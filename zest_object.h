//
// Created by bbrabbit on 11/19/20.
//

#ifndef ZEST_ZEST_OBJECT_H
#define ZEST_ZEST_OBJECT_H

#include <stddef.h>

#include "zest_gc.h"
#include "zest_object.h"
#include "zest_CFunction.h"

typedef void (*ZestFreeFunc)(void*);
typedef void (*ZestDestructFunc)(ZestObject*);
typedef ZestObject* (*ZestDisplayFunc)(ZestObject*);
typedef unsigned int(*ZestHashFunc)(ZestObject*);
typedef ZestObject* (*ZestGetMetaTableFunc)(ZestObject*);
typedef int (*ZestSetMetaTableFunc)(ZestObject*,ZestObject*,ZestObject*);
typedef ZestObject* (*ZestAllocFunc)(ZestObject*, size_t)

// basic types of zest language
typedef struct zest_string {
    int length;
    int free;
    long hash;
    char* str[1];
} ZestString;

typedef struct zest_table_node ZestTableNode;

struct zest_table_node {
    ZestTableNode* next;
    ZestObject* k;
    ZestObject* v;
};

typedef struct zest_table {
  ZestTableNode* node;
  ZestObject* array;
  unsigned int array_size;
} ZestTable;

typedef struct zest_object {
    GCObject* gc;
    union {
        void* rptr;
        void* zobj;
        long long i;
        double f;
        ZestCFunction* func;
    } data;
    unsigned char type;
    ZestTable* metatable;
    struct {
        ZestAllocFunc* alloc_func;
        ZestFreeFunc* free_func;
        ZestHashFunc* hash_func;
        ZestDestructFunc* destruct_func;
        ZestDisplayFunc* display_func;
        ZestGetMetaTableFunc* get_metatable_func;
        ZestSetMetaTableFunc* set_metatable_func;
    } obj_func;
}ZestObject;

#endif //ZEST_ZEST_OBJECT_H
