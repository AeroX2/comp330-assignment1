/*
 * Fire.cpp
 *
 *  Created on: 23 Mar. 2018
 *      Author: James Ridey
 */

#include "fire.hpp"

int layer_sizes[][2] = {{30,50},{20,30},{0,10}};
int layer_colors[][3] = {{255,0,0},{255,165,0},{255,255,255}};

Fire::Fire(Vector position, Vector size) : Entity(position, size) {
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
	for (int i = 0; i < sizeof(layers)/sizeof(layers[0]); i++) {
		layers[i].clear();
		for (int ii = 0; ii < 360; ii++) {
			float radius = Utils::random_range_int(layer_sizes[i][0], layer_sizes[i][1]);
			layers[i].push_back(radius);
		}
	}
}

void Fire::redraw() {
	Entity::redraw();

	for (int i = 0; i < sizeof(layers)/sizeof(layers[0]); i++) {
		glColor3ub(layer_colors[i][0],layer_colors[i][1],layer_colors[i][2]);
		glBegin(GL_TRIANGLE_FAN);
			for (int ii = 0; ii < 360; ii++) {
				float radius = layers[i][ii];
				float degInRad = ii*M_PI/180;
				glVertex2f(cos(degInRad)*radius,sin(degInRad)*radius);
			}
		glEnd();
	}

}
