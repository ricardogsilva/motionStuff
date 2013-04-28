#include "Mover.h"

int Mover::d_id_counter = 0;

void Mover::init(float x, float y, float m, ofColor color, float lifespan, float energy_reserve)
{
    d_id = d_id_counter;
    d_id_counter++;
    setMass(m);
    d_max_speed = 10;
    //d_max_speed = 10 + ofRandom(20);
    d_max_steer_force = ofMap(m, 10, 60, 0.01, 0.06);
    //d_max_steer_force = 0.1;
    d_color = color;
    d_location = ofVec2f(x, y);
    d_velocity = ofVec2f(0, 0);
    d_acceleration = ofVec2f(0, 0);
    d_birth_date = ofGetFrameNum() / ofGetFrameRate();
    d_age = 0.0;
    d_lifespan = lifespan;
    d_energy_reserve = energy_reserve;
}

void Mover::addTag(Tag* t)
{
    d_tags.push_back(t);
    t->addParticleNoReciprocal(this);
}

void Mover::addTagNoReciprocal(Tag* t)
{
    d_tags.push_back(t);
}

//ofVec2f Mover::separate(vector<Mover> movers)
//{
//    int closeMovers = 0;
//    ofVec2f sumDiff = ofVec2f(0, 0);
//    for(int i = 0; i < movers.size(); i++){
//        if(d_id != movers[i].id())
//        {
//            float desiredSeparation = d_width / 2 + movers[i].width() / 2 + 10;
//            ofVec2f otherLocation = movers[i].location();
//            float distSquared = ofDistSquared(d_location.x, d_location.y, otherLocation.x, otherLocation.y);
//            if(distSquared < pow(desiredSeparation, 2)){
//                ofVec2f diff = d_location - otherLocation;
//                diff.normalize();
//                diff /= distSquared;
//                sumDiff += diff;
//                closeMovers++;
//            }
//        }
//    }
//    ofVec2f steer = ofVec2f(0, 0);
//    if(closeMovers > 0){
//        sumDiff /= closeMovers;
//        sumDiff.normalize();
//        sumDiff *= d_max_speed;
//        steer = sumDiff - d_velocity;
//        steer.limit(d_max_steer_force);
//        //steer = seek(sumDiff);
//    }
//    return steer;
//}

void Mover::drag(float frictionCoeff)
{
    float speed = d_velocity.length();
    float dragMagnitude = frictionCoeff * speed * speed;
    ofVec2f drag = ofVec2f(d_velocity.x, d_velocity.y);
    drag.normalize();
    drag *= -1 * dragMagnitude;
    applyForce(drag);
}

void Mover::arrive(ofVec2f target)
{
    ofVec2f desired = target - d_location;
    float dist = desired.length();
    desired.normalize();
    float radius = 100;
    if(dist < radius)
    {
        float magnitude = ofMap(dist, 0, radius, 0, d_max_speed);
        desired *= magnitude;
    } else
    {
        desired *= d_max_speed;
    }
    ofVec2f steer = desired - d_velocity;
    steer.limit(d_max_steer_force);
    applyForce(steer);
}

/*
 * Seek a food and, upon arrival, eat it
 */
void Mover::arriveFood(Mover * food)
{
    ofVec2f desired = food->location() - d_location;
    float dist = desired.length();
    desired.normalize();
    float radius = food->width() / 2 + d_width / 2;
    if(dist < radius)
    {
        float magnitude = ofMap(dist, 0, radius, 0, d_max_speed);
        desired *= magnitude;
        eat(food);
    } else
    {
        desired *= d_max_speed;
    }
    ofVec2f steer = desired - d_velocity;
    steer.limit(d_max_steer_force);
    applyForce(steer);
}

void Mover::seek(ofVec2f target)
{
    ofVec2f desired = target - d_location;
    desired.normalize();
    desired *= d_max_speed;
    ofVec2f steer = desired - d_velocity;
    steer.limit(d_max_steer_force);
    applyForce(steer);
}

//ofVec2f Mover::seekClosest(vector<Mover> * targets)
//{
//    Mover * closeTarget = findClosest(targets);
//    ofVec2f steerForce = seek(closeTarget->location());
//    return steerForce;
//}

//ofVec2f Mover::arriveClosest(vector<Mover> * targets)
//{
//    Mover* closeTarget = findClosest(targets);
//    ofVec2f steerForce = arrive(closeTarget->location());
//    return steerForce;
//}

/*
 * find the closest among a vector of foods, then seek it
 * and eat it upon arrival
 */
void Mover::arriveClosestFood(vector<Mover> * foods)
{
    Mover * closeFood = findClosest(foods);
    arriveFood(closeFood);
}

//ofVec2f Mover::escapeClosest(vector<Mover> * targets)
//{
//    Mover* closeTarget = findClosest(targets);
//    ofVec2f steerForce = escape(closeTarget->location());
//    return steerForce;
//}

Mover * Mover::findClosest(vector<Mover> * targets)
{
    float closest = pow(2 * max(ofGetWidth(), ofGetHeight()), 2);
    Mover * closeTarget;
    for(int i=0; i < targets->size(); i++)
    {
        ofVec2f targetLocation = (*targets)[i].location();
        float distSquared = ofDistSquared(d_location.x, d_location.y, targetLocation.x, targetLocation.y);
        if(distSquared < closest)
        {
            closest = distSquared;
            closeTarget = &(*targets)[i];
        }
    }
    return closeTarget;
}

ofVec2f Mover::escape(ofVec2f target)
{
    float dist = ofDist(d_location.x, d_location.y, target.x, target.y);
    ofVec2f steer = ofVec2f(0, 0);
    //if(dist < 50 + d_width / 2)
    //{
        ofVec2f desired = (target - d_location) * -1;
        desired.normalize();
        desired *= d_max_speed;
        steer = desired - d_velocity;
        steer.limit(d_max_steer_force);
    //}
    return steer;
}

void Mover::applyForce(ofVec2f force)
{
    ofVec2f f = force * d_mass;
    d_acceleration += f;
}

void Mover::eat(Mover * food)
{
    float eaten = 0;
    if(food->mass() >= d_eat_ratio)
    {
        float eaten = d_eat_ratio;
    } else {
        float eaten = food->mass();
    }
    food->setMass(food->mass() - eaten);
    float gainedEnergy = eaten * d_mass_to_energy_ratio;
    d_energy_reserve += gainedEnergy;
}

void Mover::consumeEnergy()
{
    d_energy_reserve -= d_energy_consumption;
    if(d_energy_reserve < (0 + 0.0001))
    {
        float neededEnergy = fabs(d_energy_reserve);
        float massToConvert = neededEnergy * d_mass_to_energy_ratio;
        setMass(d_mass - massToConvert);
        d_energy_reserve += neededEnergy;
    }
}

void Mover::wander()
{
    float speed = d_velocity.length();
    ofVec2f futureLocation = d_velocity;
    futureLocation.normalize();
    futureLocation *= 10;
    futureLocation += d_location;
    float randomRadius = d_width*2;
    float theAngle = ofRandom(0, 360);
    float randomAngle = ofDegToRad(theAngle);
    float futureRandomX = futureLocation.x + randomRadius * cos(randomAngle);
    float futureRandomY = futureLocation.y + randomRadius * sin(randomAngle);
    ofVec2f futureRandomPosition = ofVec2f(futureRandomX, futureRandomY);
    seek(futureRandomPosition);
    //ofVec2f desiredVelocity = futureRandomPosition.normalize() * speed;
    //d_velocity = desiredVelocity;
}

bool Mover::isAlive()
{
    bool alive;
    if(d_age <= d_lifespan && d_mass > 0)
    {
        alive = true;
    } else
    {
        alive = false;
    }
    return alive;
}

void Mover::setMass(float newMass)
{
    d_mass = newMass;
    d_width = d_base_width + d_mass;
    d_height = d_base_height + d_mass;
}

void Mover::setColor(ofColor newColor)
{
    d_color = newColor;
}

void Mover::checkEdges()
{
    float w = ofGetWidth();
    float h = ofGetHeight();
    float max_w = w - d_width / 2;
    float min_w = d_width / 2;
    float max_h = h - d_height / 2;
    float min_h = d_height / 2;
    if(d_location.x > max_w)
    {
        d_location.x = max_w;
        d_velocity.x *= -1;
    } else if(d_location.x < min_w)
    {
        d_location.x = min_w;
        d_velocity.x *= -1;
    }
    if(d_location.y > max_h)
    {
        d_location.y = max_h;
        d_velocity.y *= -1;
    } else if(d_location.y < min_h)
    {
        d_location.y = min_h;
        d_velocity.y *= -1;
    }
}

void Mover::reappear()
{
    if(d_location.x - d_width / 2 > ofGetWidth())
    {
        d_location.x = -d_width / 2;
    } else if(d_location.x + d_width / 2 < 0)
    {
        d_location.x = ofGetWidth() + d_width / 2;
    }
    if(d_location.y - d_height / 2 > ofGetHeight())
    {
        d_location.y = -d_height / 2;
    } else if(d_location.y + d_height / 2 < 0)
    {
        d_location.y = ofGetHeight() + d_height / 2;
    }
}

void Mover::update()
{
    float elapsedSeconds = ofGetFrameNum() / ofGetFrameRate();
    d_age = elapsedSeconds - d_birth_date;
    setMass(d_mass - d_mass_decay_ratio);
    if(isAlive())
    {
        //if(d_energy_reserve >= 10)
        //{
        //    wander();
        //} else {
        //    seek(ofVec2f(0, 0));
        //}
        consumeEnergy();
        updateInteractions();
        updateMovement();
        reappear();
    }

}

void Mover::updateInteractions()
{
    cout << "Mover: " << d_id << "\n";
    for(auto it_t=d_tags.begin(); it_t!=d_tags.end(); it_t++)
    {
        Tag* t = (*it_t);
        cout << "\ttag: " << t->name() << "\n";
        unordered_map<Tag*, vector<Interaction*>>* otherInteractions = t->interactions();
        for(auto it_oi=(*otherInteractions).begin(); it_oi!=(*otherInteractions).end(); it_oi++)
        {
            Tag* otherTag = it_oi->first;
            cout << "\totherTag: " << otherTag->name() << "\n";
            vector<Interaction*> interactions = it_oi->second;
            for(auto it_i=interactions.begin(); it_i!=interactions.end(); it_i++)
            {
                Interaction* the_interaction = (*it_i);
                vector<Mover*>* otherParticles = otherTag->particles();
                for(auto it_p=(*otherParticles).begin(); it_p!=(*otherParticles).end(); it_p++)
                {
                    Mover* acted = (*it_p);
                    the_interaction->interact(this, acted);
                }
            }
        }
    }
}

void Mover::updateMovement()
{
    d_rotation_angle = atan2(d_velocity.y, d_velocity.x);
    d_velocity += d_acceleration;
    d_location += d_velocity;
    d_acceleration *= 0;
}

void Mover::draw()
{
    ofEnableAlphaBlending();
    ofSetColor(d_color);
    ofFill();
    ofPushMatrix();
    ofTranslate(ofPoint(d_location.x, d_location.y));
    ofRotate(ofRadToDeg(d_rotation_angle));
    ofEllipse(0, 0, d_width, d_height);
    ofSetColor(d_color.r, d_color.g, d_color.b, 255);
    ofNoFill();
    ofEllipse(0, 0, d_mass, d_mass);
    ofLine(0, 0, d_width/2, 0);
    ofPopMatrix();
    ofDisableAlphaBlending();
}

float const &Mover::mass() const
{
    return d_mass;
}

int const &Mover::id() const
{
    return d_id;
}

float const &Mover::width() const
{
    return d_width;
}

float const &Mover::height() const
{
    return d_height;
}

float const &Mover::age() const
{
    return d_age;
}

float const &Mover::lifespan() const
{
    return d_lifespan;
}

float const &Mover::rotation_angle() const
{
    return d_rotation_angle;
}

ofColor const &Mover::color() const
{
    return d_color;
}

ofVec2f const &Mover::velocity() const
{
    return d_velocity;
}

ofVec2f const &Mover::location() const
{
    return d_location;
}

ofVec2f const &Mover::acceleration() const
{
    return d_acceleration;
}
