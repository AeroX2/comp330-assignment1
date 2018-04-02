/*
 * Helicopter.hpp
 *
 *  Created on: 10 Mar. 2018
 *      Author: James Ridey (44805632)
 */

#ifndef ENTITIES_HELICOPTER_HPP_
#define ENTITIES_HELICOPTER_HPP_

#include "../constants.hpp"
#include "entity.hpp"

class Helicopter : public Entity {
    public:
        Helicopter();
        void update();
        void redraw();
        void set_target(Vector target);
        void set_stop(bool stop);

        void set_filling(bool i);

        float &get_water();

    private:
        bool stop;
        bool filling;

        float water;
        float bladeAngle;

        Vector target;
};

#endif /* ENTITIES_HELICOPTER_HPP_ */
