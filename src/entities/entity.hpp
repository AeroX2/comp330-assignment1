/*
 * Entity.hpp
 *
 *  Created on: 10 Mar. 2018
 *      Author: James Ridey (44805632)
 */

#ifndef ENTITIES_ENTITY_HPP_
#define ENTITIES_ENTITY_HPP_

#include <GL/freeglut.h>
#include "vector.hpp"

class Entity {
	public:
		explicit Entity(Vector position, Vector size);

		virtual void update();
		virtual void redraw();

		//Position vector
		Vector position;
		//Velocity vector
		Vector velocity;
        //Acceleration vector
        Vector acceleration;
		//Size vector
		Vector size;

		//Rotation angle in degrees
		float rotation;
		//Rotation velocity
		float rotationVelocity;
};

#endif /* ENTITIES_ENTITY_HPP_ */
