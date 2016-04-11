//  Conway Life GLSL Game
//
//  Created by kalwalt alias Walter Perdan on 24/12/11
//  Copyright 2011 http://www.kalwaltart.it/ All rights reserved.
//

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableAlphaBlending();
	ofSetWindowShape(640, 480);

	image.load("mem.gif");

    conway.allocate(640, 480);
    conway.setPasses(10);
    //
    // Created by kalwalt alias Walter Perdan on 24/12/11
    // Copyright 2011 http://www.kalwaltart.it/ All rights reserved.
    conway.setCode( "#version 120\n \
                        #extension GL_ARB_texture_rectangle : enable\n \
                        \
                        uniform sampler2DRect tex0; \
                        \
                        vec4 dead = vec4(1.0,1.0,1.0,1.0); \
                        vec4 alive = vec4(0.0,0.0,0.0,1.0); \
                        \
                        void main(void) { \
                            vec2  st = gl_TexCoord[0].st;\
                            int sum = 0; \
                            vec4 y = texture2DRect(tex0, st); \
                            \
                            if (texture2DRect(tex0, st + vec2(-1.0, -1.0)) == alive) ++sum; \
                            if (texture2DRect(tex0, st + vec2(0.0, -1.0)) == alive) ++sum; \
                            if (texture2DRect(tex0, st + vec2(1.0, -1.0)) == alive) ++sum; \
                            \
                            if (texture2DRect(tex0, st + vec2(-1.0, 0.0)) == alive) ++sum; \
                            if (texture2DRect(tex0, st + vec2(1.0, 0.0)) == alive) ++sum; \
                            \
                            if (texture2DRect(tex0, st + vec2(-1.0, 1.0)) == alive) ++sum; \
                            if (texture2DRect(tex0, st + vec2(0.0, 1.0)) == alive) ++sum; \
                            if (texture2DRect(tex0, st + vec2(1.0, 1.0)) == alive) ++sum; \
                            \
                            if (sum < 2) gl_FragColor = dead; \
                            else if (sum > 3) gl_FragColor = dead; \
                            else if (sum == 3) gl_FragColor = alive; \
                            else gl_FragColor = y; \
                        }");
    
//    conway.setTexture(image.getTextureReference());
	conway.setTexture(image.getTexture());
}
//--------------------------------------------------------------
void ofApp::update(){

    conway.begin();
    ofClear(255, 255);
    conway.draw();
    ofSetColor(0,255);
    ofDrawCircle(mouseX, mouseY, 5);
    conway.end();
    
    conway.update();

    ofSetWindowTitle(ofToString(ofGetFrameRate()));

}

//--------------------------------------------------------------
void ofApp::draw(){

    conway.draw();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
