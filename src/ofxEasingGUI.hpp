//
//  ofxEasingGUI.hpp
//  ofxEasingGUI01
//
//  Created by 小俣一希 on 2020/06/16.
//

#ifndef ofxEasingGUI_hpp
#define ofxEasingGUI_hpp

#include <stdio.h>
#include "ofMain.h"
#include "ofxJSON.h"

//easingごとに、インスタンスを作成してください。




class ofxEasingGUI {
    
private:
//    vector <ofVec2f> bezier;
    ofVec2f bezier[4];
    //[0] = 左下
    //[1] = 右上
    //[2] = ハンドル1
    //[3] = ハンドル2
    
    float graphX;
    float graphY;

    float graphWidth;
    float graphHeight;
    
    ofColor red = ofColor(255,70,60,220);
    ofColor orange = ofColor(254, 95, 0, 220);
    ofColor skin = ofColor(242,210,209,235);
    ofColor purple = ofColor(240, 50, 200,220);
    ofColor yellow = ofColor(230, 230, 40,220);
    ofColor lightBlue = ofColor(20, 230, 200,220);
    
    bool bCurve1 = false;
    bool bCurve2 = false;
    bool bTouch1 = false;
    bool bTouch2 = false;
    
    bool bPreview = false;
    
    bool bCalcMode = false;
    
    float time;
    bool bTime = false;
    //デバックlog用のベクター
    vector<float> easingArray;
    //[0] = 左下
    //[1] = 右上
    //[2] = ハンドル1
    //[3] = ハンドル2
    
    bool statusLog;
    
    ofFile myTextFile;
    string jsonFileName;
    
    bool bJsonFloat = false;
    bool bJsonFloatTime = false;
    
    ofxJSONElement json;

public:
    void setup();
    void setup(float initWidth, float initHeight);
//    void setup(float initPosX, float initPosY);
    void setup(float initPosX, float initPosY, float initWidth, float initHeight);
protected:
    void draw();
    void drawBeizerPoint();
public:
    //preview
    void enablePreview();
    void disablePreview();
    
    void mouseDraggedBezier(float mouseX, float mouseY);
    void mouseDraggedBezier(ofVec2f mouse);
    void mousePressedBezier(float mouseX, float mouseY);
    void mousePressedBezier(ofVec2f mouse);
    void mouseReleasedBezier();

    
    void getBezier(ofVec2f (&bezierArray)[4]);
    void getBezierBasePoint(ofVec2f (&bezierBasePointArray)[2]);
    void getBezierHandle(ofVec2f (&bezierHandleArray)[2]);
    bool getPreview();
protected:
    ofVec2f calcBezierCurveProcess(ofVec2f bezierArray[], int bezierNum, float parameter);
    uintmax_t combination(unsigned int n, unsigned int r);
public:
    ofVec2f calcBezierCurveCoord(ofVec2f bezierArray[], int bezierNum, float parameter);
    float calcBezierCurveXCoord(ofVec2f bezierArray[], int bezierNum, float parameter);
    float calcBezierCurveYCoord(ofVec2f bezierArray[], int bezierNum, float parameter);
    
    ofVec2f calc3BezierCurveCoord(ofVec2f bezierArray[], float parameter);
    float calc3BezierCurveXCoord(ofVec2f bezierArray[], float parameter);
    float calc3BezierCurveYCoord(ofVec2f bezierArray[], float parameter);
    
    ofVec2f calc4BezierCurveCoord(ofVec2f bezierArray[], float parameter);
    float calc4BezierCurveXCoord(ofVec2f bezierArray[], float parameter);
    float calc4BezierCurveYCoord(ofVec2f bezierArray[], float parameter);
    
protected:
    void enableBezierCalcNumMode();
    void disableBezierCalcNumMode();
public:
    
    void adjustEasing(int precision, float setTime,float currentTime);
    void adjustEasing(ofVec2f (&bezierArray)[4], float setTime,float currentTime);
    void adjustEasing(ofVec2f (&bezierArray)[4] , int precision, float setTime,float currentTime);
    
    float applyEasing(float setTime, float currentTime);
    float applyEasing(ofVec2f (&bezierArray)[4], float setTime, float currentTime);
    
    float applyEasingJsonBezier(string filePath, float setTime, float currentTime);
    float applyEasingJsonFloat(string filePath, float setTime, float currentTime);

    //bezier array and graph clear
    void clear();
    
    //log / debug
    void enableEasingLog();
    void disableEasingLog();
    
    
    
    //JSON
    void printJsonEasingBezier(string fileName);
    void printJsonEasingBezierTime(string fileName);

    void printJsonEasingFloat(string fileName);
    void printJsonEasingFloatTime(string fileName);
    
protected:
    void printJsonEasingFloatProcess(vector<float> normalizedValues);
    void printJsonEasingFloatTimePrcess(vector<float> normalizedValues);
    
public:
    
    //events
    ofEvent<int> evKeyPressed;
    ofEvent<int > evKeyReleased;
    ofEvent<ofVec2f> evMouseDragged;
    ofEvent<ofVec2f> evMousePressed;
    ofEvent<ofVec2f> evMouseReleased;

    //constructor
    ofxEasingGUI();
    //deconstructor
    ~ofxEasingGUI();
    
    
    void eventRegister();

    void eventClear();

    void keyPressed(ofKeyEventArgs &args);
    void keyReleased(ofKeyEventArgs &args);
    
    void mouseMoved(ofMouseEventArgs &args);
    void mouseDragged(ofMouseEventArgs &args);
    void mousePressed(ofMouseEventArgs &args);
    void mouseReleased(ofMouseEventArgs &args);
    void mouseScrolled(ofMouseEventArgs &args);
    void mouseEntered(ofMouseEventArgs &args);
    void mouseExited(ofMouseEventArgs &args);
    
protected:
    //event
    bool bRegisterdEvents;
    
    
};





#endif /* ofxEasingGUI */
