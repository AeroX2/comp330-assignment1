/*
 * Fire.cpp
 *
 *  Created on: 23 Mar. 2018
 *      Author: James Ridey (44805632)
 */

#include "fire.hpp"

int layer_sizes[][2] = {{30, 50},
                        {20, 30},
                        {0,  10}};
unsigned char layer_colors[][3] = {{255, 0,   0},
                                   {255, 165, 0},
                                   {255, 255, 255}};

Fire::Fire(Vector position, Vector size) : Entity(position, size) {
    debug("Creating fire object");
    ticks = 0;
    new_fire();
}

void Fire::update() {
    if (ticks++ > FIRE_TICK_OVER) {
        ticks = 0;
        new_fire();
    }
}

void Fire::new_fire() {
    for (auto &layer : layers) {
        layer.clear();
        for (int ii = 0; ii < 360; ii++) {
            int radius = size.y; //Utils::random_range_int(layer_sizes[i][0], layer_sizes[i][1]);
            layer.push_back(radius);
        }
    }
}

void Fire::redraw() {
    Entity::redraw();

    //Can't use Utils::draw_circle for this because radius keeps changing
    for (auto &layer : layers) {
        //glColor3ub(layer_colors[i][0], layer_colors[i][1], layer_colors[i][2]);
        glColor3ub(255,0,0);
        glBegin(GL_TRIANGLE_FAN);
            for (int ii = 0; ii < 360; ii++) {
                float radius = layer[ii];
                float degInRad = ii * PI / 180;
                glVertex2f(cos(degInRad) * radius, sin(degInRad) * radius);
            }
        glEnd();
        glColor4f(BACKGROUND_COLOR);
        glBegin(GL_TRIANGLE_FAN);
        for (int ii = 0; ii < 360; ii++) {
            float degInRad = ii * PI / 180;
            glVertex2f(cos(degInRad) * size.x, sin(degInRad) * size.x);
        }
        glEnd();
    }

}
