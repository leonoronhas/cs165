/*****************************************************
 * File: Driver.cpp
 * Author: Br. Burton
 *
 * Description: This file contains the main function
 *  that starts the game and the callback function
 *  that specifies what methods of the game class are
 *  called each time through the game loop.
 ******************************************************/
#include "game.h"
#include "uiInteract.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>

/*********************************
 * wait is a function that will
 * set the time delay.
 *********************************/
void wait(int seconds)
{
   clock_t endwait;
   endwait = clock() + seconds * CLOCKS_PER_SEC;
   while (clock() < endwait) {}
}

/*********************************
 * getOption is a function that will
 * work as Welcome Menu for the game.
 * It provides 2 options to the user.
 *********************************/
void getOption() {
   //Block of colors
   const std::string red("\033[0;31m");
   const std::string green("\033[1;32m");
   const std::string yellow("\033[1;33m");
   const std::string cyan("\033[0;36m");
   const std::string magenta("\033[0;35m");
   const std::string reset("\033[0m");
	
   std::cout << "   " << std::endl << std::endl;
   wait(1);
   
   std::cout << cyan << "    _____                __              _         " << std::endl;
   std::cout << cyan << "   |     |___ ___ ___   |  |   ___ ___ _| |___ ___ " << std::endl;
   std::cout << cyan << "   | | | | . | . |   |  |  |__| .'|   | . | -_|  _|" << std::endl;
   std::cout << cyan << "   |_|_|_|___|___|_|_|  |_____|__,|_|_|___|___|_|  " << std::endl << std::endl;
   
   wait(2);
   std::cout << "\033[1;31m                  BY LEO SANTOS!   \033[0m\n"; //apply light red	
   wait(2);
   int option = 0;
   
   std::cout << "          PLEASE SELECT ANY OPTION BELOW:" << std::endl;
   std::cout << red << "            Press any other key to quit" << std::endl;
   std::cout << red << "               Press 1 to start game" << std::endl;
   std::cin >> option; 
    
   if (option == 1)
   {
      std::cout << green << "The game will open in 5 seconds in a separate window!" << std::endl;
      std::cout << green << "  HINT: Use the arrow keys to controle the Lander!" << std::endl;

      int n;
      std::cout << "                Starting countdown\n" << std::endl;
      for (n = 5; n > 0; n--) //countdown
      {
         std::cout << reset << std::setw(25) << n << std::endl;
         wait(1);
      }

      return;
   }
   else
      exit(0);
}

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface *pUI, void *p){
   Game *pGame = (Game *)p;
   
   pGame->advance();
   pGame->handleInput(*pUI);
   pGame->draw(*pUI);
}


/*********************************
 * Main is pretty sparse.  Just initialize
 * the game and call the display engine.
 * That is all!
 *********************************/
int main(int argc, char ** argv)
{
   getOption(); //MENU with option to play or quit program
     
   Point topLeft(-200, 200);
   Point bottomRight(200, -200);
      
   Interface ui(argc, argv, "Moon Lander by Leo Santos", topLeft, bottomRight);
   Game game(topLeft, bottomRight);

   ui.run(callBack, &game);

   return 0;
}
