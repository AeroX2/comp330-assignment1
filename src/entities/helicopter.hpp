/*
 * Helicopter.hpp
 *
 *  Created on: 10 Mar. 2018
 *      Author: James Ridey
 */

#ifndef ENTITIES_HELICOPTER_HPP_
#define ENTITIES_HELICOPTER_HPP_

#include "entity.hpp"

class Helicopter : public Entity {
	public:
		Helicopter();
		void update();
		void redraw();
	private:
		float bladeAngle;
};

#endif /* ENTITIES_HELICOPTER_HPP_ */
