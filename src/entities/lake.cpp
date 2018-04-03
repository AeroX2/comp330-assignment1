/*
 * Lake.cpp
 *
 *  Created on: 23 Mar. 2018
 *      Author: James Ridey (44805632)
 */

#include "lake.hpp"

//Crudely drawn lake coordinates
int coords[][2] = {
        {-103, 11}, {-53,  4}, {-19,  2}, {50,   0}, {74,   17}, {91,   34}, {106,  54}, {119,  73}, {143,  102},
        {163,  113}, {191,  131}, {222,  141}, {245,  150}, {250,  160}, {235,  168}, {242,  182}, {262,  188},
        {285,  192}, {314,  193}, {347,  188}, {388,  189}, {412,  192}, {420,  204}, {424,  221}, {413,  234},
        {371,  285}, {342,  300}, {332,  312}, {295,  329}, {254,  348}, {232,  374}, {203,  400}, {190,  416},
        {177,  436}, {153,  456}, {134,  466}, {116,  463}, {111,  452}, {106,  441}, {90,   437}, {88,   426},
        {93,   416}, {85,   392}, {70,   372}, {66,   351}, {65,   332}, {64,   316}, {42,   317}, {20,   312},
        {13,   299}, {5,    290}, {-12,  289}, {-22,  286}, {-26,  273}, {-43,  263}, {-63,  238}, {-70,  222},
        {-73,  206}, {-89,  178}, {-102, 160}, {-112, 148}, {-105, 122}, {-106, 111}, {-121, 97}, {-137, 90},
        {-144, 73}, {-136, 58}, {-139, 39}, {-126, 21}, {-106, 13},
};

Lake::Lake(Vector position, Vector size) : Entity(position, size) {
    debug("Creating lake object");
}

void Lake::redraw() {
    Entity::redraw();

    glColor3ub(0, 0, 255);
    glBegin(GL_TRIANGLE_FAN);
        for (auto coord : coords) {
            glVertex2f(coord[0], coord[1]);
        }
    glEnd();
}

/*
 * Adapted from: https://en.wikipedia.org/wiki/Even-odd_rule
 * Used for checking if a point in within a polygon
 * Mainly used for checking if the helicopter is inside the lake to take water
 */
bool Lake::check_collision(Entity entity) {
    auto hx = (int) entity.position.x;
    auto hy = (int) entity.position.y;
    int num = sizeof(coords) / sizeof(coords[0]);

    int j = num - 1;
    bool c = false;
    for (int i = 0; i < num; i++) {
        auto l0x = (int) (coords[i][0] + position.x);
        auto l0y = (int) (coords[i][1] + position.y);
        auto l1x = (int) (coords[j][0] + position.x);
        auto l1y = (int) (coords[j][1] + position.y);

        if (((l0y > hy) != (l1y > hy)) &&
            (hx < l0x + (l1x - l0x) * (hy - l0y) / (l1y - l0y))) {
            c = !c;
        }
        j = i;
    }
    return c;
}
