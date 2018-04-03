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

/*
 * Super update method
 * Clear velocities if they are close to zero
 * and update position, rotation
 */
void Entity::update() {
    if (velocity.x > -0.01 && velocity.x < 0.01) velocity.x = 0;
    if (velocity.y > -0.01 && velocity.y < 0.01) velocity.y = 0;
    if (rotationVelocity > -0.01 && rotationVelocity < 0.01) rotationVelocity = 0;

    rotation += rotationVelocity;
    position += velocity;
}

/*
 * Super redraw method
 * Draws the entity at a specified position
 * and rotates it
 */
void Entity::redraw() {
    glTranslatef(position.x, position.y, 0);
    glRotatef(rotation, 0, 0, 1);
}
