#include "person.h"
#include "bodydata.h"
#include "geometry.h"

cpBody* td_person_create(cpSpace* space, float x, float y, void* data)
{
    // create body
    cpBody* body = cpSpaceAddBody(space, cpBodyNew(10.f, INFINITY));
    cpBodySetPosition(body, cpv(x, y));

    // create shape
    cpShape* shape = cpSpaceAddShape(space, cpCircleShapeNew(body, 0.5f, cpvzero));
    cpShapeSetFriction(shape, 0.1);
    cpShapeSetUserData(shape, (void *) ST_CIRCLE);

    // create target body
    cpBody* target = cpBodyNew(0.f, INFINITY);
    cpBodySetPosition(target, cpv(x, y));

    // create target joint
    cpConstraint* joint = cpSpaceAddConstraint(space, cpPivotJointNew2(target, body, cpvzero, cpvzero));
    cpConstraintSetMaxBias(joint, 15.f);
    cpConstraintSetMaxForce(joint, 30000.f);

    BodyData* bt = calloc(1, sizeof(BodyData));
    bt->type = BT_PERSON;
    bt->data = data;
    bt->person.shape = shape;
    bt->person.target = target;
    bt->person.joint = joint;
    cpBodySetUserData(body, bt);

    return body;
}