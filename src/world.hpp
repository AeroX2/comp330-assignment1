/*
 * world.hpp
 *
 *  Created on: 10 Mar. 2018
 *      Author: James Ridey
 */

#ifndef WORLD_HPP_
#define WORLD_HPP_

#include <vector>

#include "entity.hpp"
#include "helicopter.hpp"
#include "sesbase.hpp"
#include "house.hpp"

using namespace std;

class World {
	public:
		void init();
		void update();
		void redraw();
	private:
		Helicopter helicopter;
		vector<Entity*> entities;
};

#endif /* WORLD_HPP_ */
