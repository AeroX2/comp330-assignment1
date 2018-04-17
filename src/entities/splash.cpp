/*
 * Lake.cpp
 *
 *  Created on: 23 Mar. 2018
 *      Author: James Ridey (44805632)
 */

#include "splash.hpp"
#include "fire.hpp"

Splash::Splash(Vector position, Vector size) : Entity(position, size) {
    debug("Creating splash object");
    fire = nullptr;
    opacity = 100;
    time_elapsed = glutGet(GLUT_ELAPSED_TIME);
}

void Splash::update() {
    Entity::update();

    int current_time = glutGet(GLUT_ELAPSED_TIME);
    if ((current_time - time_elapsed) >= SPLASH_PERSISTENCE_TIME) {
        size.x *= 0.99;
        opacity *= 0.99;
    }
}

void Splash::redraw() {
    Entity::redraw();

    glColor4ub(0, 0, 125, opacity);
    Utils::draw_circle(size.x);

    if (fire == nullptr) return;
    glPushMatrix();
        float distance = (position - fire->position).distance();
        bool inside = distance < fire->size.y;

        glColor3b(0,0,0);
        glBegin(GL_POLYGON);
            auto min_a = (int) min(splash_angles.first, splash_angles.second);
            auto max_a = (int) max(splash_angles.first, splash_angles.second);

            float diff_angle = (max_a - min_a);
            if (inside) {
                if (diff_angle <= 180) diff_angle -= 360;
            } else {
                if (diff_angle >= 180) diff_angle -= 360;
            }

            auto d = (int) diff_angle;
            d = d / 32 != 0 ? d / 32 : (d > 0 ? 1 : -1);
            for (int i = min_a; diff_angle > 0 ? i <= max_a : i >= max_a - 360; i += d) {
                float x = cos(i*PI/180) * size.y;
                float y = sin(i*PI/180) * size.y;

                Vector v = (position + Vector(x,y)) - fire->position;
                if (v.fake_distance() < fire->size.x*fire->size.x) {
                    float a = v.angle() * PI / 180;
                    x = -position.x + fire->position.x + cos(a) * fire->size.x;
                    y = -position.y + fire->position.y + sin(a) * fire->size.x;
                }

                glVertex2d(x, y);
            }

            min_a = (int) min(fire_angles.first, fire_angles.second);
            max_a = (int) max(fire_angles.first, fire_angles.second);

            diff_angle = -(max_a - min_a);
            if (diff_angle <= -180) diff_angle += 360;

            d = (int) diff_angle;
            d = d / 32 != 0 ? d / 32 : (d > 0 ? 1 : -1);
            for (int i = max_a; diff_angle < 0 ? i >= min_a : i <= min_a + 360; i += d) {
                float x = -position.x + fire->position.x + cos(i*PI/180) * fire->size.y;
                float y = -position.y + fire->position.y + sin(i*PI/180) * fire->size.y;

                glVertex2d(x, y);
            }
        glEnd();
    glPopMatrix();
}

void Splash::check_collision(Fire* fire) {
    intersection_points = Utils::circle_intersection(position, size.y, fire->position, fire->size.y);
    //Check and see if we found an intersection
    if (intersection_points.first.fake_distance() > 0 || intersection_points.second.fake_distance() > 0) {
        this->fire = fire;

        Vector p0 = intersection_points.first;
        Vector p1 = intersection_points.second;
        splash_angles = pair<float,float>((p0 - position).angle(), (p1 - position).angle());
        fire_angles = pair<float,float>((p0 - fire->position).angle(), (p1 - fire->position).angle());

        if (splash_angles.first < 0) splash_angles.first += 360;
        if (splash_angles.second < 0) splash_angles.second += 360;
        if (fire_angles.first < 0) fire_angles.first += 360;
        if (fire_angles.second < 0) fire_angles.second += 360;
    }
}
