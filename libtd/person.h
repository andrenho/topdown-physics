#ifndef PERSON_H_
#define PERSON_H_

#include "chipmunk/chipmunk.h"

typedef struct Person {
    cpShape*      shape;
    cpBody*       target;
    cpConstraint* joint;
} Person;

cpBody* td_person_create(cpSpace* space, float x, float y, void* data);

#endif