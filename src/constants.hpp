/*
 * constants.hpp
 *
 *  Created on: 10 Mar. 2018
 *      Author: James Ridey (44805632)
 */

#ifndef CONSTANTS_HPP_
#define CONSTANTS_HPP_

#define debug(x) std::cout << (x) << std::endl

const int INITIAL_WINDOW_WIDTH = 1000;
const int INITIAL_WINDOW_HEIGHT = 750;

extern int WINDOW_WIDTH;
extern int WINDOW_HEIGHT;

const float M_PI = 3.141592;
const float FRAME_RATE = 1/60.0f;
const long CLOCKS_PER_SEC = 1000000;
const int DOUBLE_CLICK_TIME = 300;

const int MOUSE_POINT_DISTANCE = 100;
const int HELICOPTER_POINT_DISTANCE = 30;

const float SPLASH_WATER_AMOUNT = 10.0f;
const int SPLASH_PERSISTENCE_TIME = 16000;

const float HELICOPTER_MAX_SPEED = 5.0f;
const float HELICOPTER_MAX_FORCE = 0.3f;
const float HELICOPTER_MAX_WATER = 50.0f;
const float HELICOPTER_BLADE_SPIN_RATE = 10.0f;
const float HELICOPTER_WATER_FILL_RATE = 0.1f;
const int FIRE_TICK_OVER = 2;

#define MENU_EXIT 0

#define HOUSE1_PARAMETERS Vector(450,260),Vector(70,50),55
#define HOUSE2_PARAMETERS Vector(450,470),Vector(100,80),74
#define HOUSE3_PARAMETERS Vector(650,350),Vector(80,40),52

#define FIRE1_PARAMETERS Vector(50,60),Vector(0,0)
#define FIRE2_PARAMETERS Vector(800,600),Vector(0,0)
#define FIRE3_PARAMETERS Vector(200,700),Vector(0,0)

#define LAKE_PARAMETERS Vector(850,-80),Vector(0,0)

#endif /* CONSTANTS_HPP_ */
