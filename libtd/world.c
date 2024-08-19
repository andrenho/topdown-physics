#include "world.h"
#include "person.h"
#include "conversion.h"

#include <stdlib.h>
#include <stddef.h>

typedef struct td_World {
    cpSpace* space;
} td_World;

td_World* td_create()
{
    td_World* world = calloc(1, sizeof(td_World));
    world->space = cpSpaceNew();
    return world;
}

void td_destroy(td_World* world)
{
    // TODO - free all units
    cpSpaceFree(world->space);
    free(world);
}

struct ShapeIterator {
    td_Shape* shapes;
    size_t max_shapes;
    size_t current;
};

static void td_each_shape(cpShape *shape, void *data)
{
    struct ShapeIterator* si = (struct ShapeIterator *) data;
    cpShape_to_shape(shape, &si->shapes[si->current]);
    ++si->current;
}

size_t td_shapes(td_World* world, td_Shape* shapes, size_t max_shapes)
{
    struct ShapeIterator si = {
            .shapes = shapes,
            .max_shapes = max_shapes,
            .current = 0,
    };
    cpSpaceEachShape(world->space, td_each_shape, &si);
    return si.current;
}

cpBody* td_add_person(td_World* world, float x, float y, void* data)
{
    return td_person_create(world->space, x, y, data);
}

void td_add_static_obj(td_World* world, td_Shape* shape)
{
    cpShape* shp = shape_to_cpShape(shape, cpSpaceGetStaticBody(world->space));
    cpShapeSetFriction(shp, 1);
    cpSpaceAddShape(world->space, shp);
    cpShapeSetUserData(shp, (void *) shape->type);
}
