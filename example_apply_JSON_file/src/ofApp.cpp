#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    ofSetCircleResolution(64);
    
    easing1.setup();
    easing2.setup();
}

//--------------------------------------------------------------
void ofApp::update(){
    radius = 200 * easing1.applyEasingJsonBezier("bezier.json", 1000, 1.0f, ofGetElapsedTimef());
    w = 300 * easing2.applyEasingJsonFloat("float.json", 1.0f, ofGetElapsedTimef());
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetHexColor(0xD6BF46);
    ofDrawCircle(ofGetWidth()/2 - 200, ofGetHeight()/2, radius);
    
    ofSetHexColor(0xD68746);
    ofDrawRectangle(ofGetWidth()/2 + 200, 100, w, ofGetHeight()-200);
    
    //fps
    ofSetColor(0);
    ofDrawBitmapString("fps : " + ofToString(ofGetFrameRate()), 30, 50);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == '1'){
        if(easing1.getAnimationLoop()){
            easing1.disableAnimationLoop();
        }
        else{
            easing1.enableAnimationLoop();
        }
    }
    
    if(key == '2'){
        if(easing2.getAnimationLoop()){
            easing2.disableAnimationLoop();
        }
        else{
            easing2.enableAnimationLoop();
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
