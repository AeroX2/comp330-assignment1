/*
 * world.cpp
 *
 *  Created on: 10 Mar. 2018
 *      Author: James Ridey (44805632)
 */

#include "world.hpp"
#include "entities/splash.hpp"

World::World() :
        house1(HOUSE1_PARAMETERS),
        house2(HOUSE2_PARAMETERS),
        house3(HOUSE3_PARAMETERS),
        lake(LAKE_PARAMETERS) {

    fps = 0;
    looping = false;
    frameCounter = 0;
    previousFPSTime = 0;
    previousClickTime = 0;

    filling_mode = false;
}

void World::init() {
    entities.push_back(&house1);
    entities.push_back(&house2);
    entities.push_back(&house3);

    //entities.push_back(&fire1);
    //entities.push_back(&fire2);
    //entities.push_back(&fire3);

    for (int i = 0; i <= 360; i += 20) {
        float deg = i * PI / 180;
        float x = INITIAL_WINDOW_WIDTH/2 + cos(deg)*FIRE_DISTANCE_FROM_ORIGIN;
        float y = INITIAL_WINDOW_HEIGHT/2 + sin(deg)*FIRE_DISTANCE_FROM_ORIGIN;
        Fire* fire = new Fire(Vector(x,y),Vector(0,0)); 
        entities.push_back(fire);
    }

    entities.push_back(&lake);

    entities.push_back(&helicopter);
}

void World::reset() {
    helicopter = Helicopter();
    clear_mouse_points();
}

void World::update() {
    //Update every entity
    for (Entity *entity : entities) {
        entity->update();
    }

    //If there is a collision with the lake
    //the mouse click event fills the helicopter instead of dumping it
    //Otherwise prevent the helicopter from filling
    if (lake.check_collision(helicopter)) {
        filling_mode = true;
    } else {
        filling_mode = false;
        helicopter.set_filling(false);
    }

    if ((!mouse_points.empty()) &&
        (helicopter.position - mouse_points.front()).distance() <= HELICOPTER_POINT_DISTANCE) {

        if (looping) mouse_points.push_back(mouse_points.front());

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
    if ((currentTime - previousFPSTime) >= 1000) {
        fps = frameCounter;
        frameCounter = 0;
        previousFPSTime = currentTime;
    }
    frameCounter++;
    char tempString[50];
    snprintf(tempString, 50, "FPS: %d", fps);

    //And draw it
    glPushMatrix();
        glLoadIdentity();
        glColor3f(1, 1, 1);
        glRasterPos2i(10, WINDOW_HEIGHT - 30);
        glutBitmapString(GLUT_BITMAP_HELVETICA_18, reinterpret_cast<unsigned char *>(tempString));
    glPopMatrix();

    //Draw every entity
    for (Entity *entity : entities) {
        glPushMatrix();
            entity->redraw();
        glPopMatrix();
    }

    //Draw the water meter
    glPushMatrix();
        glColor3ub(0, 0, 0);
        glRasterPos2i(65, 10);
        glutBitmapString(GLUT_BITMAP_HELVETICA_12, reinterpret_cast<const unsigned char *>("Water meter"));

        glColor3ub(0, 0, 255);
        glRectf(10, 10, 60, 15 + 300 * (helicopter.get_water() / HELICOPTER_MAX_WATER));
    glPopMatrix();

    //Draw the points, first point being a circle, the rest a line
    if (!mouse_points.empty()) {
        glColor3ub(255, 255, 255);
        glPushMatrix();
            Vector first_point = mouse_points.front();
            glTranslatef(first_point.x, first_point.y, 0);
            Utils::draw_circle(5);
        glPopMatrix();
        glPushMatrix();
            glLineWidth(3);
            glBegin(GL_LINE_STRIP);
                for (Vector point : mouse_points) {
                    glVertex2d(point.x, point.y);
                }
                if (looping) {
                    Vector start_point = mouse_points.front();
                    glVertex2d(start_point.x, start_point.y);
                }
            glEnd();

            //Draw the helicopter outline at the end of the path
            fake_helicopter.position = mouse_points.back();
            fake_helicopter.rotation = helicopter.rotation;
            if (mouse_points.size() >= 2) {
                int size = mouse_points.size();
                float rotation = (mouse_points[size-1] - mouse_points[size-2]).angle();
                fake_helicopter.rotation = rotation;
            }
            fake_helicopter.draw_helicopter(true);

        glPopMatrix();
    }
}

/*
 * Function binded to motionFunc,
 * called when the mouse is down and moved
 */
void World::mouse_point(int x, int y) {
    Vector current_point = Vector(x, y);

    //If there are no points, tell the helicopter to
    //fly towards that point
    if (mouse_points.empty()) {
        helicopter.set_stop(false);
        helicopter.set_start_target(current_point);
    }

    //Make another point if the mouse is far enough away from the previous point
    if (mouse_points.empty() || (current_point - mouse_points.back()).fake_distance() > MOUSE_POINT_DISTANCE) {
        mouse_points.push_back(current_point);
    }
}

/*
 * Function executed when the mouse is clicked
 */
void World::mouse_click(int x, int y) {
    int currentTime = glutGet(GLUT_ELAPSED_TIME);
    if ((currentTime - previousClickTime) <= DOUBLE_CLICK_TIME) {
        if (filling_mode) {
            helicopter.set_filling(true);
        } else {
            float &water = helicopter.get_water();
            if (water >= SPLASH_WATER_AMOUNT) {
                water -= SPLASH_WATER_AMOUNT;
                Entity *entity = new Splash(helicopter.position, Vector(50, 0));
                entities.push_back(entity);
            }
        }
        previousClickTime = 0;
    } else {
        previousClickTime = currentTime;
    }
}

void World::toggle_looping() {
    looping = !looping;
}

void World::clear_mouse_points() {
    mouse_points.clear();
    helicopter.set_stop(true);
}

