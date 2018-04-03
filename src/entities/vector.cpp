#include "vector.hpp"
#include "../constants.hpp"

Vector::Vector(float x, float y) : x(x), y(y) {
}

Vector Vector::operator+(const Vector &rhs) {
    Vector new_vector(x, y);
    new_vector += rhs;
    return new_vector;
}

Vector Vector::operator-(const Vector &rhs) {
    Vector new_vector(x, y);
    new_vector -= rhs;
    return new_vector;
}

Vector Vector::operator*(const Vector &rhs) {
    Vector new_vector(x, y);
    new_vector *= rhs;
    return new_vector;
}

Vector Vector::operator*(const float rhs) {
    Vector new_vector(x, y);
    new_vector.x *= rhs;
    new_vector.y *= rhs;
    return new_vector;
}

Vector &Vector::operator+=(const Vector &rhs) {
    x += rhs.x;
    y += rhs.y;
    return *this;
}

Vector &Vector::operator-=(const Vector &rhs) {
    x -= rhs.x;
    y -= rhs.y;
    return *this;
}

Vector &Vector::operator*=(const Vector &rhs) {
    x *= rhs.x;
    y *= rhs.y;
    return *this;
}

Vector &Vector::operator*=(const float rhs) {
    x *= rhs;
    y *= rhs;
    return *this;
}

Vector &Vector::operator/=(const float rhs) {
    x /= rhs;
    y /= rhs;
    return *this;
}

/*
 * Return the distance of the vector
 */
float Vector::distance() {
    return sqrt(x * x + y * y);
}

/*
 * Return the distance squared of the vector
 */
float Vector::fake_distance() {
    return x * x + y * y;
}

/*
 * Normalize the length of the vector between 0 and 1
 */
Vector Vector::normalise() {
    float length = distance();
    Vector new_vector = Vector(x, y);
    if (length != 0) {
        new_vector.x = new_vector.x / length;
        new_vector.y = new_vector.y / length;
    }
    return new_vector;
}

/*
 * Calculate the angle of the vector
 */
float Vector::angle() {
    if (y == 0 && x == 0) return 0;
    return atan2(y, x) * 180 / M_PI;
}

/*
 * If the length of the vector is larger than d,
 * limit the vector length to d
 */
Vector Vector::limit(const float d) {
    if (fake_distance() > d * d) {
        *this = normalise() * d;
    }
    return *this;
}

/*
 * Print out the vector to stdout
 */
void Vector::print() {
    cout << "X: " << x << '\n';
    cout << "Y: " << y << '\n';
}
