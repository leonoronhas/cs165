#include "velocity.h"

//Constructors
Velocity::Velocity() {
	setDx(0);
	setDy(0);
}
	
Velocity::Velocity(float x, float y) {
	this->x = x;
	this->y = y;
}

/*******************************************
 * VELOCITY getDx
 * Will get x
 ******************************************/
float Velocity::getDx() const {
	return this->x;
}

/*******************************************
 * VELOCITY getDy
 * Will get y
 ******************************************/
float Velocity::getDy() const {
	return this->y;
}

/*******************************************
 * VELOCITY setDx
 * Will set velocity for the change of x
 ******************************************/
void Velocity::setDx(float x) {
	this->x = x;
}

/*******************************************
 * VELOCITY setDY
 * Will set velocity for the change of y
 ******************************************/
void Velocity::setDy(float y) {
	this->y = y;
}

