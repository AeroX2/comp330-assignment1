#include "utils.hpp"

mt19937 &Utils::random_engine() {
    static mt19937 engine{(unsigned int) 347};
    return engine;
}

/*
 * Generate a random float between min and max
 */
float Utils::random_range_float(float min, float max) {
    //Probably not such a great idea to recreate the distribution every time
    //But neither is using it incorrectly
    uniform_real_distribution<float> distribution{min, max};
    return distribution(random_engine());
}

/*
 * Generate a random int between min and max
 */
int Utils::random_range_int(int min, int max) {
    //Probably not such a great idea to recreate the distribution every time
    //But neither is using it incorrectly
    uniform_int_distribution<> distribution{min, max};
    return distribution(random_engine());
}

/*
 * Generate a random int between 0 and 1
 */
float Utils::random_normalised() {
    return random_range_float(0, 1);
}

/*
 * Generate a random int between -1 and 1
 */
float Utils::random_clamped() {
    return random_range_float(-1, 1);
}

float Utils::constrain(float num, float min, float max) {
    if (num < min)
        return min;
    if (num > max)
        return max;
    return num;
}

/*
 * Draw a arc with radius at the origin, starting at start_degree, ending at end_degree
 * Should be positioned with glTranslatef
 */
void Utils::draw_arc(float radius, int start_degree, int end_degree) {
    glBegin(GL_TRIANGLE_FAN);
        if (!(start_degree == 0 && end_degree == 360)) glVertex2f(0,0);
        for (int i = start_degree; i < end_degree; i++) {
            float degInRad = i * PI / 180;
            glVertex2f(cos(degInRad) * radius, sin(degInRad) * radius);
        }
    glEnd();
}

/*
 * Draw a circle with a radius at the origin
 * Should be positioned with glTranslatef
 */
void Utils::draw_circle(float radius) {
    Utils::draw_arc(radius, 0, 360);
}
