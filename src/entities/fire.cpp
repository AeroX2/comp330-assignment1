/*
 * Fire.cpp
 *
 *  Created on: 23 Mar. 2018
 *      Author: James Ridey (44805632)
 */

#include "fire.hpp"

int Fire::layer_sizes[][2] = {{300, 320},
                        {280, 300},
                        {250, 270},
                        {230, 240}};
unsigned char Fire::layer_colors[][3] = {{255, 0,   0},
                                   {255, 165, 0},
                                   {255, 255, 255}};

Fire::Fire(Vector position, Vector size) : Entity(position, size) {
    debug("Creating fire object");

    layer_size = sizeof(layers)/sizeof(layers[0]);
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
    for (int i = 0; i < layer_size; i++) {
        layers[i].clear();
        for (int ii = 0; ii < 360; ii++) {
            int radius = Utils::random_range_int(layer_sizes[i][0], layer_sizes[i][1]);
            layers[i].push_back(radius);
        }
    }
}

void Fire::redraw() {
    Entity::redraw();

    //Can't use Utils::draw_circle for this because radius keeps changing
    for (int i = 0; i < layer_size-1; i++) {
        glColor3ub(layer_colors[i][0], layer_colors[i][1], layer_colors[i][2]);
        glBegin(GL_TRIANGLE_FAN);
            for (int ii = 0; ii < 360; ii++) {
                float radius = layers[i][ii];
                float degInRad = ii * PI / 180;
                glVertex2f(cos(degInRad) * radius, sin(degInRad) * radius);
            }
        glEnd();
    }

    glColor4f(BACKGROUND_COLOR);
    glBegin(GL_TRIANGLE_FAN);
        for (int ii = 0; ii < 360; ii++) {
            float radius = layers[layer_size-1][ii];
            float degInRad = ii * PI / 180;
            glVertex2f(cos(degInRad) * radius, sin(degInRad) * radius);
        }
    glEnd();
}
