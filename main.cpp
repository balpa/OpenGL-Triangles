#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <random>
using namespace std;

GLint b = 300;
bool collide = false;
GLdouble counter = 400, yatay= 20, yatay2; //counter random yap
float xr = 0, yr = 0, movd, divx = 250, divy = 4;
int i;
float t = 0;

GLdouble clipAreaXLeft, clipAreaXRight, clipAreaYBottom, clipAreaYTop;


GLint NumberOfPoints = 10;
GLfloat x[10], y[10];

/*float vertices[] = {
	// first triangle
	100,150, 
	150, 150, 
	125,200, 
	// second triangle
	200, 250, 
	250,250,
	225,300,
};*/


void initOpenGl()
{
	glClearColor(1.0, 1.0, 1.0, 1.0); //Background Color
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 700, 0, 500);
	glMatrixMode(GL_MODELVIEW);
}

/*void bar() {


	glColor3f(0.1, 0.1, 1.0);
	glBegin(GL_QUADS);

	glVertex2f(150 + xr, 20 + yr);
	glVertex2f(250 + xr, 20 + yr);
	glVertex2f(250 + xr, 40 + yr);
	glVertex2f(150 + xr, 40 + yr);

	glEnd();
	glFlush();



}*/ //bar


/*void drawTriangle()//triangle
{
	glLoadIdentity();
	glTranslatef(0, movd, 0);
	for (i = 1; i <= 10; i++)
	{
		glColor3f(0, 0, 0);
		glBegin(GL_QUADS);
		glVertex2f(divx - 5, divy * 15 * i + 18);
		glVertex2f(divx - 5, divy * 15 * i - 18);
		glVertex2f(divx + 5, divy * 15 * i - 18);
		glVertex2f(divx + 5, divy * 15 * i + 18);
		glEnd();
	}
	glLoadIdentity();
}
*/

void triangle()
{


	glLoadIdentity();
	glTranslated(0.0,0.0, 0.0);
	glColor3f(0.2, 0.2, 1.0);

	glBegin(GL_QUADS);

	glVertex2f(150 + xr, 20 + yr);
	glVertex2f(250 + xr, 20 + yr);
	glVertex2f(250 + xr, 40 + yr);
	glVertex2f(150 + xr, 40 + yr);

	glEnd();
	glFlush();


	//----------------------------
	
	/*glDrawArrays(GL_TRIANGLES, 0, 6);*/
	


		glLoadIdentity();

		counter = counter - 0.01;
		yatay = yatay + 0.008;

		glTranslated(yatay,counter, 0.0);


		glColor3f(0.1, 0.4, 0.8);
		glBegin(GL_TRIANGLES);
		glVertex2f(100, 150);
		glVertex2f(150, 150);
		glVertex2f(125, 200);

		glEnd();
		glFlush();


	
	counter = counter - 0.01;
	yatay = yatay + 0.01;
	glTranslated(-yatay, counter, 0.0);

	glColor3f(0.56, 0.0, 0.3);
	glBegin(GL_TRIANGLES);
	glVertex2f(100, 150);
	glVertex2f(150, 150);
	glVertex2f(125, 200);

	glEnd();
	glFlush();


	counter = counter - 0.01;
	yatay = yatay + 0.02;
	glTranslated(yatay, counter, 0.0);

	glColor3f(0.2, 0.38, 0.0); 
	glBegin(GL_TRIANGLES);
	glVertex2f(100, 150);
	glVertex2f(150, 150);
	glVertex2f(125, 200);

	glEnd();
	glFlush();

		counter = counter - 0.01;
		yatay = yatay + 0.001;
		glTranslated(yatay, counter, 0.0);

		glColor3f(0.6, 0.5, 0.6);
		glBegin(GL_TRIANGLES);
		glVertex2f(100, 150);
		glVertex2f(150, 150);
		glVertex2f(125, 200);

		glEnd();
		glFlush();
}

/*
void trianglemany() {

	glLoadIdentity();

	for (i = 0; i < 6; i++) {

		for (yatay2 = 0; yatay2 < 50; yatay2++) {

			
			glTranslated(yatay2, counter, 0.0);


			glColor3f(0.2, 0.9, 0.5);
			glBegin(GL_TRIANGLES);
			glVertex2f(100, 150);
			glVertex2f(150, 150);
			glVertex2f(125, 200);


			glEnd();
			glFlush();

		}



	}



}*/
/*void bar() {


	glBegin(GL_QUADS);

	glVertex2f(150 + xr, 20 + yr);
	glVertex2f(250 + xr, 20 + yr);
	glVertex2f(250 + xr, 40 + yr);
	glVertex2f(150 + xr, 40 + yr);

	glEnd();
	glFlush();
	glutSwapBuffers();



}*/


void Timer(int value)  // timer-score
{
	t += 1;
	glutPostRedisplay();
	// 1000 milliseconds = 1 second
	glutTimerFunc(10000, Timer, 0);
	cout << t;

}

void display()
{

	glClear(GL_COLOR_BUFFER_BIT);
	//Push and pop matrix for separating circle object from Background
	glColor3f(0.0, 1.0, 0.0);

	
		triangle();
		Timer(0);

	

	glutSwapBuffers();
	glFlush();



}


void specialkey(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_UP:
		yr = yr + 5;
		glutPostRedisplay();
		break;
	case GLUT_KEY_DOWN:
		yr = yr - 5;
		glutPostRedisplay();
		break;
	case GLUT_KEY_LEFT:
		xr = xr - 5;
		glutPostRedisplay();
		break;
	case GLUT_KEY_RIGHT:
		xr = xr + 5;
		glutPostRedisplay();
		break;
	case GLUT_KEY_HOME:
		exit(0);
		break;
	}
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(600, 900);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OYUN");
	initOpenGl();
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutSpecialFunc(specialkey);
	glutMainLoop();
	return 0;
}