#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cmath>

using namespace std;

class Vector {
    public:
        explicit Vector(float x = 0, float y = 0);

        Vector operator+(const Vector &rhs);
        Vector operator-(const Vector &rhs);
        Vector operator*(const Vector &rhs);
        Vector operator*(float rhs);

        Vector &operator+=(const Vector &rhs);
        Vector &operator-=(const Vector &rhs);
        Vector &operator*=(const Vector &rhs);
        Vector &operator*=(float rhs);

        Vector &operator/=(float rhs);

        float distance();
        float fake_distance();
        Vector normalise();
        void print();

        float x;
        float y;

        float angle();

        Vector truncate(float max);

        Vector limit(const float d);
};

#endif
