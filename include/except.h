//
// Created by spzhu on 2021/9/27.
//

#ifndef CII_EXCEPT_H
#define CII_EXCEPT_H


#include <setjmp.h>

#define T Except_T

typedef struct T {
    char *reason;
} T ;

typedef struct Except_Frame Except_Frame;
struct Except_Frame {
    Except_Frame *prev;
    jmp_buf env;
    const char *file;
    int line;
    const T *exception;
};

enum {
    Except_entered = 0,
    Except_raised,
    Except_handled,
    Except_finalized
};

extern Except_Frame *Except_stack;
extern const Except_T Assert_Failed;
void Except_raise(const T *e, const char *file, int line);
#define RAISE(e) Except_raise(&(e), __FILE__, __LINE__)

#endif //CII_EXCEPT_H
