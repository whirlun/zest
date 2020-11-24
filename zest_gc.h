//
// Created by bbrabbit on 11/19/20.
//

#ifndef ZEST_ZEST_GC_H
#define ZEST_ZEST_GC_H

#include "zest_object.h"

typedef struct GCObject GCObject;

#define GCHEADER GCObject* prev; GCObject* next; unsigned char gcbit

struct GCObject {
    GCHEADER;
};


#endif //ZEST_ZEST_GC_H
