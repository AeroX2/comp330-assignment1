/*
 * Helicopter.cpp
 *
 *  Created on: 10 Mar. 2018
 *      Author: James Ridey
 */

#include "helicopter.hpp"
#include "../constants.hpp"

Helicopter::Helicopter() : Entity(Vector(WINDOW_WIDTH/2,WINDOW_HEIGHT/2), Vector(25,25)) {
	bladeAngle = 0.0f;
}

void Helicopter::update() {
	bladeAngle += HELICOPTER_SPIN_RATE;
}

void Helicopter::redraw() {
	glTranslatef(position.x, position.y, 0);
	glRecti(-size.x/2,-size.y/2,size.x/2,size.y/2);
	glRecti(-3,-50,3,0);

	glPushMatrix();
		glRotatef(bladeAngle,0,0,1);
		glRecti(-3,-40,3,40);
		glRecti(-40,-3,40,3);
	glPopMatrix();
}
