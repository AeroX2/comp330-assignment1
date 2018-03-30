/*
 * Entity.hpp
 *
 *  Created on: 10 Mar. 2018
 *      Author: James Ridey
 */

#ifndef ENTITIES_ENTITY_HPP_
#define ENTITIES_ENTITY_HPP_

#include <GL/freeglut.h>
#include "vector.hpp"

class Entity {
	public:
		Entity(Vector position, Vector size);
		virtual ~Entity() {};

		virtual void update();
		virtual void redraw();
	protected:
		//Position vector
		Vector position;
		//Velocity vector
		Vector velocity;
		//Size vector
		Vector size;

		//Rotation angle in degrees
		double rotation;
		//Rotation velocity
		double rotationVelocity;
};

#endif /* ENTITIES_ENTITY_HPP_ */
