/*
 * constants.hpp
 *
 *  Created on: 10 Mar. 2018
 *      Author: James Ridey
 */

#ifndef CONSTANTS_HPP_
#define CONSTANTS_HPP_

#define debug(x) std::cout << x << std::endl

const static long CLOCKS_PER_SEC = 1000000;
const static double FRAME_RATE = 1/60.0f;

static int WINDOW_WIDTH = 1000;
static int WINDOW_HEIGHT = 750;

#define HOUSE1_PARAMETERS Vector(50,100),Vector(50,30),30
#define HOUSE2_PARAMETERS Vector(200,300),Vector(100,80),40
#define HOUSE3_PARAMETERS Vector(400,150),Vector(60,20),20

const static float HELICOPTER_SPIN_RATE = 10.0f;

#endif /* CONSTANTS_HPP_ */
