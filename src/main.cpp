/*
 * main.cpp -- Helicopter game
 * Author: James Ridey (44805632)
 * Date: March 2018
 */

#include <GL/freeglut.h>

#include "constants.hpp"
#include "world.hpp"

#if defined(_WIN32) || defined(WIN32)
#else
#include <unistd.h>
#endif

int WINDOW_WIDTH = INITIAL_WINDOW_WIDTH;
int WINDOW_HEIGHT = INITIAL_WINDOW_HEIGHT;

World world;

int menu_id;
double current_time = 0;
double accumulator = 0;
bool running = true;
bool ignore_mouse_move = false;

/* Initialization function  */
void init() {
    debug("Init");

    //Initialize a few OpenGL parameters
    glClearColor(BACKGROUND_COLOR);
    glColor3f(1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, WINDOW_WIDTH, 0, WINDOW_HEIGHT);

    //Enable transparency
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    world.init();
    current_time = glutGet(GLUT_ELAPSED_TIME);
}

/*
 * Update function, updates the state of the world
 */
void update() {
    world.update();
}

/*
 * Display callback function, called for initial display
 * and whenever redisplay needed
 */
void redraw() {
    glClear(GL_COLOR_BUFFER_BIT);
    world.redraw();

    glPushMatrix();
        glLoadIdentity();
        glColor3b(0, 0, 0);
        glRasterPos2i(10, WINDOW_HEIGHT - 50);
        glutBitmapString(GLUT_BITMAP_HELVETICA_12,
                         reinterpret_cast<const unsigned char *>("When the helicopter is over the lake, double click to fill up on water"));
        glRasterPos2i(10, WINDOW_HEIGHT - 75);
        glutBitmapString(GLUT_BITMAP_HELVETICA_12,
                         reinterpret_cast<const unsigned char *>("Double click when the helicopter is not over the lake to dump water"));
    glPopMatrix();

    glutSwapBuffers();
}

/*
 * Main game loop
 * Based upon Fix Your Timestep by Gaffer on Games
 * https://gafferongames.com/post/fix_your_timestep/
 */
void gameloop() {
    double new_time = glutGet(GLUT_ELAPSED_TIME);
    double frameTime = ((new_time - current_time) * 1000) / CLOCK_PER_SEC;
    current_time = new_time;

    accumulator += frameTime;

    while (accumulator >= FRAME_RATE) {
        glutMainLoopEvent();
        update();
        glutPostRedisplay();
        accumulator -= FRAME_RATE;
    }

#if defined(_WIN32) || defined(WIN32)
    Sleep(1);
#else
    usleep(1);
#endif
}

/*
 * Process the right click menu events and the key presses
 */
void processMenuEvents(int option) {
    ignore_mouse_move = true;

    switch (option) {
        case MENU_EXIT:
            running = false;
            break;
        case MENU_RESET:
            world.reset();
            break;
        case MENU_TOGGLE_LOOPING:
            world.toggle_looping();
            break;
        case MENU_CLEAR_PATH:
            world.clear_mouse_points();
            break;
        default:
            break;
    }
    glutPostRedisplay();
}

/*
 * Keyboard callback function, called when a key is pressed
 */
void key_down(unsigned char key, int x, int y) {
}

/*
 * Keyboard callback function, called when a key is release
 */
void key_up(unsigned char key, int x, int y) {
    if (key == 'q') {
        processMenuEvents(MENU_EXIT);
    } else if (key == 'r') {
        processMenuEvents(MENU_RESET);
    } else if (key == 'l') {
//        processMenuEvents(MENU_RESET);
//        world.toggle_looping();
    } else if (key == 'c') {
        processMenuEvents(MENU_CLEAR_PATH);
    }
}

/*
 * Mouse motion callback, called whenever the mouse is down and moved
 */
void mouse_move(int x, int y) {
    if (ignore_mouse_move) {
        ignore_mouse_move = false;
        return;
    }

    //If the window is resized the mouse coordinates will need to be offset
    x -= (WINDOW_WIDTH - INITIAL_WINDOW_WIDTH) / 2;
    y += (WINDOW_HEIGHT - INITIAL_WINDOW_HEIGHT) / 2;

    world.mouse_point(x, WINDOW_HEIGHT - y);
}

/*
 * Mouse click callback function, called when the mouse is clicked
 */
void mouse_click(int button, int state, int x, int y) {
    if (state == GLUT_UP && button == GLUT_LEFT_BUTTON) {
        world.mouse_click(x, y);
    }
}

/*
 * Reshape callback function, called when the window size is changed
 */
void reshape(int w, int h) {
    //New viewport to width and height of window
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, 0, h);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //Translate everything to the middle of the screen
    int x = (w - INITIAL_WINDOW_WIDTH) / 2;
    int y = (h - INITIAL_WINDOW_HEIGHT) / 2;
    glTranslated(x, y, 0);

    WINDOW_WIDTH = w;
    WINDOW_HEIGHT = h;
}

/*
 * Create the right click menu
 */
void createMenu() {
    menu_id = glutCreateMenu(processMenuEvents);
    glutAddMenuEntry("Exit (q)", MENU_EXIT);
    glutAddMenuEntry("Reset (r)", MENU_RESET);
//    glutAddMenuEntry("Toggle looping (l)",MENU_TOGGLE_LOOPING);
    glutAddMenuEntry("Clear path (c)", MENU_CLEAR_PATH);

    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argc, char *argv[]) {
    debug("Starting up");

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow("Helicopter Game");

    debug("Registering callbacks");
    //Register the GLUT callbacks
    glutIdleFunc(gameloop);
    glutDisplayFunc(redraw);
    glutKeyboardFunc(key_down);
    glutKeyboardUpFunc(key_up);
    glutMotionFunc(mouse_move);
    glutMouseFunc(mouse_click);
    glutReshapeFunc(reshape);

    createMenu();

    debug("Starting gameloop");
    init();
    while (running) {
        gameloop();
    }

    return 0;
}
