#include "world.h"

#include <stdlib.h>
#include <stddef.h>

typedef struct td_World {
} td_World;

td_World* td_world_create()
{
    td_World* w = calloc(1, sizeof(td_World));
    return w;
}

void td_world_destroy(td_World* world)
{
    free(world);
}

td_Person* td_world_add_person(td_World* world, float x, float y)
{
    return NULL;
}

void td_world_add_static_obj(td_World* world, td_Shape* shape)
{
}
