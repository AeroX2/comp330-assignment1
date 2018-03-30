/*
 * Fire.hpp
 *
 *  Created on: 23 Mar. 2018
 *      Author: James Ridey
 */

#ifndef ENTITIES_FIRE_HPP_
#define ENTITIES_FIRE_HPP_

#include <vector>

#include "../constants.hpp"
#include "../utils.hpp"
#include "entity.hpp"

class Fire : public Entity {
	public:
		Fire(Vector position, Vector size);
		void update();
		void redraw();
		void new_fire();
	private:
		//3 separate layers of "random" circles for the fire
		vector<int> layers[3];

		int ticks;
};

#endif /* ENTITIES_FIRE_HPP_ */
