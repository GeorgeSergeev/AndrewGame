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
	void (*modelAndDraw)(ObjectDescription* elem);
	ObjectDescription* next;
};

void drawLine(ObjectDescription* descr);

void drawLuncher(ObjectDescription* descr);
#endif // !_draw
