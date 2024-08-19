#ifndef BODYDATA_H_
#define BODYDATA_H_

#include "person.h"

typedef enum BodyType {
    BT_PERSON,
} BodyType;

typedef struct BodyData {
    BodyType type;
    void*    data;
    union {
        Person person;
    };
} BodyData;

#endif