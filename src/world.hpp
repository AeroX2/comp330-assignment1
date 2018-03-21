/*
 * world.hpp
 *
 *  Created on: 10 Mar. 2018
 *      Author: James Ridey
 */

#ifndef WORLD_HPP_
#define WORLD_HPP_

#include <vector>

#include "constants.hpp"
#include "entities/vector.hpp"
#include "entities/entity.hpp"
#include "entities/helicopter.hpp"
#include "entities/sesbase.hpp"
#include "entities/house.hpp"

using namespace std;

class World {
	public:
		World();
		void init();
		void update();
		void redraw();
	private:
		int fps;
		int frameCounter;
		int previousTime;

		Helicopter helicopter;
		House house1;
		House house2;
		House house3;

		vector<Entity*> entities;
};

#endif /* WORLD_HPP_ */
