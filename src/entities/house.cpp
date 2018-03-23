/*
 * house.cpp
 *
 *  Created on: 10 Mar. 2018
 *      Author: James Ridey
 */

#include "house.hpp"

House::House(Vector position, Vector size, int peak) :
		Entity(position, size), peak(peak) {
}

void House::redraw() {
	Entity::redraw();

	glRecti(-size.x/2, -size.y/2, size.x/2, size.y/2);
	glBegin(GL_POLYGON);
	  glVertex2i(-size.x/2, size.y/2);
	  glVertex2i(0,size.y/2+peak);
	  glVertex2i(size.x/2, size.y/2);
	glEnd();
}
