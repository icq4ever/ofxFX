#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofEnableAlphaBlending();
    ofSetWindowShape(640*2, 480);
    
    rip.allocate(640,480);
    bounce.allocate(640,480);
    
    ofImage background;
    background.load("fondo.jpg");
    
    bounce.setTexture(background.getTexture(), 1);
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
    
    rip.begin();
    ofFill();
    ofSetColor(ofNoise( ofGetFrameNum() ) * 255 * 5, 255);
    ofDrawEllipse(mouseX,mouseY, 10,10);
    rip.end();
    rip.update();
    
    bounce << rip;
//    bounce.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    ofSetColor(255,255);
    
    rip.draw(0,0);
    ofDrawBitmapString("ofxRipples ( damping = " + ofToString(rip.damping) + " )", 15,15);
    
    bounce.draw(640,0);
    ofDrawBitmapString("ofxBounce", 640+15,15);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == OF_KEY_UP){
        rip.damping += 0.01;
    } else if ( key == OF_KEY_DOWN){
        rip.damping -= 0.01;
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
    rip.damping = ofMap(y, 0, ofGetHeight(), 0.9, 1.0, true);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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