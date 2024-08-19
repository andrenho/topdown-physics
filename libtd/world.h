#ifndef WORLD_H_
#define WORLD_H_

#include <stddef.h>

#include "geometry.h"
#include "chipmunk/chipmunk.h"

typedef struct td_World td_World;

typedef cpBody td_Unit;

td_World* td_create();
void      td_destroy(td_World* world);

size_t    td_shapes(td_World* world, td_Shape* shapes, size_t max_shapes);

td_Unit*  td_add_person(td_World* world, float x, float y, void* data);
void      td_add_static_obj(td_World* world, td_Shape* shape);

#endif