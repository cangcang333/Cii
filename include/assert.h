//
// Created by Danial on 2021/9/28.
//

//#ifndef CII_ASSERT_H
//#define CII_ASSERT_H

#undef assert
#ifdef NDEBUG
#define assert(e) ((void)0)
#else
#include "except.h"
extern void assert(int e);
#define assert(e) ((void) ((e) || (RAISE(Assert_Failed), 0)))

#endif
