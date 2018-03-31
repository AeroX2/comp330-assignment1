/*
 * Lake.hpp
 *
 *  Created on: 23 Mar. 2018
 *      Author: James Ridey
 */

#ifndef ENTITIES_SPLASH_HPP_
#define ENTITIES_SPLASH_HPP_

#include <vector>

#include "../constants.hpp"
#include "../utils.hpp"
#include "entity.hpp"

class Splash : public Entity {
	public:
		Splash(Vector position, Vector size);
		void redraw();
};

#endif /* ENTITIES_SPLASH_HPP_ */
