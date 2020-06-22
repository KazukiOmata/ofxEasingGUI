#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    selector = 1;
    
    
    
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
    
    
    

    
}
//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
   
}

//--------------------------------------------------------------

void ofApp::drawGui(ofEventArgs &args){
    


    
    
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
                
//            case 2:
//                easing2.clear();
//                break;
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
                
//            case 2:
//                if(!(easing2.getPreview())){
//                    easing2.enablePreview();
//                    cout << "disanable Preview" << endl;
//
//                }
//                else{
//                    easing2.disablePreview();
//                    cout << "disanable Preview" << endl;
//                }
//                break;
//
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
                
//            case 2:
//                if(easing2.getAnimationLoop()){
//                    easing2.disableAnimationLoop();
//                    cout << "disanable Preview" << endl;
//
//                }
//                else{
//                    easing2.enableAnimationLoop();
//                    cout << "enable Animation Loop" << endl;
//
//                }
//                break;
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
            
//        case 2:
//            easing2.mouseDraggedBezier(e);
//            break;
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
                
//            case 2:
//                easing2.mousePressedRightBezier(e);
//                break;
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
                
//            case 2:
//                easing2.mousePressedBezier(e);
//                break;
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
            
//        case 2:
//            easing2.mouseReleasedBezier();
//            break;
//
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
