#pragma once
#include "uiDraw.h"
#include "uiInteract.h"

class Velocity
{
private:
	float x;
	float y;

public:
	//Constructors
	Velocity();
	Velocity(float x, float y);

	//Getters
	float getDx() const;
	float getDy() const;
		
	//Setters
	void setDx(float x);
	void setDy(float y);
	
};

