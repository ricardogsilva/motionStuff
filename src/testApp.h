#pragma once

#include <vector>
#include "ofMain.h"
#include "World.h"
using namespace std;

class testApp : public ofBaseApp{

    float frictionCoeff;
    World d_world;
    //Mover m;
    //Mover s;
    //MoverSystem reds;
    //MoverSystem blacks;

	//vector<Mover> d_movers;
	//vector<Mover> d_attractors;
    //int d_i;
	//bool enableDownForce;
	//bool enableUpForce;
	//bool enableLeftForce;
	//bool enableRightForce;
	//bool enableSeek;
	//bool enableEscape;

	//float const friction_coefficient const
	//ofVec2f friction;

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
};
