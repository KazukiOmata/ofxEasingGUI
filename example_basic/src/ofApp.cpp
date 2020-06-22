#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //initialize
    selector = 1;
    
    direction = 1;
    check = false;
    x2 = 800;
    y2 = 600;
    x2a = 0;
    y2a = 0;
    finish = true;
    
    
    ofBackground(255);
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
    
    
    //easing2 Gui settings x,y,w,h
    easing2.setup(100, 50, 400, 400);
    
    
    //easing3 Gui settings x,y,w,h
    easing3.setup(100, 50, 400, 400);

    //easing3 Gui settings x,y,w,h
    easing4.setup(100, 50, 400, 400);
    easing4a.setup(100, 50, 400, 400);
    easing4b.setup(100, 50, 400, 400);
    easing4c.setup(100, 50, 400, 400);
    easing4d.setup(100, 50, 400, 400);

    easing5.setup(100, 50, 400, 400);

    
}
//--------------------------------------------------------------
void ofApp::update(){
    //easing 1 an d easing2
    float time = ofGetElapsedTimef();
    rotation = 360 * easing1.applyEasing(1000, 2.0f, time);
    w = 200 * easing2.applyEasing(1000, 2.0f, time);
    h = 200 * easing2.applyEasing(1000, 2.0f, time);
    
    //easing3
    x =  ofGetWidth() * easing3.applyEasing(1000, 1.0f, ofGetElapsedTimef());
    
    //easing4
    time = ofGetElapsedTimef();
    widths[0] = 400 * easing4.applyEasing(1000, 1.0f, time,0.0f, 0.4f);
    easing4.getBezier(array);
    widths[1] = 400 * easing4a.applyEasing(array, 1000, 1.0f, time, 0.1f, 0.3f);
    widths[2] = 400 * easing4b.applyEasing(array, 1000, 1.0f, time, 0.2f, 0.2f);
    widths[3] = 400 * easing4c.applyEasing(array, 1000, 1.0f, time, 0.3f, 0.1f);
    widths[4] = 400 * easing4d.applyEasing(array, 1000, 1.0f, time, 0.4f);
    
    //easing5 (easing5 is synchronized with easing4)
    if(easing4.checkFinished() && finish){
        check = true;
        finish = false;
        ++direction;
        
        if(direction > 4){
            direction = 1;
        }
    }
    
    if(check && !finish){
        float moveX = 200;
        float moveY = 150;
        switch (direction) {
            case 1:
                y2a = moveY * easing5.applyEasing(1000, 0.5f,ofGetElapsedTimef());
                if(easing5.checkFinished()){
                    y2a = 0;
                    finish = true;
                    y2 += moveY;
                }
                break;
            case 2:
                x2a = -moveX * easing5.applyEasing(1000, 0.5f,ofGetElapsedTimef());
                if(easing5.checkFinished()){
                    x2a = 0;
                    finish = true;
                    x2 -= moveX;
                }
                break;
            case 3:
                y2a = -moveY * easing5.applyEasing(1000, 0.5f,ofGetElapsedTimef());
                if(easing5.checkFinished()){
                    y2a = 0;
                    finish = true;
                    y2 -= moveY;

                }
                break;
            case 4:
                x2a = moveX * easing5.applyEasing(1000, 0.5f,ofGetElapsedTimef());
                if(easing5.checkFinished()){
                    x2a = 0;
                    finish = true;
                    x2 += moveX;

                }
                break;
            default:
                break;
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    //easing1 and easing2
    ofPushMatrix();
    ofTranslate(300 , 300 );
    ofRotateDeg(rotation);
    
    ofSetHexColor(0xFE8484);
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofDrawRectangle(0, 0, w, h);
    
    ofPopMatrix();
    
    //easing3
    ofSetHexColor(0xFFE7D3
                  );
    ofDrawRectangle(x, 450, 30, 30);
    
   
    //easing4
    ofSetHexColor(0xFE8484);
    ofDrawRectangle(800, 300, widths[0], 40);
    ofSetHexColor(0xFED684);
    ofDrawRectangle(800, 300, widths[1], 40);
    ofSetHexColor(0x6275AB);
    ofDrawRectangle(800, 300, widths[2], 40);
    ofSetHexColor(0x69CB69);
    ofDrawRectangle(800, 300, widths[3], 40);
    ofSetHexColor(0x257A7A);
    ofDrawRectangle(800, 300, widths[4], 40);

    //easing5
    ofSetHexColor(0xC8BFE1);
    ofDrawRectangle(x2 + x2a, y2 + y2a, 50, 50);

    //fps
    ofSetColor(0);
    ofDrawBitmapString("fps : " + ofToString(ofGetFrameRate()), 30, 50);
}

//--------------------------------------------------------------

void ofApp::drawGui(ofEventArgs &args){
    
    
    //draw Adjustment GUI panel
    switch (selector) {
        case 1:
            //rectangle rotation
            easing1.adjustEasing(1000, 2.0f, ofGetElapsedTimef());
            ofSetColor(240, 50, 200,220);
            ofDrawBitmapString("rotation", ofGetWidth()/2 -32 , 25);
            break;
            
        case 2:
            //rectangle width and height
            easing2.adjustEasing(1000, 2.0f, ofGetElapsedTimef());
            ofSetColor(240, 50, 200,220);
            ofDrawBitmapString("size", ofGetWidth()/2 -20, 25);

            break;
            
        case 3:
            //rectangle width and height
            easing3.adjustEasing(1000, 1.0f, ofGetElapsedTimef());
            ofSetColor(240, 50, 200,220);
            ofDrawBitmapString("xPos", ofGetWidth()/2 -20, 25);

            break;
            
        case 4:
            //rectangle width and height
            easing4.adjustEasing(1000, 1.0f, ofGetElapsedTimef());
            ofSetColor(240, 50, 200,220);
            ofDrawBitmapString("width", ofGetWidth()/2 -21, 25);
            
            break;
            
        case 5:
            //rectangle width and height
            easing5.adjustEasing(1000, 0.5f, ofGetElapsedTimef());
            ofSetColor(240, 50, 200,220);
            ofDrawBitmapString("cycle", ofGetWidth()/2 -21, 25);
            
            break;
            
        default:
            break;
    }
    
    
    
    //description
    ofSetColor(0);
    ofDrawBitmapString("selector is changed by arrow key", 30, ofGetHeight() - 10);
    ofDrawBitmapString("selector : " + ofToString(selector), 30, ofGetHeight() - 25);
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
    
    int selectorNum = 5;
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
                
            case 3:
                easing3.clear();
                break;
            case 4:
                easing4.clear();
                break;
            case 5:
                easing5.clear();
                break;
                
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

                }
                else{
                    easing2.disablePreview();
                    cout << "disanable Preview" << endl;
                }
                break;
                
            case 3:
                if(!(easing3.getPreview())){
                    easing3.enablePreview();
                    cout << "disanable Preview" << endl;
                    
                }
                else{
                    easing3.disablePreview();
                    cout << "disanable Preview" << endl;
                }
                break;
                
            case 4:
                if(!(easing4.getPreview())){
                    easing4.enablePreview();
                    cout << "disanable Preview" << endl;
                    
                }
                else{
                    easing4.disablePreview();
                    cout << "disanable Preview" << endl;
                }
                break;
            case 5:
                if(!(easing5.getPreview())){
                    easing5.enablePreview();
                    cout << "disanable Preview" << endl;
                    
                }
                else{
                    easing5.disablePreview();
                    cout << "disanable Preview" << endl;
                }
                break;
                
                
            default:
                break;
        }
        
        
    }
    else if(key == 'j'){
        //json file
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
                
            case 3:
                if(easing3.getAnimationLoop()){
                    easing3.disableAnimationLoop();
                    cout << "disanable Preview" << endl;
                    
                }
                else{
                    easing3.enableAnimationLoop();
                    cout << "enable Animation Loop" << endl;
                    
                }
                break;
            case 4:
                if(easing4.getAnimationLoop()){
                    easing4.disableAnimationLoop();
                    cout << "disanable Preview" << endl;
                    
                }
                else{
                    easing4.enableAnimationLoop();
                    cout << "enable Animation Loop" << endl;
                    
                }
                break;
                
            case 5:
                if(easing5.getAnimationLoop()){
                    easing5.disableAnimationLoop();
                    cout << "disanable Preview" << endl;
                    
                }
                else{
                    easing5.enableAnimationLoop();
                    cout << "enable Animation Loop" << endl;
                    
                }
                break;
                
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
            
        case 3:
            easing3.mouseDraggedBezier(e);
            break;
        case 4:
            easing4.mouseDraggedBezier(e);
            break;
            
        case 5:
            easing5.mouseDraggedBezier(e);
            break;
            
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
                
            case 3:
                easing3.mousePressedRightBezier(e);
                break;
                
            case 4:
                easing4.mousePressedRightBezier(e);
                break;
                
            case 5:
                easing5.mousePressedRightBezier(e);
                break;
                
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
                
            case 3:
                easing3.mousePressedBezier(e);
                break;
            case 4:
                easing4.mousePressedBezier(e);
                break;
                
            case 5:
                easing5.mousePressedBezier(e);
                break;
                
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
            
        case 3:
            easing3.mouseReleasedBezier();
            break;
            
        case 4:
            easing4.mouseReleasedBezier();
            break;
            
        case 5:
            easing5.mouseReleasedBezier();
            break;
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
