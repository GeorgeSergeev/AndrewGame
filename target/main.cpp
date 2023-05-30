
#include <stdio.h>
#include <cstdlib>
#include "draw.h"
#include "repo.h"
#include <gl/glut.h>





int WindW, WindH;



float randomFloat()
{
	return  -0.9f + (static_cast <float> (rand()) / static_cast <float> (RAND_MAX))*2;
}


ObjectDescription* repo = NULL;
ObjectDescription* luncher = NULL;


void Reshape(int width, int height) // Reshape function 
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1, 1, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	WindW = width;
	WindH = height;
}

void Draw(void) // Window redraw function 
{
	glClear(GL_COLOR_BUFFER_BIT);

	
	DrawAll(repo);

	glFlush();
	glutSwapBuffers();
}

void Visibility(int state) // Visibility function 
{
	if (state == GLUT_NOT_VISIBLE) printf("Window not visible!\n");
	if (state == GLUT_VISIBLE) printf("Window visible!\n");
}

void timf(int value) // Timer function 
{
	glutPostRedisplay();
	// Redraw windows 
	glutTimerFunc(40, timf, 0);
	// Setup next timer 
}

void processKeyEvent(unsigned char key, int x, int y) {

}


void processSpecialKeyEvent(int key, int x, int y) {
	if (luncher != NULL && luncher->enable) {
		switch (key) {
		case GLUT_KEY_UP:
			luncher->dy = 0.01f;
			break;
		case GLUT_KEY_DOWN:
			luncher->dy = -0.01f;
			break;
		case GLUT_KEY_LEFT:
			luncher->dx = -0.01f;
			break;
		case GLUT_KEY_RIGHT:
			luncher->dx = 0.01f;
			break;

		}
	}
}


int main(int argc, char* argv[])
{
	WindW = 800; WindH = 800;
	
	luncher = CreateLuncher(repo);
	repo = luncher;

	// init random line
	
	for (float i = -0.8f; i < 0; i+=0.1f) {			
		ObjectDescription *o = new ObjectDescription;
		o->x = i;
		o->y = i;
		o->alpha = trunc(360.0f * randomFloat());
		o->dx = randomFloat()*0.1f;
		o->dy = randomFloat()*0.1f;
		o->enable = true;
		o->modelAndDraw = drawLine;
		repo = add(o, repo);
	}
	
		

	glutInit(&argc, argv);
	glutInitWindowSize(WindW, WindH);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	(void)glutCreateWindow("Andrew Play");
	glutReshapeFunc(Reshape);
	// Set up reshape function 
	glutDisplayFunc(Draw); // Set up redisplay function 
	glutTimerFunc(40, timf, 0); // Set up timer for 40ms, about 25 fps 
	glutKeyboardFunc(processKeyEvent);
	glutSpecialFunc(processSpecialKeyEvent);
	glutVisibilityFunc(Visibility); // Set up visibility funtion 
	glClearColor(0, 0, 0, 0);
	glutMainLoop();
	return 0;
}



