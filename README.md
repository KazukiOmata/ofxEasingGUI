# ofxEasingGUI

## Description
this is oepnFrame works addon which You can use easing animation with GUI Panel.

## Features
we can adjust easing easily GUI panel and save it info of easing(json file),apply easing animation for any yor object.

## Getting Started
> main.cpp

    #include "ofMain.h"
    #include "ofApp.h"
    #include "ofAppGLFWWindow.h"
    
    int main(){
      ofGLFWWindowSettings settings;

      //mainWindow
      settings.setSize(1024, 768);
      settings.setPosition(ofVec2f(600,0));
      settings.resizable = true;
      shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);

      //subWindow 1
      //if you want more window/panel, You can add window/panel like the following sentence
      settings.setSize(600, 600);
      settings.setPosition(ofVec2f(0,0));
      settings.resizable = false;
      shared_ptr<ofAppBaseWindow> guiWindow = ofCreateWindow(settings);
      guiWindow->setVerticalSync(false);

      shared_ptr<ofApp> mainApp(new ofApp);
      mainApp->setupGui();
      ofAddListener(guiWindow->events().draw,mainApp.get(),&ofApp::drawGui);


      ofRunApp(mainWindow, mainApp);
      ofRunMainLoop();
    }

> ofApp.h

    #include "ofMain.h"
    #include "ofxEasingGUI.hpp"
    #include "ofEvent.h"
    
    class ofApp : public ofBaseApp{
      public:
      void setup();
      void update();
      void draw();
      
              ~~~~~~~~~
              ~~~~~~~~~
              
      void dragEvent(ofDragInfo dragInfo);
      void gotMessage(ofMessage msg);
      
      void setupGui();
      void drawGui(ofEventArgs & args);

      void keyPressedGui(int &key);
      void keyReleasedGui(int &key);
      void mouseDraggedGui(ofVec2f &e);
      void mousePressedGui(ofVec2f &e);
      void mouseReleaseGui(ofVec2f &e);
      
      ofxEasingGUi easing;
    };

> ofApp.cpp

    #include "ofApp.h"
    
    void ofApp::setup(){
        ~~~~~~~~~
    }
    
    void ofApp::setupGui(){
        easing.setup(100, 100, 400, 400);

        ofAddListener(easing.evKeyPressed,this,&ofApp::keyPressedGui);
        ofAddListener(easing.evKeyReleased,this,&ofApp::keyReleasedGui);

        ofAddListener(easing.evMouseDragged,this,&ofApp::mouseDraggedGui);
        ofAddListener(easing.evMousePressed,this,&ofApp::mousePressedGui);
        ofAddListener(easing.evMouseReleased,this,&ofApp::mouseReleaseGui);
    }
    
    ~~~~~~~~~
    ~~~~~~~~~
    ~~~~~~~~~
    
    void ofApp::drawGui(ofEventArgs &args){
    
        easing.adjustEasing(1000, 2.0f, ofGetElapsedTimef());
    }
    
    void ofApp::keyPressedGui(int &key){

        if(key == 'c'){
            easing.clear();
        }
        if(key == 'p'){
            if(!(easing.getPreview())){
                easing.enablePreview();
            }
            else{
                easing2.disablePreview();
            }
        }
        else if(key == 'j'){
            easing.printJsonEasingBezier("test1");
            //        easing.printJsonEasingBezierTime("test2");
            //        easing.printJsonEasingFloat("test3");
            //        easing.printJsonEasingFloatTime("test4");
        }
    }
    
    void ofApp::mouseDraggedGui(ofVec2f &e){
        easing.mouseDraggedBezier(e);

    }
    void ofApp::mousePressedGui(ofVec2f &e){
        easing.mousePressedBezier(e);
    }
    void ofApp::mouseReleaseGui(ofVec2f &e){
        easing.mouseReleasedBezier();
    }

  
## Documentation
Japanese(日本語) Document is [here](https://kazukiomata.github.io/ofxEasingGUI.github.io/)

English Document is [here](https://kazukiomata.github.io/ofxEasingGUI.github.io/)

## Installation
Download or use git to clone this folder into the openFrameworks/addons/ folder.

and then, Rename and Remove versionName of this folder.

ex:
ofxEasingGui-v01m00 => ofxEasingGUI

## Dependencies
To read JSON file

[ofxJSON](https://github.com/jeffcrouse/ofxJSON)


## Versioning
latest version is v01m01

Easing calculation is corrected.

previous version
v01m00 // test Uploading

it is developed of_v0.10.1_osx_release macOS 10.14.6


## Licensing
See [LICENSE](LICENSE).



