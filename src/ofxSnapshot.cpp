/*
 * ofxSnapshot.cpp
 *
 *  Created on: Jun 1, 2013
 *      Author: felix
 */

#include "ofxSnapshot.h"

ofxSnapshot::ofxSnapshot() {
	snapshotKey = 's';
	snapshotActive = false;
	color.set(0,0,255);
	ofRegisterKeyEvents(this);
	ofRegisterMouseEvents(this);
}

ofxSnapshot::~ofxSnapshot() {
	// TODO Auto-generated destructor stub
}

void ofxSnapshot::setSnapshotKey(char key){
	snapshotKey = key;
}

void ofxSnapshot::draw(){
	if(isMousePressed){
		ofPushStyle();
		ofRectangle rect(tl,br);
		ofSetColor(color);
		ofNoFill();
		ofRect(rect);
		ofSetColor(color,50);
		ofFill();
		ofRect(rect);
		ofPopStyle();
	}
}

void ofxSnapshot::mousePressed(ofMouseEventArgs &e){
	if(!snapshotActive)
		return;

	tl.x = e.x;
	tl.y = e.y;
	br = tl;
	isMousePressed = true;
}
void ofxSnapshot::mouseDragged(ofMouseEventArgs &e){
	if(isMousePressed){
		br.x = e.x;
		br.y = e.y;
	}
}
void ofxSnapshot::mouseReleased(ofMouseEventArgs &e){
	if(isMousePressed){
		isMousePressed = false;
		snapshotActive = false;
	}
}

void ofxSnapshot::keyPressed(ofKeyEventArgs & e){
	if(e.key == snapshotKey){
		snapshotActive = true;
	}
}
