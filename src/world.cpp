/*
 * world.cpp
 *
 *  Created on: 10 Mar. 2018
 *      Author: James Ridey
 */

#include <GL/freeglut.h>
#include <stdio.h>

#include "world.hpp"
#include "constants.hpp"

World::World() :
	house1(HOUSE1_PARAMETERS),
	house2(HOUSE2_PARAMETERS),
	house3(HOUSE3_PARAMETERS) {
	fps = 0;
	frameCounter = 0;
	previousTime = 0;
}

void World::init() {
	entities.push_back(&helicopter);
	entities.push_back(&house1);
	entities.push_back(&house2);
	entities.push_back(&house3);
}

void World::update() {
	//Update every entity
	for (Entity* entity : entities) {
		entity->update();
	}
}

void World::redraw() {
	//Calculate the current FPS
	int currentTime = glutGet(GLUT_ELAPSED_TIME);
	if ((currentTime-previousTime) >= 1000) {
		fps = frameCounter;
		frameCounter = 0;
		previousTime = currentTime;
	}
	frameCounter++;
	char tempString[50];
	snprintf(tempString, 50, "FPS: %d", fps);

	//And draw it
	glColor3f(1,1,1);
	glRasterPos2i(10, WINDOW_HEIGHT-30);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, reinterpret_cast<unsigned char*>(tempString));

	//Draw every entity
	for (Entity* entity : entities) {
		glPushMatrix();
			entity->redraw();
		glPopMatrix();
	}
}

