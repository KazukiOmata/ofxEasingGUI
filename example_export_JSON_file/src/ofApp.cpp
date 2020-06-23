#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    selector = 1;
    
    ofBackground(255);
    ofSetCircleResolution(64);
}

//--------------------------------------------------------------
void ofApp::setupGui(){
    
    //easing1 Gui setttings x,y,w,h
    easing1.setup(100, 50, 400 ,400);
    
    //if you use some easing instance, you should call ofAddLister() once of any instance.
    ofAddListener(easing1.evKeyPressed,this,&ofApp::keyPressedGui);
    ofAddListener(easing1.evKeyReleased,this,&ofApp::keyReleasedGui);
    
    ofAddListener(easing1.evMouseDragged,this,&ofApp::mouseDraggedGui);
    ofAddListener(easing1.evMousePressed,this,&ofApp::mousePressedGui);
    ofAddListener(easing1.evMouseReleased,this,&ofApp::mouseReleaseGui);
    
    
    easing2.setup(100, 50, 400 ,400);

    
}
//--------------------------------------------------------------
void ofApp::update(){
    radius = 200 * easing1.applyEasing(1000, 1.0f, ofGetElapsedTimef());
    w = 300 * easing2.applyEasing(1000, 1.0f, ofGetElapsedTimef());
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

void ofApp::drawGui(ofEventArgs &args){
    

    switch (selector) {
        case 1:
            easing1.adjustEasing(1000, 1.0f, ofGetElapsedTimef());
            ofSetColor(240, 50, 200,220);
            ofDrawBitmapString("bezier", ofGetWidth()/2 -21, 25);
            break;
            
        case 2:
            easing2.adjustEasing(1000, 1.0f, ofGetElapsedTimef());
            ofSetColor(240, 50, 200,220);
            ofDrawBitmapString("float", ofGetWidth()/2 -21, 25);
            break;
            
        default:
            break;
    }
    
    
    //description
    ofSetHexColor(0xD68746);
    ofDrawBitmapString("Press J key : export jsonfile which included current easing data", 30, ofGetHeight() - 10);
    ofSetColor(0);
    ofDrawBitmapString("push C key : clear easing" , 30, ofGetHeight() - 40);
    ofDrawBitmapString("push L key : loop animation" , 30, ofGetHeight() - 55);
    ofDrawBitmapString("push P key : animation preview" , 30, ofGetHeight() - 70);
    ofDrawBitmapString("Left click : add bezier hundle, right click : delete bezier hundle" , 30, ofGetHeight() - 85);
    
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}
//--------------------------------------------------------------

void ofApp::keyPressedGui(int &key){
    
    int selectorNum = 2;
    //change easing graph
    if(key == OF_KEY_RIGHT){
        ++selector;
        
        if(selector > selectorNum){
            selector = 1;
        }
    }
    else if(key == OF_KEY_LEFT){
        --selector;
        
        if (selector < 1) {
            selector = selectorNum;
        }
    }
    
    //clear eazing bezier
    if(key == 'c'){
        switch (selector) {
            case 1:
                easing1.clear();

                break;
                
            case 2:
                easing2.clear();
                break;
//
//            case 3:
//                easing3.clear();
//                break;
//            case 4:
//                easing4.clear();
//                break;
//            case 5:
//                easing5.clear();
//                break;
                
            default:
                break;
        }
        
    }
    // preview
    if(key == 'p'){
        switch (selector) {
            case 1:
                if(!(easing1.getPreview())){
                    easing1.enablePreview();
                    cout << "disanable Preview" << endl;
                }
                else{
                    easing1.disablePreview();
                    cout << "disanable Preview" << endl;

                }
                break;
                
            case 2:
                if(!(easing2.getPreview())){
                    easing2.enablePreview();
                    cout << "disanable Preview" << endl;
//
                }
                else{
                    easing2.disablePreview();
                    cout << "disanable Preview" << endl;
                }
                break;

//            case 3:
//                if(!(easing3.getPreview())){
//                    easing3.enablePreview();
//                    cout << "disanable Preview" << endl;
//
//                }
//                else{
//                    easing3.disablePreview();
//                    cout << "disanable Preview" << endl;
//                }
//                break;
//
//            case 4:
//                if(!(easing4.getPreview())){
//                    easing4.enablePreview();
//                    cout << "disanable Preview" << endl;
//
//                }
//                else{
//                    easing4.disablePreview();
//                    cout << "disanable Preview" << endl;
//                }
//                break;
//            case 5:
//                if(!(easing5.getPreview())){
//                    easing5.enablePreview();
//                    cout << "disanable Preview" << endl;
//
//                }
//                else{
//                    easing5.disablePreview();
//                    cout << "disanable Preview" << endl;
//                }
//                break;
                
                
            default:
                break;
        }
        
        
    }
    else if(key == 'j'){
        //json file
        switch (selector) {
            case 1:
                easing1.exportJsonEasingBezier("bezier");
                cout << "json file created (bezier data)" << endl;
                break;
                
            case 2:
                easing2.exportJsonEasingFloat("float");
                cout << "json file created (float data)" << endl;

                break;
                
            default:
                break;
        }
        
        
        
    }
    // loop settings
    else if(key == 'l'){
        
        switch (selector) {
            case 1:
                if(easing1.getAnimationLoop()){
                    easing1.disableAnimationLoop();
                    cout << "disanable Preview" << endl;

                }
                else{
                    easing1.enableAnimationLoop();
                    cout << "enable Animation Loop" << endl;

                }
                break;
                
            case 2:
                if(easing2.getAnimationLoop()){
                    easing2.disableAnimationLoop();
                    cout << "disanable Preview" << endl;

                }
                else{
                    easing2.enableAnimationLoop();
                    cout << "enable Animation Loop" << endl;

                }
                break;
//
//            case 3:
//                if(easing3.getAnimationLoop()){
//                    easing3.disableAnimationLoop();
//                    cout << "disanable Preview" << endl;
//
//                }
//                else{
//                    easing3.enableAnimationLoop();
//                    cout << "enable Animation Loop" << endl;
//
//                }
//                break;
//            case 4:
//                if(easing4.getAnimationLoop()){
//                    easing4.disableAnimationLoop();
//                    cout << "disanable Preview" << endl;
//
//                }
//                else{
//                    easing4.enableAnimationLoop();
//                    cout << "enable Animation Loop" << endl;
//
//                }
//                break;
//
//            case 5:
//                if(easing5.getAnimationLoop()){
//                    easing5.disableAnimationLoop();
//                    cout << "disanable Preview" << endl;
//
//                }
//                else{
//                    easing5.enableAnimationLoop();
//                    cout << "enable Animation Loop" << endl;
//
//                }
//                break;
                
            default:
                break;
        }
        
        
    }
}
//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}
//--------------------------------------------------------------


void ofApp::keyReleasedGui(int &key){
    
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

void ofApp::mouseDraggedGui(ofVec2f &e){
    switch (selector) {
        case 1:
            easing1.mouseDraggedBezier(e);
            
            break;
            
        case 2:
            easing2.mouseDraggedBezier(e);
            break;
//
//        case 3:
//            easing3.mouseDraggedBezier(e);
//            break;
//        case 4:
//            easing4.mouseDraggedBezier(e);
//            break;
//
//        case 5:
//            easing5.mouseDraggedBezier(e);
//            break;
            
        default:
            break;
    }

}

//--------------------------------------------------------------

void ofApp::mousePressedGui(ofVec2f &e){
    
    if(ofGetMousePressed(1)){    // center click

        
    }
    else if(ofGetMousePressed(2)){    //right click
        switch (selector) {
            case 1:
                easing1.mousePressedRightBezier(e);
                break;
                
            case 2:
                easing2.mousePressedRightBezier(e);
                break;
//
//            case 3:
//                easing3.mousePressedRightBezier(e);
//                break;
//
//            case 4:
//                easing4.mousePressedRightBezier(e);
//                break;
//
//            case 5:
//                easing5.mousePressedRightBezier(e);
//                break;
                
            default:
                break;
        }
        
    }
    else{    //left click
        switch (selector) {
            case 1:
                easing1.mousePressedBezier(e);
                break;
                
            case 2:
                easing2.mousePressedBezier(e);
                break;
//
//            case 3:
//                easing3.mousePressedBezier(e);
//                break;
//            case 4:
//                easing4.mousePressedBezier(e);
//                break;
//
//            case 5:
//                easing5.mousePressedBezier(e);
//                break;
                
            default:
                break;
        }

    }

}


//--------------------------------------------------------------

void ofApp::mouseReleaseGui(ofVec2f &e){
    switch (selector) {
        case 1:
            easing1.mouseReleasedBezier();
            break;
            
        case 2:
            easing2.mouseReleasedBezier();
            break;

//        case 3:
//            easing3.mouseReleasedBezier();
//            break;
//
//        case 4:
//            easing4.mouseReleasedBezier();
//            break;
//
//        case 5:
//            easing5.mouseReleasedBezier();
//            break;
            
        default:
            break;
    }

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
