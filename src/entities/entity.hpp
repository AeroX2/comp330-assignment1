/*
 * Entity.hpp
 *
 *  Created on: 10 Mar. 2018
 *      Author: James Ridey
 */

#ifndef ENTITIES_ENTITY_HPP_
#define ENTITIES_ENTITY_HPP_

#include <GL/glut.h>
#include "vector.hpp"

class Entity {
	public:
		Entity(Vector position);
		virtual ~Entity() {};

		virtual void update();
		virtual void redraw();
	protected:
		//Position vector
		Vector position;
		//Velocity vector
		Vector velocity;

		//Rotation angle in degrees
		double rotation;
		//Rotation velocity
		double rotationVelocity;
};

#endif /* ENTITIES_ENTITY_HPP_ */
