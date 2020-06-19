//
//  ofxEasingGUI.cpp
//  ofxEasingGUI01
//
//  Created by 小俣一希 on 2020/06/16.
//

#include "ofxEasingGUI.hpp"

//--------------------------------------------------------------

//ウィンドウスクリーンの全体を使ったグラフで考える
void ofxEasingGUI::setup(){
    graphX = 0;
    graphY = 0;
    graphWidth = ofGetWidth();
    graphHeight = ofGetHeight();
    
    bezier[0] = (ofVec2f(graphX, graphHeight + graphY));//左下
    bezier[1] = (ofVec2f(graphWidth + graphX, graphY));//右上
    bezier[2] = ofVec2f(0.0f, 0.0f);
    bezier[3] = ofVec2f(0.0f, 0.0f);
    
    statusLog = false;
    
    
    eventRegister();
    
    
    
}
//--------------------------------------------------------------

//任意のサイズのグラフで考える
void ofxEasingGUI::setup(float initWidth, float initHeight){
    graphX = 0;
    graphY = 0;
    graphWidth = initWidth;
    graphHeight = initHeight;
    
    bezier[0] = (ofVec2f(graphX, graphHeight + graphY));//左下
    bezier[1] = (ofVec2f(graphWidth + graphX, graphY));//右上
    bezier[2] = ofVec2f(0.0f, 0.0f);
    bezier[3] = ofVec2f(0.0f, 0.0f);
    
    statusLog = false;
    
    eventRegister();


}
//--------------------------------------------------------------


//任意のポジションからのグラフで考える
void ofxEasingGUI::setup(float initPosX, float initPosY, float initWidth, float initHeight){
    graphX = initPosX;
    graphY = initPosY;
    graphWidth = initWidth;
    graphHeight = initHeight;
    
    bezier[0] = (ofVec2f(graphX, graphHeight + graphY));//左下
    bezier[1] = (ofVec2f(graphWidth + graphX, graphY));//右上
    bezier[2] = ofVec2f(0.0f, 0.0f);
    bezier[3] = ofVec2f(0.0f, 0.0f);
    
    statusLog = false;
    
    eventRegister();


}
//--------------------------------------------------------------

void ofxEasingGUI::draw(){
//    ofSetBackgroundAuto(false);
    ofBackground(240);
    ofNoFill();
    ofSetColor(40, 140);
    ofSetLineWidth(2.0);
    ofDrawRectangle(graphX, graphY, graphWidth, graphHeight);
    ofFill();
    ofSetLineWidth(2.0);
    ofSetColor(20,230);
    
    ofDrawCircle(bezier[0], 4);//左下
    ofDrawCircle(bezier[1], 4);//右上
    
    ofSetColor(40, 40);
    ofSetLineWidth(2.0);
    ofDrawLine(bezier[0].x, bezier[0].y, bezier[1].x, bezier[1].y);
    
    ofSetColor(10,240);
    ofDrawBitmapString("Value", graphX - 20, graphY - 30);
    ofDrawBitmapString("Time", graphX + graphWidth + 30, graphY + graphHeight + 5);
}


//--------------------------------------------------------------


void ofxEasingGUI::drawBeizerPoint(){
    
    if(bCurve1 && !bCurve2){
        ofColor line = ofColor(orange.r, orange.g, orange.b,150);
        ofSetColor(line);
        ofDrawLine(bezier[0].x, bezier[0].y, bezier[2].x, bezier[2].y);
        ofSetColor(orange);
        ofDrawCircle(bezier[2], 4);
    }
    else if(bCurve1 && bCurve2){
        ofColor line = ofColor(orange.r, orange.g, orange.b,150);
        ofSetColor(line);
        ofDrawLine(bezier[0].x, bezier[0].y, bezier[2].x, bezier[2].y);
        ofSetColor(orange);
        ofDrawCircle(bezier[2], 4);
        line = ofColor(red.r, red.g, red.b, 150);
        ofSetColor(line);
        ofDrawLine(bezier[1].x, bezier[1].y, bezier[3].x, bezier[3].y);
        ofSetColor(red);
        ofDrawCircle(bezier[3], 4);
    }
}


//--------------------------------------------------------------


void ofxEasingGUI::enablePreview(){
    
    bPreview = true;
}
//--------------------------------------------------------------


void ofxEasingGUI::disablePreview(){
    
    bPreview = false;
}



//--------------------------------------------------------------


//マウスドラッグでグラフを動かすため。引数にはマウスのXY。
void ofxEasingGUI::mouseDraggedBezier(float mouseX, float mouseY){
    if(bCurve1 && bTouch1){
        bezier[2] = ofVec2f(mouseX - graphX, mouseY - graphY);
        
    }
    else if(bCurve2 && bTouch2){
        bezier[3] = ofVec2f(mouseX - graphX, mouseY - graphY);
        
    }
    
    if(bCurve1 && !bCurve2){

        ofSetColor(purple);
        ofDrawCircle(bezier[2], 4);//左下

    }
    else if(bCurve1 && bCurve2){
        ofSetColor(purple);
        ofDrawCircle(bezier[2], 4);//左下
        ofSetColor(yellow);
        ofDrawCircle(bezier[3], 4);//左下
    }
}

//--------------------------------------------------------------


void ofxEasingGUI::mouseDraggedBezier(ofVec2f mouse){
    if(bCurve1 && bTouch1){
        bezier[2] = ofVec2f(mouse.x, mouse.y);
        
    }
    else if(bCurve2 && bTouch2){
        bezier[3] = ofVec2f(mouse.x, mouse.y);
        
    }
    
    if(bCurve1 && !bCurve2){
        ofSetColor(purple);
        ofDrawCircle(bezier[2], 4);//左下
        
    }
    else if(bCurve1 && bCurve2){
        ofSetColor(purple);
        ofDrawCircle(bezier[2], 4);//左下
        ofSetColor(yellow);
        ofDrawCircle(bezier[3], 4);//左下
    }
}


//--------------------------------------------------------------


//マウス押した時にグラフを動かすため。引数にはマウスのXY。
void ofxEasingGUI::mousePressedBezier(float mouseX, float mouseY){
    if(!bCurve1 && !bCurve2){
        bezier[2] = (ofVec2f(mouseX - graphX, mouseY - graphY));
        bCurve1 = true;
    }
    else if(bCurve1 && !bCurve2){
        bezier[3] = (ofVec2f(mouseX - graphX, mouseY - graphY));
        bCurve2 = true;
    }
    
    if(abs(bezier[2].x - (mouseX - graphX)) <= 20 && abs(bezier[2].y - (mouseY - graphY)) <= 20 && bCurve1){
        bTouch1 = true;
    }
    else if(abs(bezier[3].x - (mouseX - graphX)) <= 20 && abs(bezier[3].y - (mouseY - graphY)) <= 20 && bCurve2){
        bTouch2 =true;
    }
    
}

//--------------------------------------------------------------


void ofxEasingGUI::mousePressedBezier(ofVec2f mouse){
    if(!bCurve1 && !bCurve2){
        bezier[2] = (ofVec2f(mouse.x, mouse.y));
        bCurve1 = true;
    }
    else if(bCurve1 && !bCurve2){
        bezier[3] = (ofVec2f(mouse.x, mouse.y));
        bCurve2 = true;
    }
    
    if(abs(bezier[2].x - (mouse.x)) <= 20 && abs(bezier[2].y - (mouse.y)) <= 20 && bCurve1){
        bTouch1 = true;
    }
    else if(abs(bezier[3].x - (mouse.x)) <= 20 && abs(bezier[3].y - (mouse.y)) <= 20 && bCurve2){
        bTouch2 =true;
    }
}


//--------------------------------------------------------------


//マウスドラッグ後、リリースした時のリセット用
void ofxEasingGUI::mouseReleasedBezier(){
    
    bTouch1 = false;
    bTouch2 = false;
}

//--------------------------------------------------------------






//ベジェ四つをofVec2f型の要素数4の配列で参照渡し
void ofxEasingGUI::getBezier(ofVec2f (&bezierArray)[4]){
    bezierArray[0] = bezier[0];
    bezierArray[1] = bezier[1];
    bezierArray[2] = bezier[2];
    bezierArray[3] = bezier[3];

    
}

//--------------------------------------------------------------


//ベジェの基点の二つをofVec2f型の要素数2の配列で参照渡し
void ofxEasingGUI::getBezierBasePoint(ofVec2f (&bezierBasePointArray)[2]){
    bezierBasePointArray[0] = bezier[0];
    bezierBasePointArray[1] = bezier[1];
    

}

//--------------------------------------------------------------


//ハンドルをofVec2f型の要素数2の配列を参照渡し。
void ofxEasingGUI::getBezierHandle(ofVec2f (&bezierHandleArray)[2]){
    bezierHandleArray[0] = bezier[2];
    bezierHandleArray[1] = bezier[3];
    
}


//--------------------------------------------------------------

bool ofxEasingGUI::getPreview(){
    return bPreview;
}

//--------------------------------------------------------------



//reference
//https://nixeneko.hatenablog.com/entry/2015/06/26/075022

ofVec2f ofxEasingGUI::calcBezierCurveProcess(ofVec2f bezierArray[], int bezierNum, float parameter){
    
    ofVec2f coordinate = ofVec2f(0.0f,0.0f);
    int n = bezierNum;
    
    for(int i = 0;i < n;i++){
        float temp = (float)combination(n, i) * pow(parameter, i) * pow((1.0f - parameter), n-i);
        coordinate += bezierArray[i] * temp;
    }
    
    return coordinate;
}

//--------------------------------------------------------------
//reference
//https://teratail.com/questions/72682
uintmax_t ofxEasingGUI::combination(unsigned int n, unsigned int r) {
    if ( r * 2 > n ) r = n - r;
    uintmax_t dividend = 1;
    uintmax_t divisor  = 1;
    for ( unsigned int i = 1; i <= r; ++i ) {
        dividend *= (n-i+1);
        divisor  *= i;
    }
    return dividend / divisor;
}

//--------------------------------------------------------------


ofVec2f ofxEasingGUI::calcBezierCurveCoord(ofVec2f bezierArray[], int bezierNum, float parameter){
    //parameter ; 0.0 ~ 1.0
    
    ofVec2f coordinate;
    
    coordinate = calcBezierCurveProcess(bezierArray,bezierNum,parameter);
    
    return coordinate;
    
    
}

//--------------------------------------------------------------

float ofxEasingGUI::calcBezierCurveXCoord(ofVec2f bezierArray[], int bezierNum, float parameter){
    ofVec2f coordinate;
    
    coordinate = calcBezierCurveProcess(bezierArray,bezierNum,parameter);
    
    return coordinate.x;
}

//--------------------------------------------------------------

float ofxEasingGUI::calcBezierCurveYCoord(ofVec2f bezierArray[], int bezierNum, float parameter){
    ofVec2f coordinate;
    
    coordinate = calcBezierCurveProcess(bezierArray,bezierNum,parameter);
    
    return coordinate.y;
}

//--------------------------------------------------------------


ofVec2f ofxEasingGUI::calc3BezierCurveCoord(ofVec2f bezierArray[], float parameter){
    ofVec2f coordinate;
    
    coordinate = bezierArray[0] * pow((1.0f - parameter),2) + bezierArray[2] * 2.0f * parameter * (1.0f - parameter) + bezierArray[1] * pow(parameter,2);
    
    return coordinate;

}

//--------------------------------------------------------------

float ofxEasingGUI::calc3BezierCurveXCoord(ofVec2f bezierArray[], float parameter){
    ofVec2f coordinate;
    
    coordinate = bezierArray[0] * pow((1.0f - parameter),2) + bezierArray[2] * 2.0f * parameter * (1.0f - parameter) + bezierArray[1] * pow(parameter,2);
    
    return coordinate.x;
}

//--------------------------------------------------------------

float ofxEasingGUI::calc3BezierCurveYCoord(ofVec2f bezierArray[], float parameter){
    ofVec2f coordinate;
    
    coordinate = bezierArray[0] * pow((1.0f - parameter),2) + bezierArray[2] * 2.0f * parameter * (1.0f - parameter) + bezierArray[1] * pow(parameter,2);
    
    return coordinate.y;
}

//--------------------------------------------------------------


ofVec2f ofxEasingGUI::calc4BezierCurveCoord(ofVec2f bezierArray[], float parameter){
    ofVec2f coordinate;
    
    coordinate = bezierArray[0] * pow((1.0f - parameter),3) + bezierArray[2] * 3.0f * parameter * pow((1.0f - parameter),2) + bezierArray[3] * 3.0f * pow(parameter,2) * (1.0f - parameter) + bezierArray[1] * pow(parameter,3);
    
    return coordinate;

}

//--------------------------------------------------------------

float ofxEasingGUI::calc4BezierCurveXCoord(ofVec2f bezierArray[], float parameter){
    ofVec2f coordinate;
    
    coordinate = bezierArray[0] * pow((1.0f - parameter),3) + bezierArray[2] * 3.0f * parameter * pow((1.0f - parameter),2) + bezierArray[3] * 3.0f * pow(parameter,2) * (1.0f - parameter) + bezierArray[1] * pow(parameter,3);
    
    return coordinate.x;
}

//--------------------------------------------------------------

float ofxEasingGUI::calc4BezierCurveYCoord(ofVec2f bezierArray[], float parameter){
    ofVec2f coordinate;
    
    coordinate = bezierArray[0] * pow((1.0f - parameter),3) + bezierArray[2] * 3.0f * parameter * pow((1.0f - parameter),2) + bezierArray[3] * 3.0f * pow(parameter,2) * (1.0f - parameter) + bezierArray[1] * pow(parameter,3);
    
    return coordinate.y;
}

//--------------------------------------------------------------


void ofxEasingGUI::enableBezierCalcNumMode(){
    bCalcMode = true;
}

void ofxEasingGUI::disableBezierCalcNumMode(){
    bCalcMode = false;

}


//--------------------------------------------------------------


//precision = 精度, setTime = 何秒間, curentTime = 現在の時間
void ofxEasingGUI::adjustEasing(int precision, float setTime,float currentTime){
    
    draw();
    //初期時間
    if(!bTime){
        time = currentTime;
        bTime = true;
    }
    

    //初期値のままだとdrawしない
    if( (bezier[2].x != 0.0f && bezier[2].y !=  0.0f) || (bezier[3].x != 0.0f && bezier[3].y != 0.0f) ){
        

        
        drawBeizerPoint();
        
        ofVec2f coordinate;

        //ハンドルが一つの時
        if(bezier[3].x == 0.0f && bezier[3].y == 0.0f){
            
            //グラフの描画
            for(float t = 0.0f; t < 1.0f; t += 1.0f/(float)(precision)){
                
                ofVec2f bezierCurvePoint;
                
                if(!bCalcMode){
                    bezierCurvePoint = calc3BezierCurveCoord(bezier, t);
                }else{
                    bezierCurvePoint = calcBezierCurveCoord(bezier, 3, t);
                }
                
                ofSetColor(skin);
                ofDrawCircle(bezierCurvePoint, 2);
                

            }
            //setTime秒に設定
            float easingTime = ofMap(currentTime, time, time + setTime, 0.0f, 1.0f);
            ofVec2f easingCoord;
            if(!bCalcMode){
                easingCoord = calc3BezierCurveCoord(bezier, easingTime);
            }else{
                easingCoord = calcBezierCurveCoord(bezier, 3, easingTime);
            }
            float easingX_normalized = ofMap(easingCoord.x, graphX, graphWidth + graphX, 0.0f, 1.0f);
            float easingY_normalized = ofMap(easingCoord.y, graphY + graphHeight, graphY, 0.0f, 1.0f);
            
            coordinate = ofVec2f(easingX_normalized, easingY_normalized);
            
            
            
            
        }
        //ハンドルが二つの時
        else{
            

            //グラフの描画
            for(float t = 0.0f; t < 1.0f; t += 1.0f/(float)(precision)){
                ofVec2f bezierCurvePoint;
                
                if(!bCalcMode){
                    bezierCurvePoint = calc4BezierCurveCoord(bezier, t);
                }else{
                    bezierCurvePoint = calcBezierCurveCoord(bezier, 4, t);
                }
                
                
                ofSetColor(skin);
                ofDrawCircle(bezierCurvePoint, 2);
                
                
            }
            
            
            
            //setTime秒に設定
            float easingTime = ofMap(currentTime, time, time + setTime, 0.0f, 1.0f);
            ofVec2f easingCoord;
            if(!bCalcMode){
                easingCoord = calc4BezierCurveCoord(bezier, easingTime);
            }else{
                easingCoord = calcBezierCurveCoord(bezier, 4, easingTime);
            }
            float easingX_normalized = ofMap(easingCoord.x, graphX, graphWidth + graphX, 0.0f, 1.0f);
            float easingY_normalized = ofMap(easingCoord.y, graphY + graphHeight, graphY, 0.0f, 1.0f);
            
            coordinate = ofVec2f(easingX_normalized, easingY_normalized);
            
            
        }
        //プレビュー
        if(bPreview){
            ofVec2f point;
            
            point.x = coordinate.y * graphWidth + graphX;
            point.y = graphY + (graphHeight/2);
            ofSetColor(lightBlue);
            ofDrawCircle(point.x, point.y, 4);
        }
        
        //デバックlog用
        if(statusLog || bJsonFloatTime || bJsonFloat){
            easingArray.push_back(coordinate.y);
        }
        
        
        if(currentTime > setTime + time){
            //デバックlog用
            if(statusLog){
                std::cout << "--------------------------------------" << std::endl;
                std::cout << "easingArray = "<< std::endl;
                string array;
                for(int e = 0;e < easingArray.size(); e++){
                    array += ofToString(easingArray[e]);
                    //                    std::cout << easingArray[e] << "," << std::endl;
                    if(easingArray[easingArray.size() - 1] != easingArray[e]){
                        array += ',';
                    }
                }
                std::cout << array << std::endl;
                std::cout << "--------------------------------------" << std::endl;
                easingArray.clear();
                
            }
            else if(bJsonFloatTime || bJsonFloat){
                if(bJsonFloat){
                    printJsonEasingFloatProcess(easingArray);
                    
                }
                else if(bJsonFloatTime){
                    printJsonEasingFloatTimePrcess(easingArray);
                    
                }
                easingArray.clear();
                
            }
            
            bTime = false;
        }
        
        
        
    }
    else if( (sizeof(bezier) / sizeof(ofVec2f)) < 3 ){
        std::cout << "bezierのハンドルが存在しません。" << std::endl;

    }
    //初期位置報告
    else{
        if(statusLog){
            std::cout << "bezierのハンドルが初期値です。bezierのハンドルを設定してください。" << std::endl;
        }
        
    }
}


//--------------------------------------------------------------

//デバックかつイージング調整用で、イージングを適用したofVec2f型の要素4の配列を返す
//pricisionでイージングの精度を調整100無印と一緒
void ofxEasingGUI::adjustEasing(ofVec2f (&bezierArray)[4], float setTime,float currentTime){
    
    draw();

    //初期時間
    if(!bTime){
        time = currentTime;
        bTime = true;
    }
    //初期値のままだとdrawしない
    if((bezier[2].x != 0.0f && bezier[2].y !=  0.0f) || (bezier[3].x != 0.0f && bezier[3].y != 0.0f)){
        
        
        drawBeizerPoint();

        
        int precision = 100;
        ofVec2f coordinate;

        
        //ハンドルが一つの時
        if(bezier[3].x == 0.0f && bezier[3].y == 0.0f){
            
            //グラフの描画
            for(float t = 0.0f; t < 1.0f; t += 1.0f/(0.01f)){
                ofVec2f bezierCurvePoint;
                
                if(!bCalcMode){
                    bezierCurvePoint = calc3BezierCurveCoord(bezier, t);
                }else{
                    bezierCurvePoint = calcBezierCurveCoord(bezier, 3, t);
                }
                
                ofSetColor(skin);
                ofDrawCircle(bezierCurvePoint, 2);
                
            }
            //setTime秒に設定
            float easingTime = ofMap(currentTime, time, time + setTime, 0.0f, 1.0f);
            ofVec2f easingCoord;
            if(!bCalcMode){
                easingCoord = calc3BezierCurveCoord(bezier, easingTime);
            }else{
                easingCoord = calcBezierCurveCoord(bezier, 3, easingTime);
            }
            float easingX_normalized = ofMap(easingCoord.x, graphX, graphWidth + graphX, 0.0f, 1.0f);
            float easingY_normalized = ofMap(easingCoord.y, graphY + graphHeight, graphY, 0.0f, 1.0f);
            
            coordinate = ofVec2f(easingX_normalized, easingY_normalized);
            
            
        }
        //ハンドルが二つの時
        else{
            
            //グラフの描画
            for(float t = 0.0f; t < 1.0f; t += 1.0f/(0.01f)){
                ofVec2f bezierCurvePoint;
                
                if(!bCalcMode){
                    bezierCurvePoint = calc4BezierCurveCoord(bezier, t);
                }else{
                    bezierCurvePoint = calcBezierCurveCoord(bezier, 4, t);
                }
                
                ofSetColor(skin);
                ofDrawCircle(bezierCurvePoint, 2);
                
                
            }
            
            
            
            //setTime秒に設定
            float easingTime = ofMap(currentTime, time, time + setTime, 0.0f, 1.0f);
            ofVec2f easingCoord;
            if(!bCalcMode){
                easingCoord = calc4BezierCurveCoord(bezier, easingTime);
            }else{
                easingCoord = calcBezierCurveCoord(bezier, 4, easingTime);
            }
            float easingX_normalized = ofMap(easingCoord.x, graphX, graphWidth + graphX, 0.0f, 1.0f);
            float easingY_normalized = ofMap(easingCoord.y, graphY + graphHeight, graphY, 0.0f, 1.0f);
            
            coordinate = ofVec2f(easingX_normalized, easingY_normalized);
            
            
        }
        //プレビュー
        if(bPreview){
            ofVec2f point;
            point.x = coordinate.y * graphWidth + graphX;
            point.y = graphY + (graphHeight/2);
            ofSetColor(lightBlue);
            ofDrawCircle(point.x, point.y, 4);
        }
        
        
        //デバックlog用
        if(statusLog || bJsonFloatTime || bJsonFloat){
            easingArray.push_back(coordinate.y);
        }
        
        
        
        if(currentTime > setTime + time){
            //デバックlog用
            if(statusLog){
                std::cout << "--------------------------------------" << std::endl;
                std::cout << "easingArray = "<< std::endl;
                string array;
                for(int e = 0;e < easingArray.size(); e++){
                    array += ofToString(easingArray[e]);
                    //                    std::cout << easingArray[e] << "," << std::endl;
                    if(easingArray[easingArray.size() - 1] != easingArray[e]){
                        array += ',';
                    }
                    
                }
                std::cout << array << std::endl;
                std::cout << "--------------------------------------" << std::endl;
                easingArray.clear();
                
            }
            else if(bJsonFloatTime || bJsonFloat){
                if(bJsonFloat){
                    printJsonEasingFloatProcess(easingArray);
                    
                }
                else if(bJsonFloatTime){
                    printJsonEasingFloatTimePrcess(easingArray);
                    
                }
                easingArray.clear();
                
            }
            
            bTime = false;
        }
        
        
        bezierArray[0] = bezier[0];
        bezierArray[1] = bezier[1];
        bezierArray[2] = bezier[2];
        bezierArray[3] = bezier[3];
        
        if(statusLog){
            std::cout << "bezierArray[0] = ("<< bezierArray[0].x << ", " << bezierArray[0].y << ")"  <<  std::endl;
            std::cout << "bezierArray[1] = ("<< bezierArray[1].x << ", " << bezierArray[1].y << ")"  <<  std::endl;
            std::cout << "bezierArray[2] = ("<< bezierArray[2].x << ", " << bezierArray[2].y << ")"  <<  std::endl;
            std::cout << "bezierArray[3] = ("<< bezierArray[3].x << ", " << bezierArray[3].y << ")"  <<  std::endl;

            

            std::cout << "--------------------------------------" << std::endl;

        }
        
    }
    else if( (sizeof(bezier) / sizeof(ofVec2f)) < 3 ){
        std::cout << "bezierのハンドルが存在しません。" << std::endl;
        
    }
    //初期位置報告
    else{
        if(statusLog){
            std::cout << "bezierのハンドルが初期値です。bezierのハンドルを設定してください。" << std::endl;
        }
        
    }
    
    
    
}


//--------------------------------------------------------------


//デバックかつイージング調整用で、イージングを適用したofVec2f型の要素4の配列を返す
//jsonファイルに出力して、設定を記憶。
//pricisionでイージングの精度を調整100無印と一緒
void ofxEasingGUI::adjustEasing(ofVec2f (&bezierArray)[4] , int precision, float setTime,float currentTime){
    
    draw();

    //初期時間
    if(!bTime){
        time = currentTime;
        bTime = true;
    }
    
    //初期値のままだとdrawしない
    if((bezier[2].x != 0.0f && bezier[2].y !=  0.0f) || (bezier[3].x != 0.0f && bezier[3].y != 0.0f)){
        
        
        drawBeizerPoint();
        
        ofVec2f coordinate;

        //ハンドルが一つの時
        if(bezier[3].x == 0.0f && bezier[3].y == 0.0f){
            

            //グラフの描画
            for(float t = 0.0f; t < 1.0f; t += 1.0f/(float)(precision)){
                ofVec2f bezierCurvePoint;
                
                if(!bCalcMode){
                    bezierCurvePoint = calc3BezierCurveCoord(bezier, t);
                }else{
                    bezierCurvePoint = calcBezierCurveCoord(bezier, 3, t);
                }
                
                ofSetColor(skin);
                ofDrawCircle(bezierCurvePoint, 2);
                
            }
            //setTime秒に設定
            float easingTime = ofMap(currentTime, time, time + setTime, 0.0f, 1.0f);
            ofVec2f easingCoord;
            if(!bCalcMode){
                easingCoord = calc3BezierCurveCoord(bezier, easingTime);
            }else{
                easingCoord = calcBezierCurveCoord(bezier, 3, easingTime);
            }
            float easingX_normalized = ofMap(easingCoord.x, graphX, graphWidth + graphX, 0.0f, 1.0f);
            float easingY_normalized = ofMap(easingCoord.y, graphY + graphHeight, graphY, 0.0f, 1.0f);
            
            coordinate = ofVec2f(easingX_normalized, easingY_normalized);

            
        }
        //ハンドルが二つの時
        else{
            

            //グラフの描画
            for(float t = 0.0f; t < 1.0f; t += 1.0f/(float)(precision)){
                ofVec2f bezierCurvePoint;
                
                if(!bCalcMode){
                    bezierCurvePoint = calc4BezierCurveCoord(bezier, t);
                }else{
                    bezierCurvePoint = calcBezierCurveCoord(bezier, 4, t);
                }
                
                ofSetColor(skin);
                ofDrawCircle(bezierCurvePoint, 2);
                
                
            }
            
            
            
            //setTime秒に設定
            float easingTime = ofMap(currentTime, time, time + setTime, 0.0f, 1.0f);
            ofVec2f easingCoord;

            if(!bCalcMode){
                easingCoord = calc4BezierCurveCoord(bezier, easingTime);
            }else{
                easingCoord = calcBezierCurveCoord(bezier, 4, easingTime);
            }
            float easingX_normalized = ofMap(easingCoord.x, graphX, graphWidth + graphX, 0.0f, 1.0f);
            float easingY_normalized = ofMap(easingCoord.y, graphY + graphHeight, graphY, 0.0f, 1.0f);
            
            coordinate = ofVec2f(easingX_normalized, easingY_normalized);
            
            
        }
        
        //プレビュー
        if(bPreview){
            ofVec2f point;
            point.x = coordinate.y * graphWidth + graphX;
            point.y = graphY + (graphHeight/2);
            ofSetColor(lightBlue);
            ofDrawCircle(point.x, point.y, 4);
        }
        
        
        //デバックlog用
        if(statusLog || bJsonFloat || bJsonFloatTime){
//            easingArray.push_back(coordinates[index].y);
            easingArray.push_back(coordinate.y);

        }
        
        
        if(currentTime > setTime + time){
            //デバックlog用
            if(statusLog){
                std::cout << "--------------------------------------" << std::endl;
                std::cout << "easingArray = "<< std::endl;
                string array;
                for(int e = 0;e < easingArray.size(); e++){
                    array += ofToString(easingArray[e]);
                    //                    std::cout << easingArray[e] << "," << std::endl;
                    if(easingArray[easingArray.size() - 1] != easingArray[e]){
                        array += ',';
                    }
                    
                }
                std::cout << array << std::endl;
                std::cout << "--------------------------------------" << std::endl;
                easingArray.clear();
                
            }
            else if(bJsonFloatTime || bJsonFloat){
                if(bJsonFloat){
                    printJsonEasingFloatProcess(easingArray);
                    
                }
                else if(bJsonFloatTime){
                    printJsonEasingFloatTimePrcess(easingArray);
                    
                }
                easingArray.clear();
                
            }
            bTime = false;
        }
        
        
        bezierArray[0] = bezier[0];
        bezierArray[1] = bezier[1];
        bezierArray[2] = bezier[2];
        bezierArray[3] = bezier[3];
        
        
        if(statusLog){
            std::cout << "bezierArray[0] = ("<< bezierArray[0].x << ", " << bezierArray[0].y << ")"  <<  std::endl;
            std::cout << "bezierArray[1] = ("<< bezierArray[1].x << ", " << bezierArray[1].y << ")"  <<  std::endl;
            std::cout << "bezierArray[2] = ("<< bezierArray[2].x << ", " << bezierArray[2].y << ")"  <<  std::endl;
            std::cout << "bezierArray[3] = ("<< bezierArray[3].x << ", " << bezierArray[3].y << ")"  <<  std::endl;
            
            
            
            std::cout << "--------------------------------------" << std::endl;
            
        }
        
        
    }
    else if( (sizeof(bezier) / sizeof(ofVec2f)) < 3 ){
        std::cout << "bezierのハンドルが存在しません。" << std::endl;
        
    }
    //初期位置報告
    else{
        if(statusLog){
            std::cout << "bezierのハンドルが初期値です。bezierのハンドルを設定してください。" << std::endl;
        }
        
        
    }
}

//--------------------------------------------------------------


//jsonファイルからのbezier入力
float ofxEasingGUI::applyEasingJsonBezier(string filePath, float setTime, float currentTime){
    
    //json読み込み
    bool success = json.open(filePath);
    //デバック・ログ表示
    if(statusLog){
        if(success){
            std::cout << json.getRawString() << std::endl;
        }
        else{
            std::cout << "Failed to parse JSON" << std::endl;
            return 0.0f;
        }
    }
    
    
    //jsonの代入
    
    float myGraphX = json["graphX"].asFloat();
    float myGraphY = json["graphY"].asFloat();
    float myGraphWidth = json["graphWidth"].asFloat();
    float myGraphHeight = json["graphHeight"].asFloat();
    
    graphX = myGraphX;
    graphY = myGraphY;
    graphWidth = myGraphWidth;
    graphHeight = myGraphHeight;
    
    ofVec2f myBezier[4];
    
    //jsonからの代入
    for(int i = 0;i < json["bezier"].size(); i++){
        myBezier[i] = ofVec2f(json["bezier"][i]["x"].asFloat(), json["bezier"][i]["y"].asFloat());
    }
    
//    cout << "mybezier0 = " << myBezier[0] << endl;
//    cout << "mybezier1 = " << myBezier[1] << endl;
//    cout << "mybezier2 = " << myBezier[2] << endl;
//    cout << "mybezier3 = " << myBezier[3] << endl;

    
    //デバック・ログ表示
    if(statusLog){
        std::cout << "myGrpahX = " << myGraphX << std::endl;
        std::cout << "myGraphY = " << myGraphY << std::endl;
        std::cout << "myGraphWidth = " << myGraphWidth << std::endl;
        std::cout << "myGraphHeight = " << myGraphHeight << std::endl;
    }
    
    
    //初期時間
    if(!bTime){
        time = currentTime;
        bTime = true;
    }
    
    ofVec2f coordinate;
    
    //ベジェのハンドルが一つなら
    if(myBezier[3].x == 0.0f && myBezier[3].y == 0.0f){
        //setTime秒に設定
        float easingTime = ofMap(currentTime, time, time + setTime, 0.0f, 1.0f);
        ofVec2f bezierCurvePoint;
        if(!bCalcMode){
            bezierCurvePoint = calc3BezierCurveCoord(myBezier, easingTime);
        }else{
            bezierCurvePoint = calcBezierCurveCoord(myBezier, 3, easingTime);
        }
        
        ofVec2f normalized_bezierCurvePoint;
        normalized_bezierCurvePoint.x = ofMap(bezierCurvePoint.x, graphX, graphX + graphWidth,0.0f, 1.0f);
        normalized_bezierCurvePoint.y = ofMap(bezierCurvePoint.y, graphY + graphHeight, graphY, 0.0f, 1.0f);
        coordinate = normalized_bezierCurvePoint;
        
        
        //デバックlog用
        if(statusLog){
            easingArray.push_back(coordinate.y);
        }
        
        if(currentTime > setTime + time){
            //デバックlog用
            if(statusLog){
                std::cout << "--------------------------------------" << std::endl;
                std::cout << "easingArray = "<< std::endl;
                string array;
                for(int e = 0;e < easingArray.size(); e++){
                    array += ofToString(easingArray[e]);
                    //                    std::cout << easingArray[e] << "," << std::endl;
                    if(easingArray[easingArray.size() - 1] != easingArray[e]){
                        array += ',';
                    }
                    
                }
                std::cout << array << std::endl;
                std::cout << "--------------------------------------" << std::endl;
                easingArray.clear();
                
            }
            
            bTime = false;
        }
        
        
        return coordinate.y;
    }
    
    //ハンドルが二つの時
    else{
        //setTime秒に設定
        float easingTime = ofMap(currentTime, time, time + setTime, 0.0f, 1.0f);
        ofVec2f bezierCurvePoint;
        if(!bCalcMode){
            bezierCurvePoint = calc4BezierCurveCoord(myBezier, easingTime);
        }else{
            bezierCurvePoint = calcBezierCurveCoord(myBezier, 4, easingTime);
        }
        ofVec2f normalized_bezierCurvePoint;
        normalized_bezierCurvePoint.x = ofMap(bezierCurvePoint.x, graphX, graphX + graphWidth,0.0f, 1.0f);
        normalized_bezierCurvePoint.y = ofMap(bezierCurvePoint.y, graphY + graphHeight, graphY, 0.0f, 1.0f);
        coordinate = normalized_bezierCurvePoint;
        
        
        
        //デバックlog用
        if(statusLog){
            easingArray.push_back(coordinate.y);
        }
        
        
        
        if(currentTime > setTime + time){
            //デバックlog用
            if(statusLog){
                std::cout << "--------------------------------------" << std::endl;
                std::cout << "easingArray = "<< std::endl;
                string array;
                for(int e = 0;e < easingArray.size(); e++){
                    array += ofToString(easingArray[e]);
                    //                    std::cout << easingArray[e] << "," << std::endl;
                    if(easingArray[easingArray.size() - 1] != easingArray[e]){
                        array += ',';
                    }
                    
                }
                std::cout << array << std::endl;
                std::cout << "--------------------------------------" << std::endl;
                easingArray.clear();
                
            }
            
            bTime = false;
        }
        
        
        
        return coordinate.y;

        
    }
    
}


//--------------------------------------------------------------

float ofxEasingGUI::applyEasingJsonFloat(string filePath, float setTime, float currentTime){
    //json読み込み
    bool success = json.open(filePath);
    //デバック・ログ表示
    if(statusLog){
        if(success){
            std::cout << json.getRawString() << std::endl;
        }
        else{
            std::cout << "Failed to parse JSON" << std::endl;
            return 0.0f;
        }
    }
    
    
    //jsonの代入
    
    float myGraphX = json["graphX"].asFloat();
    float myGraphY = json["graphY"].asFloat();
    float myGraphWidth = json["graphWidth"].asFloat();
    float myGraphHeight = json["graphHeight"].asFloat();
    
    graphX = myGraphX;
    graphY = myGraphY;
    graphWidth = myGraphWidth;
    graphHeight = myGraphHeight;
    
    vector<float> easingValues;
    
    //jsonからの代入
    for(int i = 0;i < json["easingValues"].size(); i++){
        easingValues.push_back(json["easingValues"][i].asFloat());
    }
    
    //デバック・ログ表示
    if(statusLog){
        std::cout << "myGrpahX = " << myGraphX << std::endl;
        std::cout << "myGraphY = " << myGraphY << std::endl;
        std::cout << "myGraphWidth = " << myGraphWidth << std::endl;
        std::cout << "myGraphHeight = " << myGraphHeight << std::endl;
    }
    
    
    //初期時間
    if(!bTime){
        time = currentTime;
        bTime = true;
    }
    
    float easingTime = ofMap(currentTime, time, time + setTime, 0.0f, 1.0f);
    int num = easingValues.size() * easingTime;
    
    
    if(currentTime > setTime + time){
        
        
        bTime = false;
    }
    
    
    return easingValues[num];
    
    

    
    
}





//--------------------------------------------------------------

float ofxEasingGUI::applyEasing(float setTime, float currentTime){
    //初期時間
    if(!bTime){
        time = currentTime;
        bTime = true;
    }
    
    float value;
    
    ofVec2f coordinate;

    
    //setTime秒に設定
    float easingTime = ofMap(currentTime, time, time + setTime, 0.0f, 1.0f);
    
    //ハンドルが一つの時
    if(bezier[3].x == 0.0f && bezier[3].y == 0.0f){
        
        ofVec2f bezierCurvePoint;
        if(!bCalcMode){
            bezierCurvePoint = calc3BezierCurveCoord(bezier, easingTime);
        }else{
            bezierCurvePoint = calcBezierCurveCoord(bezier, 3, easingTime);
        }
        ofVec2f normalized_bezierCurvePoint;
        normalized_bezierCurvePoint.x = ofMap(bezierCurvePoint.x, graphX, graphX + graphWidth,0.0f, 1.0f);
        normalized_bezierCurvePoint.y = ofMap(bezierCurvePoint.y, graphY + graphHeight, graphY, 0.0f, 1.0f);
        coordinate = normalized_bezierCurvePoint;
        
        
        value =  coordinate.y;

        
        if(currentTime > setTime + time){
            
            bTime = false;
        }
        
    }
    //ハンドルが二つの時
    else{
        
        
        ofVec2f bezierCurvePoint;
        if(!bCalcMode){
            bezierCurvePoint = calc4BezierCurveCoord(bezier, easingTime);
        }else{
            bezierCurvePoint = calcBezierCurveCoord(bezier, 4, easingTime);
        }
        ofVec2f normalized_bezierCurvePoint;
        normalized_bezierCurvePoint.x = ofMap(bezierCurvePoint.x, graphX, graphX + graphWidth,0.0f, 1.0f);
        normalized_bezierCurvePoint.y = ofMap(bezierCurvePoint.y, graphY + graphHeight, graphY, 0.0f, 1.0f);
        coordinate = normalized_bezierCurvePoint;
        
        value =  coordinate.y;

        
        
        if(currentTime > setTime + time){
            
            bTime = false;
        }
        
    }
    
    
    
    
    
    return value;
}

//--------------------------------------------------------------


float ofxEasingGUI::applyEasing(ofVec2f (&bezierArray)[4], float setTime, float currentTime){
    //初期時間
    if(!bTime){
        time = currentTime;
        bTime = true;
    }
    
    float value;
    
    ofVec2f coordinate;
    
    
    //setTime秒に設定
    float easingTime = ofMap(currentTime, time, time + setTime, 0.0f, 1.0f);
    
    //ハンドルが一つの時
    if(bezierArray[3].x == 0.0f && bezierArray[3].y == 0.0f){
        
        ofVec2f bezierCurvePoint;
        if(!bCalcMode){
            bezierCurvePoint = calc3BezierCurveCoord(bezierArray, easingTime);
        }else{
            bezierCurvePoint = calcBezierCurveCoord(bezierArray, 3, easingTime);
        }
        ofVec2f normalized_bezierCurvePoint;
        normalized_bezierCurvePoint.x = ofMap(bezierCurvePoint.x, graphX, graphX + graphWidth,0.0f, 1.0f);
        normalized_bezierCurvePoint.y = ofMap(bezierCurvePoint.y, graphY + graphHeight, graphY, 0.0f, 1.0f);
        coordinate = normalized_bezierCurvePoint;
        
        
        value =  coordinate.y;
        
        
        if(currentTime > setTime + time){
            
            bTime = false;
        }
        
    }
    //ハンドルが二つの時
    else{
        
        
        ofVec2f bezierCurvePoint;
        if(!bCalcMode){
            bezierCurvePoint = calc4BezierCurveCoord(bezierArray, easingTime);
        }else{
            bezierCurvePoint = calcBezierCurveCoord(bezierArray, 4, easingTime);
        }
        ofVec2f normalized_bezierCurvePoint;
        normalized_bezierCurvePoint.x = ofMap(bezierCurvePoint.x, graphX, graphX + graphWidth,0.0f, 1.0f);
        normalized_bezierCurvePoint.y = ofMap(bezierCurvePoint.y, graphY + graphHeight, graphY, 0.0f, 1.0f);
        coordinate = normalized_bezierCurvePoint;
        
        value =  coordinate.y;
        
        
        
        if(currentTime > setTime + time){
            
            bTime = false;
        }
        
    }
    return value;

}



//--------------------------------------------------------------





//--------------------------------------------------------------



        
//bezierをclearしたい時用の関数
void ofxEasingGUI::clear(){
//    bezier.clear();
    bCurve1 = false;
    bCurve2 = false;
    bezier[0] = (ofVec2f(graphX, graphHeight + graphY));//左下
    bezier[1] = (ofVec2f(graphWidth + graphX, graphY));//右上
    bezier[2] = ofVec2f(0.0f, 0.0f);
    bezier[3] = ofVec2f(0.0f, 0.0f);
}

    
//--------------------------------------------------------------

    
    
    
void ofxEasingGUI::enableEasingLog(){
    statusLog = true;

}


//--------------------------------------------------------------

    
    
void ofxEasingGUI::disableEasingLog(){
    statusLog = false;
}


//--------------------------------------------------------------


//ベジェの4つの配列の座標をjsonに出力する
void ofxEasingGUI::printJsonEasingBezier(string fileName){
    ofFile newFile(ofToDataPath(fileName + ".json"), ofFile::ReadWrite); //file doesn't exist yet
    newFile.create(); // now file doesn't exist
    myTextFile.open(ofToDataPath(fileName + ".json"), ofFile::ReadWrite, false);
    
    string text = "{";
    text += "\"graphX\":" + ofToString(graphX) + ",";
    text += "\"graphY\":" + ofToString(graphY) + ",";
    text += "\"graphWidth\":" + ofToString(graphWidth) + ",";
    text += "\"graphHeight\":" + ofToString(graphHeight) + ",";

    
    text += "\"bezier\":[";
    
    for(int i = 0;i < 4; i++){
        text += "{\"x\":" + ofToString(bezier[i].x) + ",";
        text += "\"y\":" + ofToString(bezier[i].y);
        if(i != 4-1){
            text += "},";
        }
        else{
            text += "}";

        }
        
    }
    text += "]}";
    
    if(statusLog){
        cout << text << endl;
    }
    
    
    
    myTextFile << text;
    
    
    
}

//--------------------------------------------------------------

//ベジェの4つの配列の座標をjsonに出力する(file名に時間をつける)
void ofxEasingGUI::printJsonEasingBezierTime(string fileName){
    
    string currentFileTime = ofGetTimestampString();
    ofFile newFile(ofToDataPath(fileName + "_" + currentFileTime + ".json"), ofFile::ReadWrite); //file doesn't exist yet
    newFile.create(); // now file doesn't exist
    myTextFile.open(ofToDataPath(fileName + "_" + currentFileTime + ".json"), ofFile::ReadWrite, false);
    
    string text = "{";
    text += "\"graphX\":" + ofToString(graphX) + ",";
    text += "\"graphY\":" + ofToString(graphY) + ",";
    text += "\"graphWidth\":" + ofToString(graphWidth) + ",";
    text += "\"graphHeight\":" + ofToString(graphHeight) + ",";
    
    
    text += "\"bezier\":[";
    
    for(int i = 0;i < 4; i++){
        text += "{\"x\":" + ofToString(bezier[i].x) + ",";
        text += "\"y\":" + ofToString(bezier[i].y);
        if(i != 4-1){
            text += "},";
        }
        else{
            text += "}";
        }
        
    }
    text += "]}";
    
    
    myTextFile << text;
    
}


//--------------------------------------------------------------

void ofxEasingGUI::printJsonEasingFloat(string fileName){
    bJsonFloat = true;
    jsonFileName = fileName;
}

//--------------------------------------------------------------


void ofxEasingGUI::printJsonEasingFloatTime(string fileName){
    bJsonFloatTime = true;
    jsonFileName = fileName;
    
}
//--------------------------------------------------------------


void ofxEasingGUI::printJsonEasingFloatProcess(vector<float> normalizedValues){
    
    ofFile newFile(ofToDataPath(jsonFileName  + ".json"), ofFile::ReadWrite); //file doesn't exist yet
    newFile.create(); // now file doesn't exist
    myTextFile.open(ofToDataPath(jsonFileName  + ".json"), ofFile::ReadWrite, false);
    
    string text = "{";
    text += "\"graphX\":" + ofToString(graphX) + ",";
    text += "\"graphY\":" + ofToString(graphY) + ",";
    text += "\"graphWidth\":" + ofToString(graphWidth) + ",";
    text += "\"graphHeight\":" + ofToString(graphHeight) + ",";
    
    
    text += "\"easingValues\":[";
    
    for(int i = 0;i < normalizedValues.size(); i++){
        text += ofToString(normalizedValues[i]);
        if(i != normalizedValues.size() - 1){
            text += ",";
        }
        else{
        }
        
    }
    text += "]}";
    
    
    myTextFile << text;
    
    bJsonFloatTime = false;
}


//--------------------------------------------------------------


void ofxEasingGUI::printJsonEasingFloatTimePrcess(vector<float> normalizedValues){
    
    string currentFileTime = ofGetTimestampString();

    ofFile newFile(ofToDataPath(jsonFileName + "_" + currentFileTime + ".json"), ofFile::ReadWrite); //file doesn't exist yet
    newFile.create(); // now file doesn't exist
    myTextFile.open(ofToDataPath(jsonFileName + "_" + currentFileTime + ".json"), ofFile::ReadWrite, false);
    
    
    string text = "{";
    text += "\"graphX\":" + ofToString(graphX) + ",";
    text += "\"graphY\":" + ofToString(graphY) + ",";
    text += "\"graphWidth\":" + ofToString(graphWidth) + ",";
    text += "\"graphHeight\":" + ofToString(graphHeight) + ",";
    
    
    text += "\"easingValues\":[";
    
    for(int i = 0;i < normalizedValues.size(); i++){
        text += ofToString(normalizedValues[i]) + ",";
        
    }
    text += "]}";
    
    
    myTextFile << text;
    
    bJsonFloatTime = false;

}

//--------------------------------------------------------------

//ofEvent<ofVec2f> clicked;
//コンストラクタ
ofxEasingGUI::ofxEasingGUI(){
    bRegisterdEvents = false;
}

//--------------------------------------------------------------

//デコンストラクタ
ofxEasingGUI::~ofxEasingGUI(){
    eventClear();
}

//--------------------------------------------------------------


void ofxEasingGUI::eventRegister(){
    if(!bRegisterdEvents){
        
        //this will enable our  class to listen to the key events
        ofRegisterKeyEvents(this);
        
        //this will enable our  class to listen to the mouse events
        ofRegisterMouseEvents(this);
       
        
        bRegisterdEvents = true;
    }
}

//--------------------------------------------------------------


void ofxEasingGUI::eventClear(){
    if(bRegisterdEvents){
        
        //disable listenig to key events
        ofUnregisterKeyEvents(this);
        
        //disable listenig to mouse events
        //        マウスイベントの監視を無効にする
        ofUnregisterMouseEvents(this);
        
        
        bRegisterdEvents = false;
    }
}

//--------------------------------------------------------------
//公式 ofKeyEventArgs
//https://openframeworks.cc/documentation/events/ofKeyEventArgs/#show_type
//enumでofkeyEventArgsが定義されている。


void ofxEasingGUI::keyPressed(ofKeyEventArgs &args){
    
    
    ofNotifyEvent(evKeyPressed, args.key, this);

}

//--------------------------------------------------------------


void ofxEasingGUI::keyReleased(ofKeyEventArgs &args){
    
    ofNotifyEvent(evKeyReleased, args.key, this);

}

//--------------------------------------------------------------


void ofxEasingGUI::mouseMoved(ofMouseEventArgs &args){
    

}


//--------------------------------------------------------------

void ofxEasingGUI::mouseDragged(ofMouseEventArgs &args){
//    mouseDraggedBezier(args.x, args.y);
    
    ofVec2f mousePos = ofVec2f(args.x, args.y);
    ofNotifyEvent(evMouseDragged, mousePos, this);

}

//--------------------------------------------------------------

void ofxEasingGUI::mousePressed(ofMouseEventArgs &args){
//    mousePressedBezier(args.x, args.y);

    ofVec2f mousePos = ofVec2f(args.x, args.y);
    ofNotifyEvent(evMousePressed, mousePos, this);

}

//--------------------------------------------------------------

void ofxEasingGUI::mouseReleased(ofMouseEventArgs &args){
//    mouseReleasedBezier();
    
    ofVec2f mousePos = ofVec2f(args.x, args.y);
    ofNotifyEvent(evMouseReleased, mousePos, this);
}

//--------------------------------------------------------------

void ofxEasingGUI::mouseScrolled(ofMouseEventArgs &args){
    
}

//--------------------------------------------------------------

void ofxEasingGUI::mouseEntered(ofMouseEventArgs &args){
    
}

//--------------------------------------------------------------

void ofxEasingGUI::mouseExited(ofMouseEventArgs &args){
    
}

//--------------------------------------------------------------
