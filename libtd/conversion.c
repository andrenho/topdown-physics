#include "conversion.h"

cpShape* shape_to_cpShape(td_Shape* shape, cpBody* body)
{
    switch (shape->type) {
        case ST_CIRCLE:
            return cpCircleShapeNew(body, shape->circle.radius, cpv(shape->circle.x, shape->circle.y));
        case ST_POLYGON: {
            cpVect vect[8];
            for (size_t i = 0; i < shape->polygon.n_points; ++i)
                vect[i] = cpv(shape->polygon.x[i], shape->polygon.y[i]);
            return cpPolyShapeNew(body, shape->polygon.n_points, vect, cpTransformIdentity, 0.f);
        }
    }
}

void cpShape_to_shape(cpShape* shape, td_Shape* out)
{
    td_ShapeType shape_type = (td_ShapeType) (intptr_t) cpShapeGetUserData(shape);
    out->type = shape_type;
    switch (shape_type) {
        case ST_CIRCLE: {
            cpVect pos = cpCircleShapeGetOffset(shape);
            out->circle.x = pos.x;
            out->circle.y = pos.y;
            out->circle.radius = cpCircleShapeGetRadius(shape);
            break;
        }
        case ST_POLYGON:
            out->polygon.n_points = cpPolyShapeGetCount(shape);
            for (size_t i = 0; i < out->polygon.n_points; ++i) {
                if (i == 8)
                    break;
                cpVect vect = cpPolyShapeGetVert(shape, i);
                out->polygon.x[i] = vect.x;
                out->polygon.y[i] = vect.y;
            }
            break;
    }
}