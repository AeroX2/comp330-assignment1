/*
 * world.hpp
 *
 *  Created on: 10 Mar. 2018
 *      Author: James Ridey (44805632)
 */

#ifndef WORLD_HPP_
#define WORLD_HPP_

#include <GL/freeglut.h>
#include <cstdio>
#include <vector>
#include <queue>

#include "constants.hpp"
#include "entities/vector.hpp"
#include "entities/entity.hpp"
#include "entities/helicopter.hpp"
#include "entities/house.hpp"
#include "entities/fire.hpp"
#include "entities/lake.hpp"

using namespace std;

class World {
    public:
        World();
        void init();
        void update();
        void redraw();
        void mouse_point(int x, int y);
        void mouse_click(int x, int y);

		void toggle_looping();
        void reset();
		void clear_mouse_points();
	private:
        int fps;
        int frameCounter;
        int previousFPSTime;
        int previousClickTime;

        bool filling_mode;
        bool looping;

        Helicopter helicopter;
		Helicopter fake_helicopter;

		Fire fire;
		Lake lake;

        House house1;
        House house2;
        House house3;

        vector<Entity *> entities;
        vector<Vector> mouse_points;

};

#endif /* WORLD_HPP_ */
