###############################################################
# Program:
#     Project 07, Moon Lander
#     Brother Comeau, CS165
# Author:
#     Leonardo Santos
# Summary:
#     MoonLander Game where the user controls the lander 
#     using the keyboard. The objective of the game is to 
#     smoothly land in the plataform. . 
# Above and Beyond
#     Updated the font style, size, and color. Updated the title.
#     Updated the colors for lander and moutains.
#     Created a Fuel description.
#     Created messages for running out of fuel that blinks to
#     call the user's attention and a final message when 
#     there is no fuel left. Updated the positions for every
#     sentence in the game.
#     Created a interactive menu when the game starts so the
#     user can choose 1 to play the game and any other key to
#     quit the game.
#     Created instructions and hints on the menu before the game
#     starts and created a starting countdown when the user 
#     selects 1 to start the game and then the game window opens.
#     Created a stylish title for the menu in blue.
#     Created specific messages when the user crash the lander
#     into the platform and changed its color and position.
#     The start menu was set up to create a rose after the
#     countdown is complete. Play again and you will see.
###############################################################


LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main Moon Lander game
###############################################################
a.out: driver.o ground.o game.o uiInteract.o uiDraw.o point.o lander.o velocity.o
	g++ driver.o ground.o game.o uiInteract.o uiDraw.o point.o lander.o velocity.o $(LFLAGS)
	tar -j -cf moonLander.tar makefile *.h *.cpp

###############################################################
# Individual files
#    uiDraw.o      Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o  Handles input events
#    point.o       The position on the screen
#    ground.o      Handles the ground / world
#    game.o        Handles the game interaction
###############################################################
uiDraw.o: uiDraw.cpp uiDraw.h
	g++ -c uiDraw.cpp

uiInteract.o: uiInteract.cpp uiInteract.h
	g++ -c uiInteract.cpp

point.o: point.cpp point.h
	g++ -c point.cpp

ground.o: ground.cpp ground.h
	g++ -c ground.cpp

game.o: game.h game.cpp uiDraw.h uiInteract.h point.h ground.h
	g++ -c game.cpp

driver.o: driver.cpp game.h uiInteract.h
	g++ -c driver.cpp

#######################################################################
# My Individual files
#	lander.o   Class for the lander, it controlls its movement,
#	           speed, gravity, draw, advance, and set the positions.
#	velocity.o Class that sets the velocity of the game.
#######################################################################
lander.o: lander.h lander.cpp velocity.h point.h
	g++ -c lander.cpp

velocity.o: velocity.h velocity.cpp
	g++ -c velocity.cpp

###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o *.tar
