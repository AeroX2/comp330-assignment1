/*
 * Lake.hpp
 *
 *  Created on: 23 Mar. 2018
 *      Author: James Ridey (44805632)
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
        bool check_collision(Entity entity);
};

#endif /* ENTITIES_FIRE_HPP_ */
