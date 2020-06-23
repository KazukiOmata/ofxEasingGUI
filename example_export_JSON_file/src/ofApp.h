#pragma once

#include "ofMain.h"
#include "ofxEasingGUI.hpp"
#include "ofEvent.h"


class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    //easing instances
    ofxEasingGUI easing1;
    ofxEasingGUI easing2;

    
    
    //sub window methods
    void setupGui();
    void drawGui(ofEventArgs & args);
    
    void keyPressedGui(int &key);
    void keyReleasedGui(int &key);
    void mouseDraggedGui(ofVec2f &e);
    void mousePressedGui(ofVec2f &e);
    void mouseReleaseGui(ofVec2f &e);

		
    int selector;
    
    float radius;
    float w;
};
