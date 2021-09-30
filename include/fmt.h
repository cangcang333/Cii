
#ifndef CII_FMT_H
#define CII_FMT_H

#include <stdarg.h>
#include <stdio.h>
#include "except.h"

#define T Fmt_T

typedef void  (*T)(int code, va_list *app, int put(int c, void *cl), void *cl,
                    unsigned char flags[256], int width, int precision);
extern char *Fmt_flags;
extern const Except_T Fmt_Overflow;
extern void Fmt_fmt(int put(int c, void *cl), void *cl, const char *fmt, ...);

extern void Fmt_vfmt(int put(int c, void *cl), void *cl, const char *fmt, va_list ap);




#undef T


#endif