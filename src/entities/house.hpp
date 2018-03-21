/*
 * house.h
 *
 *  Created on: 10 Mar. 2018
 *      Author: James Ridey
 */

#ifndef ENTITIES_HOUSE_HPP_
#define ENTITIES_HOUSE_HPP_

#include "entity.hpp"

class House : public Entity {
	public:
		House(Vector position, Vector size, int peak);
		virtual ~House() {};

		void redraw();
	private:
		int peak;
};

#endif /* ENTITIES_HOUSE_HPP_ */
