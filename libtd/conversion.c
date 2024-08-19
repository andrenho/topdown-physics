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
