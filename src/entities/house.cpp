/*
 * house.cpp
 *
 *  Created on: 10 Mar. 2018
 *      Author: James Ridey (44805632)
 */

#include "house.hpp"

House::House(Vector position, Vector size, int peak) :
        Entity(position, size), peak(peak) {
}

void House::redraw() {
    Entity::redraw();

    int x0 = (int) -size.x / 2;
    int y0 = (int) -size.y / 2;
    int x1 = (int) size.x / 2;
    int y1 = (int) size.y / 2;

    glColor3ub(101, 102, 107);
    glRectf(x0, y0, x1, y1);

    //Rectangle outline
    glColor3ub(0, 0, 0);
    glLineWidth(5);
    glBegin(GL_LINE_LOOP);
        glVertex2d(x0, y0);
        glVertex2d(x1, y0);
        glVertex2d(x1, y1);
        glVertex2d(x0, y1);
    glEnd();

    //House roof lines
    glLineWidth(1);
    glBegin(GL_LINE_LOOP);
        glVertex2d(x0, y0);
        glVertex2d(-peak / 2, 0);
        glVertex2d(x0, y1);
        glVertex2d(-peak / 2, 0);
        glVertex2d(peak / 2, 0);
        glVertex2d(x1, y1);
        glVertex2d(peak / 2, 0);
        glVertex2d(x1, y0);
    glEnd();
}
