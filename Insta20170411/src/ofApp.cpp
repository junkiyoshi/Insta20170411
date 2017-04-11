#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowTitle("Many Particle");
	ofEnableDepthTest();
	ofEnableSmoothing();
	ofBackground(0);
	ofSetFrameRate(30);
	//ofBlendMode(OF_BLENDMODE_ADD);

	this->flg = true;

	for (int i = 0; i < 128; i++) {
		Particle particle = Particle(ofRandom(-ofGetWidth() / 2, ofGetWidth() / 2), ofRandom(-ofGetHeight() / 2, ofGetHeight() / 2), ofRandom(-512, 512));
		this->particles.push_back(particle);
	}
}

//--------------------------------------------------------------
void ofApp::update() {
	if (this->flg) {

		ofVec3f control;
		if (ofGetKeyPressed(OF_KEY_CONTROL)) {
			for (auto& p : this->particles) {
				p.applyForce(ofVec3f(ofRandom(-ofGetWidth() / 2, ofGetWidth() / 2), ofRandom(-ofGetHeight() / 2, ofGetHeight() / 2), ofRandom(-512, 512)));
			}
		}
		if (ofGetKeyPressed(OF_KEY_UP)) {
			control += ofVec3f(0, -10, 0);
		}
		if (ofGetKeyPressed(OF_KEY_DOWN)) {
			control += ofVec3f(0, 10, 0);
		}
		if (ofGetKeyPressed(OF_KEY_RIGHT)) {
			control += ofVec3f(10, 0, 0);
		}
		if (ofGetKeyPressed(OF_KEY_LEFT)) {
			control += ofVec3f(-10, 0, 0);
		}
		
		for (auto& p : this->particles) {
			p.applyForce(control);
		}
		

		for (auto& p : this->particles) {
			p.think();
			p.flok(this->particles);
			p.borders();
			p.update();
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2, 0);

	camera.begin();

	for (auto& p : this->particles) {
		p.draw();
	}

	camera.end();
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
	this->flg = true;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
