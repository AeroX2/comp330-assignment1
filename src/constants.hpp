/*
 * constants.hpp
 *
 *  Created on: 10 Mar. 2018
 *      Author: James Ridey
 */

#ifndef CONSTANTS_HPP_
#define CONSTANTS_HPP_

#define debug(x) std::cout << x << std::endl

const static double M_PI = 3.14159265358979323846264338327950288;
const static long CLOCKS_PER_SEC = 1000000;
const static double FRAME_RATE = 1/60.0f;

const int INITIAL_WINDOW_WIDTH = 1000;
const int INITIAL_WINDOW_HEIGHT = 750;

extern int WINDOW_WIDTH;
extern int WINDOW_HEIGHT;

#define HOUSE1_PARAMETERS Vector(350,400),Vector(50,30),30
#define HOUSE2_PARAMETERS Vector(500,600),Vector(100,80),40
#define HOUSE3_PARAMETERS Vector(700,450),Vector(60,20),20

#define FIRE1_PARAMETERS Vector(50,60),Vector(0,0)
#define FIRE2_PARAMETERS Vector(800,600),Vector(0,0)
#define FIRE3_PARAMETERS Vector(200,700),Vector(0,0)

#define LAKE_PARAMETERS Vector(750,-80),Vector(0,0)

const static float HELICOPTER_SPIN_RATE = 10.0f;
const static int FIRE_TICK_OVER = 2;

#endif /* CONSTANTS_HPP_ */
