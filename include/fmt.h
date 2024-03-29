
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

extern void Fmt_print(const char *fmt, ...);

extern void Fmt_fprint(FILE *stream, const char *fmt, ...);

extern int Fmt_sfmt(char *buf, int size, const char *fmt, va_list ap);

extern int Fmt_vsfmt(char *buf, int size, const char *fmt, va_list ap);

extern char *Fmt_string(const char *fmt, ...);

extern char *Fmt_vstring(const char *fmt, va_list ap);

extern T Fmt_register(int code, T cvt);

extern void Fmt_putd(const char *str, int len, int put(int c, void *cl), void *cl,
                     unsigned char flags[256], int width, int precision);

extern void Fmt_puts(const char *str, int len, int put(int c, void *cl), void *cl,
                     unsigned char flags[256], int width, int precision);

#undef T


#endif