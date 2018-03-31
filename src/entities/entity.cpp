/*
 * Entity.cpp
 *
 *  Created on: 10 Mar. 2018
 *      Author: James Ridey (44805632)
 */

#include "entity.hpp"

Entity::Entity(Vector position, Vector size) : position(position), size(size) {
	rotation = 0;
	rotationVelocity = 0;
}

void Entity::update() {

//	if (!futureVelocity.isZero) {
//		velocity.set(futureVelocity)
//		futureVelocity.setZero()
//	}

	if (velocity.x > -0.01 && velocity.x < 0.01) velocity.x = 0;
	if (velocity.y > -0.01 && velocity.y < 0.01) velocity.y = 0;
	if (rotationVelocity > -0.01 && rotationVelocity < 0.01) rotationVelocity = 0;

//	rotationVelocity += angleAcceleration
	rotation += rotationVelocity;

	position += velocity;
    velocity += acceleration;
}

void Entity::redraw() {
	glTranslatef(position.x, position.y, 0);
    glRotatef(rotation, 0, 0, 1);
}
