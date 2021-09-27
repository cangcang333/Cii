#include <stdio.h>

#include "except.h"
#include "mem.h"

int main(int argc, char **argv) {
    printf("memTest start ...\n");

    char *msg = "reason why";
    Except_T exceptT;
    exceptT.reason = msg;
    printf("Except_T reason is %s\n", exceptT.reason);

    test_api("mem api working");

    printf("memTest end ...\n");

    return 0;
}