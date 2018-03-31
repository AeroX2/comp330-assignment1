/*
 * Lake.cpp
 *
 *  Created on: 23 Mar. 2018
 *      Author: James Ridey (44805632)
 */

#include "splash.hpp"

Splash::Splash(Vector position, Vector size) : Entity(position, size) {
    opacity = 100;
    time_elapsed = glutGet(GLUT_ELAPSED_TIME);
}

void Splash::update() {
    Entity::update();

    int current_time = glutGet(GLUT_ELAPSED_TIME);
    if ((current_time-time_elapsed) >= 800) {
        size *= 0.99;
        opacity *= 0.99;
    }
}

void Splash::redraw() {
	Entity::redraw();

	glColor4ub(0,0,125,opacity);
    Utils::draw_circle(size.x);
}
