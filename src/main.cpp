/*
 * main.cpp -- Helicopter game
 * Author: James Ridey (44805632)
 * Date: March 2018
 */

#include <GL/freeglut.h>

#include "constants.hpp"
#include "world.hpp"

int WINDOW_WIDTH = INITIAL_WINDOW_WIDTH;
int WINDOW_HEIGHT = INITIAL_WINDOW_HEIGHT;

World world;
double current_time = 0;
double accumulator = 0;
bool running = true;

/* Initialization function  */
void init() {
	debug("Init");

	//Initialize a few OpenGL parameters
	glClearColor(0.8863, 0.6980, 0.4745, 1);
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

    glColor3b(0,0,0);
    glRasterPos2i(10, WINDOW_HEIGHT-50);
    glutBitmapString(GLUT_BITMAP_HELVETICA_12,
                     reinterpret_cast<const unsigned char *>("Double click over the lake\nto fill up on water"));
    glRasterPos2i(10, WINDOW_HEIGHT-85);
    glutBitmapString(GLUT_BITMAP_HELVETICA_12,
                     reinterpret_cast<const unsigned char *>("Double click anywhere else\nto dump the water collected"));

	glutSwapBuffers();
}

/*
 * Main game loop
 * Based upon Fix Your Timestep by Gaffer on Games
 * https://gafferongames.com/post/fix_your_timestep/
 */
void gameloop() {
	double new_time = glutGet(GLUT_ELAPSED_TIME);
	double frameTime = ((new_time - current_time) * 1000) / CLOCKS_PER_SEC;
	current_time = new_time;

	accumulator += frameTime;

	while (accumulator >= FRAME_RATE) {
		glutMainLoopEvent();
		update();
		glutPostRedisplay();
		accumulator -= FRAME_RATE;
	}
	Sleep(1);
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
        debug("Exiting");
        running = false;
    }
}

void mouse_move(int x, int y) {
    world.mouse_point(x, WINDOW_HEIGHT-y);
}

void mouse_click(int button, int state, int x, int y) {
	if (state == GLUT_UP && button == GLUT_LEFT_BUTTON) {
		world.mouse_click(x, y);
	}
}

void reshape(int width, int height) {
    //TODO A reminder that this is not currently working
	int x = (width-INITIAL_WINDOW_WIDTH)/2;
	int y = (height-INITIAL_WINDOW_HEIGHT)/2;
	gluOrtho2D(x, y, INITIAL_WINDOW_WIDTH, INITIAL_WINDOW_HEIGHT);
	glViewport(0,0,width,height);

	WINDOW_WIDTH = width;
	WINDOW_HEIGHT = height;
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

	debug("Starting gameloop");
	init();
	while (running) {
		gameloop();
	}

	return 0;
}
