/*
 * Helicopter.cpp
 *
 *  Created on: 10 Mar. 2018
 *      Author: James Ridey (44805632)
 */

#include "helicopter.hpp"
#include "../utils.hpp"

Helicopter::Helicopter() : Entity(Vector(INITIAL_WINDOW_WIDTH / 2, INITIAL_WINDOW_HEIGHT / 2), Vector(25, 25)) {
    debug("Creating helicopter object");

    filling = false;
    stop = true;

    water = 0;
    bladeAngle = 0;

    target = Vector(INITIAL_WINDOW_WIDTH / 2, INITIAL_WINDOW_HEIGHT / 2);
}

void Helicopter::update() {
    Entity::update();

    //Spin the helicopter blades
    bladeAngle += HELICOPTER_BLADE_SPIN_RATE;

    if (!stop) {
        //Steer towards the current point
        //Based of the code found on: https://www.askforgametask.com/tutorial/steering-behaviors-seek/
        Vector desired_velocity = (target - position).normalise() * HELICOPTER_MAX_SPEED;
        Vector steering = (desired_velocity - velocity).limit(HELICOPTER_MAX_FORCE);
        velocity = (velocity + steering).limit(HELICOPTER_MAX_SPEED);
        rotation = velocity.angle() - 90;
    } else {
        //Slow down helicopter after last point
        velocity *= 0.95f;
    }

    //Fill up with water until the max
    if (filling && water <= HELICOPTER_MAX_WATER) {
        water += HELICOPTER_WATER_FILL_RATE;
    } else {
        filling = false;
    }
}

void Helicopter::redraw() {
    Entity::redraw();

    //Set the color white
    glColor4ub(255, 255, 255, 250);

    //Draw the helicopter body
    glRectf(-size.x / 2, -size.y / 2, size.x / 2, size.y / 2);
    //And tail
    glRecti(-3, -50, 3, 0);

    //Draw the helicopter blade
    glPushMatrix();
        glRotatef(bladeAngle, 0, 0, 1);
        glRecti(-3, -40, 3, 40);
        glRecti(-40, -3, 40, 3);
    glPopMatrix();

    //Draw the filling indicator
    if (filling) {
        glPushMatrix();
        glRotatef(-bladeAngle * 1.5, 0, 0, 1);
        glColor3ub(0, 0, 255);
        Utils::draw_arc(size.x / 2, 0, 270);
        glPopMatrix();
    }

    //This is deliberate, we are popping out of the
    //entity matrix and drawing on the screen instead
    glPopMatrix();
        glPushMatrix();
            glLoadIdentity();

            //Draw water meter
            glColor3ub(0, 0, 0);
            glRasterPos2i(65, 10);
            glutBitmapString(GLUT_BITMAP_HELVETICA_12, reinterpret_cast<const unsigned char *>("Water meter"));

            glColor3ub(0, 0, 255);
            glRectf(10, 10, 60, 15 + 300 * (water / HELICOPTER_MAX_WATER));
        glPopMatrix();
    glPushMatrix();
}

/*
 * Set the target to fly towards
 */
void Helicopter::set_target(Vector target) {
    this->target = target;
}

/*
 * If there is no target left, stop should be true
 * Otherwise this should be set to true
 */
void Helicopter::set_stop(bool stop) {
    this->stop = stop;
}

/*
 * Set if the helicopter is filling up with water or not
 */
void Helicopter::set_filling(bool filling) {
    this->filling = filling;
}

/*
 * Get the amount of water the helicopter is holding
 */
float &Helicopter::get_water() {
    return water;
}
