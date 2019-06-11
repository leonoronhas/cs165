/*************************************************************
 * File: game.cpp
 * Author: Br. Burton
 *
 * Description: Contains the implementations of the
 *  method bodies for the game class.
 *
 * Please DO NOT share this code with other students from
 *  other sections or other semesters. They may not receive
 *  the same code that you are receiving.
 *************************************************************/

#include "game.h"

#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "ground.h"
#include "lander.h"


/******************************************
 * GAME :: JUST LANDED
 * Did we land successfully?
 ******************************************/
bool Game :: justLanded() const
{
   bool landed = false;
   
   Point platformCenter = ground.getPlatformPosition();
   int width = ground.getPlatformWidth();

   float xDiff = lander.getPoint().getX() - platformCenter.getX();
   float yDiff = lander.getPoint().getY() - platformCenter.getY();

   float margin = width / 2.0;
   
   if (fabs(xDiff) < margin)
   {
      // between edges
      if (yDiff < 4 && yDiff >= 0)
      {
         // right above it
         if (fabs(lander.getVelocity().getDx()) < 3 && fabs(lander.getVelocity().getDy()) < 3)
         {
            // we're there!
            landed = true;
         }
      }
   }
   
   return landed;
}

/***************************************
 * GAME :: ADVANCE
 * advance the game one unit of time
 ***************************************/
void Game :: advance()
{
   if (lander.isAlive() && !lander.isLanded())
   {
      // advance the lander
      lander.applyGravity(GRAVITY_AMOUNT);
      lander.advance();
   
      // check for crash
      if (!ground.isAboveGround(lander.getPoint()))
      {
         lander.setAlive(false);
      }
   
      // check for just landed
      if (justLanded())
      {
         lander.setLanded(true);
      }
   }

   /***************************************
   * GAME : TEST FOR CRASHES
   ****************************************/
   Point platformCenter = ground.getPlatformPosition();
   int width = ground.getPlatformWidth();

   float xDiff = lander.getPoint().getX() - platformCenter.getX();
   float yDiff = lander.getPoint().getY() - platformCenter.getY();

   float margin = width / 2.0;

   if (fabs(xDiff) < margin)
   {
	   // between edges
	   if (yDiff < 4 && yDiff >= -10)
	   {
		   // right above it but too fast
		   if (fabs(lander.getVelocity().getDx()) > 3 || fabs(lander.getVelocity().getDy()) > 3)
		   {
			   drawText(Point(-120.0, 120.0), "Too fast into the platform!", 1.0, 0.0, 0.0); //red
			   lander.setAlive(false);
		   }
	   }
   }
}

/***************************************
 * GAME :: HANDLE INPUT
 * accept input from the user
 ***************************************/
void Game :: handleInput(const Interface & ui)
{
   if (lander.isAlive() && !lander.isLanded())
   {
   
      if (ui.isDown())
      {
         lander.applyThrustBottom();
      }
      
      if (ui.isLeft())
      {
         lander.applyThrustLeft();
      }
      
      if (ui.isRight())
      {
         lander.applyThrustRight();
      }
   }
}

/*********************************************
 * GAME :: DRAW
 * Draw everything on the screen
 *********************************************/
void Game :: draw(const Interface & ui)
{
   lander.draw();

   drawText(Point(-200, 185), "FUEL", 1.0, 1.0, 1.0); //white
   
   //Give out warning messages about the fuel
   if (lander.getFuel() <= 250 && lander.getFuel() >= 150)
   {
	   static int count;     //static so it does not died after every call
	   if (count++ % 2 == 0) //make it blink fast
	   drawText(Point(-125, 180), "Less than half of fuel left!", 1.0 , 1.0, 0.0); //yellow
   }

   if (lander.isLanded())
   {
	   drawText(Point(-135, 140), "You have successfully landed!", 0.0, 1.0, 0.0); //green
   }

   if (lander.getFuel() == 0)
   {
	   drawText(Point(-120.0,0.0),"You ran out of fuel.. and", 1.0, 0.0, 0.0); //red
   }

   if (!lander.isAlive())
   {
	   drawText(Point(-80, 100), "You have crashed!", 1.0, 0.0, 0.0); //red
   }
	   
   if (lander.canThrust())
   {
      drawLanderFlames(lander.getPoint(), ui.isDown(), ui.isLeft(), ui.isRight());
   }
   
   Point fuelLocation;
   fuelLocation.setX(topLeft.getX() + 3);
   fuelLocation.setY(topLeft.getY() - 20);
   
   drawNumber(fuelLocation, lander.getFuel());

   //ask ground to draw itself
   ground.draw();
}

