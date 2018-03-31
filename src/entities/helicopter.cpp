/*
 * Helicopter.cpp
 *
 *  Created on: 10 Mar. 2018
 *      Author: James Ridey
 */

#include "helicopter.hpp"

Helicopter::Helicopter() : Entity(Vector(INITIAL_WINDOW_WIDTH/2, INITIAL_WINDOW_HEIGHT/2), Vector(25,25)) {
    stop = true;
	bladeAngle = 0.0f;
    target = Vector(INITIAL_WINDOW_WIDTH/2, INITIAL_WINDOW_HEIGHT/2);
}

void Helicopter::update() {
    Entity::update();

    //Spin the helicopter blades
    bladeAngle += HELICOPTER_BLADE_SPIN_RATE;

    if (!stop) {
        //Steer towards the current point
        Vector desired_velocity = (target - position).normalise() * HELICOPTER_MAX_SPEED;
        Vector steering = (desired_velocity - velocity).limit(HELICOPTER_MAX_FORCE);
        velocity = (velocity + steering).limit(HELICOPTER_MAX_SPEED);
        rotation = velocity.angle() - 90;
    } else {
        //Slow down helicopter after last point
        velocity *= 0.95f;
    }

}

void Helicopter::redraw() {
	Entity::redraw();

    //Set the color white
    glColor3f(1,1,1);

    //Draw the helicopter body
    glRectf(-size.x/2,-size.y/2,size.x/2,size.y/2);
    //And tail
    glRecti(-3,-50,3,0);

    //Draw the helicopter blade
    glPushMatrix();
        glRotatef(bladeAngle,0,0,1);
        glRecti(-3,-40,3,40);
        glRecti(-40,-3,40,3);
    glPopMatrix();
}

void Helicopter::set_target(Vector target) {
	this->target = target;
}

void Helicopter::set_stop(bool stop) {
    this->stop = stop;
}
