#pragma once

#include <string>
#include "ofMain.h"
#include "World.h"
#include "Tag.h"
#include "Interaction.h"
#include "InteractionFactory.h"

using namespace std;

class testApp : public ofBaseApp{

    float frictionCoeff;
    World d_world;
    InteractionFactory d_interaction_factory;

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
