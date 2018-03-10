/*
 * world.cpp
 *
 *  Created on: 10 Mar. 2018
 *      Author: James Ridey
 */

#include "world.hpp"
#include "constants.hpp"

void World::init() {
	House house1(HOUSE1_PARAMETERS);
	House house2(HOUSE2_PARAMETERS);
	House house3(HOUSE3_PARAMETERS);

	entities.push_back(&helicopter);
	entities.push_back(&house1);
	entities.push_back(&house2);
	entities.push_back(&house3);
}

void World::update() {
	for (Entity* entity : entities) {
		entity->update();
	}
}

void World::redraw() {
	for (Entity* entity : entities) {
		entity->redraw();
	}
}

