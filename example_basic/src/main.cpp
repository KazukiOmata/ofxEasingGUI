#include "ofMain.h"
#include "ofApp.h"
#include "ofAppGLFWWindow.h"

//========================================================================
int main( ){
    //    ofSetupOpenGL(1024,768,OF_WINDOW);            // <-------- setup the GL context
    
    // this kicks off the running of my app
    // can be OF_WINDOW or OF_FULLSCREEN
    // pass in width and height too:
    
    
    
    ofGLFWWindowSettings settings;
    
    //main window メインウィンドウ
    settings.setSize(1024, 768);
    settings.setPosition(ofVec2f(600,0));
    settings.resizable = true;
    shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);
    
    //sub window サブウィンドウ
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
    
    
    
    
    
    //    ofRunApp(new ofApp());
    
    
    
}
