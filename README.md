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
      
      ~~~~~~~~~
      ~~~~~~~~~
      
      void setupGui();
      void drawGui(ofEventArgs & args);

      void keyPressedGui(int &key);
      void keyReleasedGui(int &key);
      void mouseDraggedGui(ofVec2f &e);
      void mousePressedGui(ofVec2f &e);
      void mouseReleaseGui(ofVec2f &e);
      
      ofxEasingGUi easing;
    };

  
  


  
## Documentation

## Installation
Download or use git to clone this folder into the openFrameworks/addons/ folder.

and then, Rename and Remove versionName of this folder.

ex:
ofxEasingGui-v01m00 => ofxEasingGUI

## Dependencies
To read JSON file

[ofxJSON](https://github.com/jeffcrouse/ofxJSON)


## Versioning
This project uses Semantic Versioning, although strict adherence will only come into effect at version 1.0.0.

## Licensing
See [LICENSE](LICENSE).



