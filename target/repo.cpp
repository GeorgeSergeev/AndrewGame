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
	o->lastShootTime = 0;
	o->shoot = false;
	o->enable = true;
	o->modelAndDraw = drawLuncher;
	return add(o, repo);
}

ObjectDescription* CreateMissle(ObjectDescription* repo, ObjectDescription* luncher)
{
	ObjectDescription* o = new ObjectDescription;
	o->x = luncher->x;
	o->y = luncher->y;
	o->alpha = 0.0f;
	o->dx = -0.01f;
	o->dy = 0.0f;
	o->lastShootTime = 0;
	o->shoot = false;
	o->enable = true;
	o->modelAndDraw = drawMissle;
	return add(o, repo);
}
;

void DrawAll(ObjectDescription* repo) {
	ObjectDescription* current = repo;

	while (current != NULL) {
		current->modelAndDraw(current);
		current = current->next;
	}

}