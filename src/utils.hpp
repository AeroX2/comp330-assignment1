#ifndef UTILS_H
#define UTILS_H

//Problem with GLUT_ELAPSED_TIME
//#include <time.h>
#include <GL/glut.h>
#include <cmath>
#include <random>

#include "constants.hpp"
#include "entities/vector.hpp"

using namespace std;

class Utils {
    public:
        static mt19937 &random_engine();
        static float random_range_float(float min, float max);
        static int random_range_int(int min, int max);
        static float random_normalised();
        static float random_clamped();
        static float constrain(float num, float min, float max);

        static void draw_arc(float position, int radius, int start_degree);
        static void draw_circle(float radius);

        static pair<Vector, Vector> circle_intersection(Vector p0, float r0, Vector p1, float r1);
};

#endif
