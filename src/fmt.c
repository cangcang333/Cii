#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <math.h>

#include "assert.h"
#include "except.h"
#include "fmt.h"
#include "mem.h"

define T Fmt_T

struct buf {
    char *buf;
    char *bp;
    int size;
};

#define pad(n, c)  do { int nn = (n); \
                        while (nn-- > 0) { \
                            put((c), cl);  \
                            }   \
                    } while (0)

static void cvt_s(int code, va_list *app, int put(int c, void *cl), void *cl,
                  unsigned char flags[], int width, int precision) {
    char *str = va_arg(*app, char *);
    assert(str);
    Fmt_puts(str, strlen(str), put, cl, flags, width, precision);
}




