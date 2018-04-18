/*
 * Fire.hpp
 *
 *  Created on: 23 Mar. 2018
 *      Author: James Ridey (44805632)
 */

#ifndef ENTITIES_FIRE_HPP_
#define ENTITIES_FIRE_HPP_

#include <vector>

#include "../constants.hpp"
#include "../utils.hpp"
#include "entity.hpp"

class Fire : public Entity {
    public:
        Fire(Vector position, Vector size);
        void update();
        void redraw();
        void new_fire();

        int layer_size;
        static int layer_sizes[][2];
        static unsigned char layer_colors[][3];
    private:
        int ticks;

        //3 separate layers of "random" circles for the fire
        vector<int> layers[4];
};

#endif /* ENTITIES_FIRE_HPP_ */
