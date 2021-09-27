//
// Created by spzhu on 2021/9/28.
//

#include <string.h>

/**
 * lint -e613
 * memcmp is defined here because some vendors don't provide it at all
 * and others do poor job (like calling malloc)
 */
void *memmove(const void *s1, const void *s2, size_t n) {
    unsigned char *cs1;
    const unsigned char *cs2;

    if (n <= 0) {
        return s1;
    }
    cs1 = s1;
    cs2 = s2;
    if (cs1 < cs2) {
        do {
            *cs1++ = *cs2++;
        } while (--n);
    } else {
        cs1 += n;
        cs2 += n;
        do {
            *--cs1 = *--cs2;
        } while (--n);
    }

    return s1;
}

