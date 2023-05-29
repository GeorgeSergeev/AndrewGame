#include <gl/glut.h>
#include "draw.h"

void drawLine(ObjectDescription* descr) {

	descr->x += descr->dx;
	descr->y += descr->dy;
	descr->alpha += 3;
	if (descr->x <= -0.9) descr->dx *= -1;
	if (descr->y <= -0.9) descr->dy *= -1;
	if (descr->x >= 0.9) descr->dx *= -1;
	if (descr->y >= 0.9) descr->dy *= -1;
	if (descr->alpha > 360) descr->alpha = 0;
	glLineWidth(3);
	glColor3f(0.0f, 0.6f, 0.9f);

	glPushMatrix();
	glRotatef(descr->alpha, 0.0f, 0.0f, 1.0f);

	glBegin(GL_LINES);
	glVertex2f(descr->x, descr->y);
	glVertex2f(descr->x + 0.05, descr->y);
	glEnd();
	glPopMatrix();
};

void drawLuncher(ObjectDescription* descr)
{
	if (descr->x > -0 && descr->x < 0.9f) descr->x += descr->dx;
	if (descr->y > -0.9f && descr->y < 0.9f) descr->y += descr->dy;

	glPushMatrix();
	glRotatef(descr->alpha, 0.0f, 0.0f, 1.0f);

	glLineWidth(3);
	glColor3f(0.0f, 0.0f, 0.6f);

	glBegin(GL_QUADS);
	glVertex2f(descr->x, descr->y);
	glVertex2f(descr->x + 0.1, descr->y);
	glVertex2f(descr->x + 0.1, descr->y + 0.1);
	glVertex2f(descr->x, descr->y + 0.1);
	glEnd();
	glPopMatrix();
};
