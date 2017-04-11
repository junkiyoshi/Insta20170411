#pragma once

#include "ofMain.h"

class Particle
{
public:
	Particle(float x, float y, float z);
	~Particle();
	
	void applyForce(ofVec3f force);
	
	ofVec3f seek(ofVec3f target);
	ofVec3f separate(vector<Particle> particles);
	ofVec3f align(vector<Particle> particles);
	ofVec3f cohesion(vector<Particle> particles);
	
	void flok(vector<Particle> particles);
	void borders();
	void think();
	void update();
	void draw();

private:
	ofVec3f location;
	ofVec3f velocity;
	ofVec3f acceleration;
	vector<ofVec3f> log;
	int log_size;
	float max_speed;
	float max_force;
	float radius;
	float angle;
	
	ofColor body_color;
	float body_size;
};