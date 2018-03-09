/*
 * test++.cpp
 *
 *  Created on: Feb 27, 2018
 *      Author: lxx
 */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

char *strcpy(char *strDest, const char *strSrc) {
    assert((strDest != NULL) && (strSrc != NULL));
    char *address = strDest;
    while ((*strDest++ = *strSrc++) != '\0') {
        printf("=== %c === %02X === %c === %02X\n", *strSrc, *strSrc, *strDest, *strDest);
    }
    return address;
}

int main() {
    const char *str = "Hello,world.";
    char buf[20];
    strcpy(buf, str);

    int a = 10;
    int b = 11;
    printf("%d\n", (a = b));

    return 0;
}
