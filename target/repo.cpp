#include "repo.h"
#include "draw.h"
#include <cstddef>


ObjectDescription* add(ObjectDescription* elem, ObjectDescription* repo) {

	elem->next = repo;
	repo = elem;
	return repo;
};

ObjectDescription* CreateLuncher(ObjectDescription* repo)
{
	// init luncher
	ObjectDescription* o = new ObjectDescription;
	o->x = 0.5f;
	o->y = 0.0f;
	o->alpha = 0.0f;
	o->dx = 0;
	o->dy = 0;
	o->enable = true;
	o->modelAndDraw = drawLuncher;
	return add(o, repo);
};

void DrawAll(ObjectDescription* repo) {
	ObjectDescription* current = repo;

	while (current != NULL) {
		current->modelAndDraw(current);
		current = current->next;
	}

}