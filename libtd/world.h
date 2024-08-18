#ifndef WORLD_H_
#define WORLD_H_

#include "person.h"
#include "geometry.h"

typedef struct td_World td_World;

td_World* td_world_create();
void      td_world_destroy(td_World* world);

td_Person* td_world_add_person(td_World* world, float x, float y);
void       td_world_add_static_obj(td_World* world, td_Shape* shape);

#endif