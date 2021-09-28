//
// Created by Danial on 2021/9/28.
//

#include "assert.h"

const Except_T Assert_Failed = { "Assertion failed" };

void (assert)(int e) {
    assert(e);
}

