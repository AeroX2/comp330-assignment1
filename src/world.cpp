/*
 * world.cpp
 *
 *  Created on: 10 Mar. 2018
 *      Author: James Ridey
 */

#include "world.hpp"
#include "constants.hpp"

World::World() :
	house1(HOUSE1_PARAMETERS),
	house2(HOUSE2_PARAMETERS),
	house3(HOUSE3_PARAMETERS) {}

void World::init() {
	entities.push_back(&helicopter);
	entities.push_back(&house1);
	entities.push_back(&house2);
	entities.push_back(&house3);
}

void World::update() {
	for (int i = 0; i < entities.size(); i++) {
		entities[i]->update();
	}
}

void World::redraw() {
	for (int i = 0; i < entities.size(); i++) {
		entities[i]->redraw();
	}
}

