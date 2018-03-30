/*
 * main.cpp -- Helicopter game
 * Authors: James Ridey
 * Date: March 2018
 */

#include <GL/freeglut.h>
#include <windows.h>

#include "constants.hpp"
#include "world.hpp"

int WINDOW_WIDTH = INITIAL_WINDOW_WIDTH;
int WINDOW_HEIGHT = INITIAL_WINDOW_HEIGHT;

World world;
double currentTime = 0;
double accumulator = 0;

/* Initialization function  */
void init() {
	debug("Init");

	//Initialize a few OpenGL parameters
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, WINDOW_WIDTH, 0, WINDOW_HEIGHT);

	world.init();
	currentTime = glutGet(GLUT_ELAPSED_TIME);
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
	glFlush();
}

/*
 * Main game loop
 * Based upon Fix Your Timestep by Gaffer on Games
 * https://gafferongames.com/post/fix_your_timestep/
 */
void gameloop() {
	double newTime = glutGet(GLUT_ELAPSED_TIME);
	double frameTime = ((newTime - currentTime) * 1000) / CLOCKS_PER_SEC;
	currentTime = newTime;

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
	if (key == 'q') exit(0);
}

void reshape(int width, int height) {
	int x = (width-INITIAL_WINDOW_WIDTH)/2;
	int y = (height-INITIAL_WINDOW_HEIGHT)/2;
	gluOrtho2D(x, y, INITIAL_WINDOW_WIDTH, INITIAL_WINDOW_HEIGHT);
	glViewport(0,0,width,height);

	WINDOW_WIDTH = width;
	WINDOW_HEIGHT = height;
}

void mouse_drag(int x, int y) {}

int main(int argc, char *argv[]) {
	debug("Starting up");

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("Helicopter Game");

	debug("Registering callbacks");
	//Register the GLUT callbacks
	glutDisplayFunc(redraw);
	glutKeyboardFunc(key_down);
	glutKeyboardUpFunc(key_up);
	glutReshapeFunc(reshape);

	debug("Starting gameloop");
	init();
	while (true) {
		gameloop();
	}

	return 0;
}
