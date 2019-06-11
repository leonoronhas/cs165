#include "lander.h"
#include "uiDraw.h"

//Constructors
Lander::Lander() {
	alive = true;    //starts the game alive
	landed = false;
	thrust = true;
	fuel = 500;      //total amount of fuel
	point.setX(0);   //initial position of the lander horizontally
	point.setY(100); //initial position of the lander vertically
}


/*******************************************
 * LANDER getPoint
 * Will get point
 ******************************************/
Point Lander::getPoint() const {
	return point;
}

/*******************************************
 * LANDER getVelocity
 * Will get velocity
 ******************************************/
Velocity Lander::getVelocity() const {
	return velocity;
}

/*******************************************
 * LANDER isAlive
 * Will get whether lander starts alive or not
 ******************************************/
bool Lander::isAlive() const {
	return alive;
}

/*******************************************
 * LANDER isLanded
 * Will set whether landed is true or false
 ******************************************/
bool Lander::isLanded() const {
	return landed;
}

/*******************************************
 * LANDER getFuel
 * Will get fuel
 ******************************************/
int Lander::getFuel() const {
	return fuel;
}

/*******************************************
 * LANDER canThrust
 * Will decide whether or not apply thrust
 ******************************************/
bool Lander::canThrust() {
	if (isAlive() && !isLanded() && getFuel() > 0)
		return true;
	else
		return false;
}

/*******************************************
 * LANDER setPoint
 * Will set point
 ******************************************/
void Lander::setPoint(Point point) {
	this->point = point;
}

/*******************************************
 * LANDER setVelocity
 * Will set velocity
 ******************************************/
void Lander::setVelocity(Velocity velocity) {
	this->velocity = velocity;
}

/*******************************************
 * LANDER setLanded
 * Will set landed
 ******************************************/
void Lander::setLanded(bool landed) {
	this->landed = landed;
}

/*******************************************
 * LANDER setAlive
 * Will set alive
 ******************************************/
void Lander::setAlive(bool alive) {
	this->alive = alive;
}

/*******************************************
 * LANDER setFuel
 * Will set fuel
 ******************************************/
void Lander::setFuel(int fuel) {
	this->fuel = fuel;
}

/*******************************************
 * LANDER applyGravity
 * Will set the gravity
 ******************************************/
void Lander::applyGravity(float gravity) {
	velocity.setDy(velocity.getDy() - gravity);
}

/*******************************************
 * LANDER applyThrustLeft
 * Will set the left thrust
 ******************************************/
void Lander::applyThrustLeft() {
	if (fuel > 0)
	{
		velocity.setDx(velocity.getDx() + 0.1);
		setFuel(fuel - 1);
		drawLanderFlames(point, false, true, false); //Draws the flames for the lander at any direction set to true
	}
}

/*******************************************
 * LANDER applyThrustRight
 * Will set the right thrust
 ******************************************/
void Lander::applyThrustRight() {
	if (fuel > 0)
	{
		velocity.setDx(velocity.getDx() - 0.1);
		setFuel(fuel - 1);
		drawLanderFlames(point, false, false, true); //Draws the flames for the lander at any direction set to true
	}
}

/*******************************************
 * LANDER applyThrustBottom
 * Will set the bottom thrust
 ******************************************/
void Lander::applyThrustBottom() {
	if (fuel >= 3)
	{
		velocity.setDy(velocity.getDy() + 0.3);
		setFuel(fuel - 3);
		drawLanderFlames(point, true, false, false); //Draws the flames for the lander at any direction set to true
	}
}

/*******************************************
 * LANDER advance
 * Advance the game, make the lander move
 ******************************************/
void Lander::advance() {
	point.setX(point.getX() + velocity.getDx());
	point.setY(point.getY() + velocity.getDy());
}

/*******************************************
 * LANDER draw
 * Draws the lander on the screen
 ******************************************/
void Lander::draw() {
	drawLander(point);
}
