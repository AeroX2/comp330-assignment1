/*
 * Lake.cpp
 *
 *  Created on: 23 Mar. 2018
 *      Author: James Ridey (44805632)
 */

#include "splash.hpp"
#include "fire.hpp"

Splash::Splash(Vector position, Vector size) : Entity(position, size) {
    debug("Creating splash object");
    fire = nullptr;
    opacity = 100;
    time_elapsed = glutGet(GLUT_ELAPSED_TIME);
}

void Splash::update() {
    Entity::update();

    int current_time = glutGet(GLUT_ELAPSED_TIME);
    if ((current_time - time_elapsed) >= SPLASH_PERSISTENCE_TIME) {
        size.x *= 0.99;
        opacity *= 0.99;
    }
}

void Splash::redraw() {
    Entity::redraw();

    glColor4ub(0, 0, 125, opacity);
    Utils::draw_circle(size.x);

    if (fire == nullptr) return;
    glPushMatrix();
        //Draw the blackened earth part of the splash
        glColor3b(0,0,0);
        glBegin(GL_POLYGON);
            for (int i = 0; i < 360; i++) {
                float x = cos(i*PI/180) * size.y;
                float y = sin(i*PI/180) * size.y;

                //If the point is inside the inner fire ring, recalculate the point
                //from the fire ring "point of view"
                Vector v = (position + Vector(x,y)) - fire->position;
                float a = v.angle() * PI / 180;
                bool inside_inner_ring = v.fake_distance() < fire->size.x*fire->size.x;
                bool inside_outer_ring = v.fake_distance() < fire->size.y*fire->size.y;

                if (inside_inner_ring) {
                    x = -position.x + fire->position.x + cos(a) * Fire::layer_sizes[fire->layer_size-1][0];
                    y = -position.y + fire->position.y + sin(a) * Fire::layer_sizes[fire->layer_size-1][0];
                } else if (!inside_outer_ring) {
                    x = -position.x + fire->position.x + cos(a) * Fire::layer_sizes[0][1];
                    y = -position.y + fire->position.y + sin(a) * Fire::layer_sizes[0][1];
                }

                glVertex2d(x, y);
            }
        glEnd();
    glPopMatrix();
}

void Splash::check_collision(Fire* fire) {
    float d = (position - fire->position).distance();
    bool collision_inner_ring = d < fire->size.x+size.y && d > fire->size.x-size.y;
    bool collision_outer_ring = d < fire->size.y+size.y;

    //Check and see if we found an intersection
    if (collision_inner_ring || collision_outer_ring) {
        this->fire = fire;
    }
}
