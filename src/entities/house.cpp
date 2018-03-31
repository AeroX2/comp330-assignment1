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

	glRectf(-size.x/2, -size.y/2, size.x/2, size.y/2);
	glBegin(GL_POLYGON);
	  glVertex2f(-size.x/2, size.y/2);
	  glVertex2f(0,size.y/2+peak);
	  glVertex2f(size.x/2, size.y/2);
	glEnd();
}
