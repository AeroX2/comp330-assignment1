#include "utils.hpp"
#include "entities/vector.hpp"

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

/*
 * Circle intersection code based off
 * http://paulbourke.net/geometry/circlesphere/tvoght.c
 */
pair<Vector,Vector> Utils::circle_intersection(Vector p0, float r0, Vector p1, float r1) {
    //Check if an intersection exists
    float d = (p0 - p1).distance();
    if (d > r0+r1) return {};
    if (d < fabs(r0-r1)) return {};

    //Determine the distance from point 0 to point 2.
    float a = ((r0*r0) - (r1*r1) + (d*d)) / (2.0f * d) ;

    //Determine the distance from point 2 to either of the intersection points.
    float h = sqrt((r0*r0) - (a*a));

    //Now determine the offsets of the intersection points from point 2.
    Vector p2 = (p1-p0) * (a/d) + p0;

    //Determine the absolute intersection points.
    float x0 = p2.x + h*(p1.y - p0.y)/d;
    float y0 = p2.y - h*(p1.x - p0.x)/d;
    float x1 = p2.x - h*(p1.y - p0.y)/d;
    float y1 = p2.y + h*(p1.x - p0.x)/d;

    return {Vector(x0,y0), Vector(x1,y1)};
}
