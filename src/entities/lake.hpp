/*
 * Lake.hpp
 *
 *  Created on: 23 Mar. 2018
 *      Author: James Ridey
 */

#ifndef ENTITIES_LAKE_HPP_
#define ENTITIES_LAKE_HPP_

#include <vector>

#include "../constants.hpp"
#include "../utils.hpp"
#include "entity.hpp"

class Lake : public Entity {
	public:
		Lake(Vector position, Vector size);
		void redraw();
};

#endif /* ENTITIES_FIRE_HPP_ */
