#pragma once
#include "point.h"
#include "velocity.h"
#include "uiDraw.h"
#include "uiInteract.h"

class Lander
{
private:
	bool landed;
	bool alive;
	bool thrust;
	int fuel;
	Point point;
	Velocity velocity;

public:
	//Constructors
	Lander();
		
	//Getters
	Point getPoint() const;
	Velocity getVelocity() const;
	bool isAlive() const;
	bool isLanded() const;
	int getFuel() const;
	
	//Setters
	void setLanded(bool landed);
	void setAlive(bool alive);
	void setFuel(int fuel);
	void setPoint(Point point);
	void setVelocity(Velocity velocity);
	
	//Something else
	bool canThrust();
	void applyGravity(float gravity);
	void applyThrustLeft();
	void applyThrustRight();
	void applyThrustBottom();
	void advance();
	void draw();
	
};

