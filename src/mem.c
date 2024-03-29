//
// Created by spzhu on 2021/9/28.
//
#include <stdlib.h>
#include <stddef.h>

#include "mem.h"
#include "assert.h"
#include "except.h"

const Except_T Mem_Failed = { "Allocation Failed" };

void *Mem_alloc(long nbytes, const char *file, int line) {
    void *ptr;
    assert(nbytes > 0);
    ptr = malloc(nbytes);
    if (ptr == NULL) {
        if (file == NULL) {
            RAISE(Mem_Failed);
        } else {
            Except_raise(&Mem_Failed, file, line);
        }
    }

    return ptr;
}

void *Mem_calloc(long count, long nbytes, const char *file, int line) {
    void *ptr;
    assert(count > 0);
    assert(nbytes > 0);
    ptr = calloc(count, nbytes);
    if (ptr == NULL) {
        if (file == NULL) {
            RAISE(Mem_Failed);
        } else {
            Except_raise(&Mem_Failed, file, line);
        }
    }
}

void Mem_free(void *ptr, const char *file, int line) {
    if (ptr) {
        free(ptr);
    }
}

void *Mem_resize(void *ptr, long nbytes, const char *file, int line) {
    assert(ptr);
    assert(nbytes > 0);
    ptr = realloc(ptr, nbytes);
    if (ptr == NULL) {
        if (file == NULL) {
            RAISE(Mem_Failed);
        } else {
            Except_raise(&Mem_Failed, file, line);
        }
    }

    return ptr;
}


void test_api(char *msg) {
    printf("test_api msg: %s\n", msg);
}
