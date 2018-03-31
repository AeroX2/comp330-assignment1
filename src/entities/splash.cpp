/*
 * Lake.cpp
 *
 *  Created on: 23 Mar. 2018
 *      Author: James Ridey (44805632)
 */

#include "splash.hpp"

Splash::Splash(Vector position, Vector size) : Entity(position, size) {
}

void Splash::redraw() {
	Entity::redraw();

	glColor4ub(0,0,0,102);
	Utils::draw_circle(50);
}
