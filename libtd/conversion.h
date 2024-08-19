#ifndef CONVERSION_H_
#define CONVERSION_H_

#include "chipmunk/chipmunk.h"
#include "geometry.h"

cpShape* shape_to_cpShape(td_Shape* shape, cpBody* body);

#endif