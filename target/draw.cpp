#include <gl/glut.h>
#include "draw.h"

void drawLine(ObjectDescription* model) {

	model->x += model->dx;
	model->y += model->dy;
	model->alpha += 3;
	if (model->x <= -0.9) model->dx *= -1;
	if (model->y <= -0.9) model->dy *= -1;
	if (model->x >= 0.9) model->dx *= -1;
	if (model->y >= 0.9) model->dy *= -1;
	if (model->alpha > 360) model->alpha = 0;
	glLineWidth(3);
	glColor3f(0.0f, 0.6f, 0.9f);

	glPushMatrix();
	glRotatef(model->alpha, 0.0f, 0.0f, 1.0f);

	glBegin(GL_LINES);
	glVertex2f(model->x, model->y);
	glVertex2f(model->x + 0.05, model->y);
	glEnd();
	glPopMatrix();
};

void drawLuncher(ObjectDescription* model)
{
	if (model->x > -0 && model->x < 0.9f) model->x += model->dx;
	if (model->y > -0.9f && model->y < 0.9f) model->y += model->dy;
	model->dx = 0;
	model->dy = 0;


	glPushMatrix();
	glRotatef(model->alpha, 0.0f, 0.0f, 1.0f);

	glLineWidth(3);
	glColor3f(0.0f, 0.0f, 0.6f);

	glBegin(GL_QUADS);
	glVertex2f(model->x, model->y);
	glVertex2f(model->x + 0.1, model->y);
	glVertex2f(model->x + 0.1, model->y + 0.1);
	glVertex2f(model->x, model->y + 0.1);
	glEnd();
	glPopMatrix();
};
