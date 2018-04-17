/*
 * Lake.hpp
 *
 *  Created on: 23 Mar. 2018
 *      Author: James Ridey (44805632)
 */

#ifndef ENTITIES_SPLASH_HPP_
#define ENTITIES_SPLASH_HPP_

#include <vector>

#include "../constants.hpp"
#include "../utils.hpp"
#include "entity.hpp"
#include "fire.hpp"

class Splash : public Entity {
    public:
        Splash(Vector position, Vector size);
        void update();
        void redraw();
        void check_collision(Fire* fire);
    private:
        int time_elapsed;
        float opacity;

        Fire* fire;
        pair<Vector, Vector> intersection_points;
        pair<float, float> splash_angles;
        pair<float, float> fire_angles;
};

#endif /* ENTITIES_SPLASH_HPP_ */
