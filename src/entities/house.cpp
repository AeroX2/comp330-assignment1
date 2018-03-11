/*
 * house.cpp
 *
 *  Created on: 10 Mar. 2018
 *      Author: James Ridey
 */

#include "house.hpp"

House::House(Vector position, Vector size, int peak) :
		Entity(position), size(size), peak(peak) {
}

void House::redraw() {
	Vector bottom_left = position;
    Vector top_left = Vector(bottom_left.x, bottom_left.y+size.y);
    Vector top_right = Vector(bottom_left.x+size.x, bottom_left.y+size.y);

	glRecti(bottom_left.x, bottom_left.y, top_right.x, top_right.y);
	glBegin(GL_POLYGON);
	  glVertex2i(top_left.x, top_left.y);
	  glVertex2i(top_left.x+size.x/2,top_left.y+peak);
	  glVertex2i(top_right.x, top_right.y);
	glEnd();
}
