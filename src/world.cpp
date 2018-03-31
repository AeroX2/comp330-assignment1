/*
 * world.cpp
 *
 *  Created on: 10 Mar. 2018
 *      Author: James Ridey
 */

#include "world.hpp"
#include "entities/splash.hpp"

World::World() :
    house1(HOUSE1_PARAMETERS),
    house2(HOUSE2_PARAMETERS),
    house3(HOUSE3_PARAMETERS),
    fire1(FIRE1_PARAMETERS),
    fire2(FIRE2_PARAMETERS),
    fire3(FIRE3_PARAMETERS),
    lake(LAKE_PARAMETERS) {
    fps = 0;
    frameCounter = 0;
    previousTime = 0;
}

void World::init() {
    entities.push_back(&house1);
    entities.push_back(&house2);
    entities.push_back(&house3);

    entities.push_back(&fire1);
    entities.push_back(&fire2);
    entities.push_back(&fire3);

    entities.push_back(&lake);

    entities.push_back(&helicopter);
}

void World::update() {
    //Update every entity
    for (Entity* entity : entities) {
        entity->update();
    }

    if ((!mouse_points.empty()) && (helicopter.position - mouse_points.front()).distance() <= HELICOPTER_POINT_DISTANCE) {
        mouse_points.erase(mouse_points.begin());
        if (!mouse_points.empty()) {
            helicopter.set_target(mouse_points.front());
        } else {
            helicopter.set_stop(true);
        }
    }
}

void World::redraw() {
    //Calculate the current FPS
    int currentTime = glutGet(GLUT_ELAPSED_TIME);
    if ((currentTime-previousTime) >= 1000) {
        fps = frameCounter;
        frameCounter = 0;
        previousTime = currentTime;
    }
    frameCounter++;
    char tempString[50];
    snprintf(tempString, 50, "FPS: %d", fps);

    //And draw it
    glColor3f(1,1,1);
    glRasterPos2i(10, WINDOW_HEIGHT-30);
    glutBitmapString(GLUT_BITMAP_HELVETICA_18, reinterpret_cast<unsigned char*>(tempString));

    //Draw every entity
    for (Entity* entity : entities) {
        glPushMatrix();
            entity->redraw();
        glPopMatrix();
    }

    //Draw the points, first point being a circle, the rest a line
    if (!mouse_points.empty()) {
        glPushMatrix();
            Vector first_point = mouse_points.front();
            glTranslatef(first_point.x, first_point.y, 0);
            Utils::draw_circle(5);
        glPopMatrix();
    }
    glPushMatrix();
        glBegin(GL_LINE_STRIP);
            for (Vector point : mouse_points) {
                glColor3ub(255,255,255);
                glVertex2d(point.x, point.y);
            }
        glEnd();
    glPopMatrix();
}

void World::mouse_point(int x, int y) {
    Vector current_point = Vector(x,y);
    if (mouse_points.empty()) {
        helicopter.set_stop(false);
        helicopter.set_target(current_point);
    }

    if (mouse_points.empty() || (current_point - mouse_points.back()).fake_distance() > MOUSE_POINT_DISTANCE) {
        mouse_points.push_back(current_point);
    }
}

void World::mouse_right_click(int x, int y) {
    Entity* entity = new Splash(helicopter.position, Vector());
    entities.push_back(entity);
}

