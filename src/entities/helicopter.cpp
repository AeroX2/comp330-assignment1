/*
 * Helicopter.cpp
 *
 *  Created on: 10 Mar. 2018
 *      Author: James Ridey
 */

#include "helicopter.hpp"

Helicopter::Helicopter() : Entity(Vector(WINDOW_WIDTH/2,WINDOW_HEIGHT/2), Vector(25,25)) {
	bladeAngle = 0.0f;
}

void Helicopter::update() {
	bladeAngle += HELICOPTER_BLADE_SPIN_RATE;
}

void Helicopter::redraw() {
	Entity::redraw();

	//Draw the helicopter body
	glRecti(-size.x/2,-size.y/2,size.x/2,size.y/2);
	//And tail
	glRecti(-3,-50,3,0);

	//Draw the helicopter blade
	glPushMatrix();
		glRotatef(bladeAngle,0,0,1);
		glRecti(-5,-40,5,40);
	glPopMatrix();
}
