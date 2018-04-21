/*
 * Helicopter.cpp
 *
 *  Created on: 10 Mar. 2018
 *      Author: James Ridey (44805632)
 */

#include "helicopter.hpp"
#include "../utils.hpp"

int Helicopter::coords[][2] = {
      {23,0}, {23,1}, {21,2}, {19,4}, {16,5}, {9,7}, {-13,7}, {-14,5}, {-44,1}, {-56,1}, {-60,0},
      {-60,0}, {-56,-1}, {-44,-1}, {-14,-5}, {-13,-7}, {9,-7}, {16,-5}, {19,-4}, {21,-2}, {23,-1}, {23,0}
};

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
        Vector steering = (desired_velocity - velocity) .limit(HELICOPTER_MAX_FORCE);
        velocity = (velocity + steering).limit(HELICOPTER_MAX_SPEED);
        rotation = velocity.angle();
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

void Helicopter::draw_helicopter(bool fake) {
    Entity::redraw();

    //Set the color white
    glColor4ub(255, 255, 255, 250);

    //If this is a fake helicopter only draw the outline
    if (fake) {
        glLineWidth(2);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }

    glRecti(-8,-15,-10,15);
    glRecti(6,-15,8,15);
    glRecti(-15,-15,12,-13);
    glRecti(-15,15,12,13);

    glBegin(GL_TRIANGLE_FAN);
        for (auto coord : Helicopter::coords) {
            glVertex2f(coord[0], coord[1]);
        }
    glEnd();

    //Draw the helicopter blade
    glPushMatrix();
    glRotatef(fake ? 45 : bladeAngle, 0, 0, 1);
    glRecti(-3, -40, 3, 40);
    glRecti(-40, -3, 40, 3);
    glPopMatrix();

    if (fake) glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void Helicopter::redraw() {
    draw_helicopter(false);

    //Draw the filling indicator
    if (filling) {
        glPushMatrix();
        glRotatef(-bladeAngle * 1.5, 0, 0, 1);
        glColor3ub(0, 0, 255);
        Utils::draw_arc(size.x / 2, 0, 270);
        glPopMatrix();
    }
}

/*
 * Set the target to fly towards
 */
void Helicopter::set_target(Vector target) {
    this->target = target;
}

/*
 * Called the first time a target is set
 */
void Helicopter::set_start_target(Vector target) {
    this->target = target;
    velocity += Vector(cos(rotation*PI/180), sin(rotation*PI/180)) * HELICOPTER_MAX_SPEED;
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
