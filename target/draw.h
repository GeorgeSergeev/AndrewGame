#pragma once
#ifndef _draw
#define _draw

struct ObjectDescription
{
	// enum { LANCHER, MISSLE } kind;
	float x, dx;
	float y, dy;
	int alpha;
	bool enable;
	int lastShootTime;
	bool shoot;
	void (*modelAndDraw)(ObjectDescription* elem);
	ObjectDescription* next;
};

void drawMissle(ObjectDescription* model);

void drawLuncher(ObjectDescription* model);
#endif // !_draw
