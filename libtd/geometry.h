#ifndef GEOMETRY_H_
#define GEOMETRY_H_

#include <stdint.h>

#define MAX_POLY_PTS 8

typedef enum td_ShapeType { ST_CIRCLE, ST_POLYGON } td_ShapeType;

typedef struct td_Circle {
    float x, y;
    float radius;
} td_Circle;

typedef struct td_Polygon {
    uint8_t n_points;
    float x[MAX_POLY_PTS];
    float y[MAX_POLY_PTS];
} td_Polygon;

typedef struct td_Shape {
    td_ShapeType type;
    union {
        td_Circle  circle;
        td_Polygon polygon;
    };
} td_Shape;

#endif