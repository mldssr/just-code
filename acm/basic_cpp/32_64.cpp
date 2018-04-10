/*
 * 32_64.cpp
 *
 *  Created on: 2018年4月9日
 *      Author: Lxx
 */

#include <cstdio>
#include <array>

union U {
    char *a;
    char b;
};
struct S {
    char *a;
    char b;
};
union U2 {
    S s;
    U u;
};

// 32位：4 8 8 2 2 4
void print_size() {
    printf("%zu\n", sizeof(U));
    printf("%zu\n", sizeof(S));
    printf("%zu\n", sizeof(U2));
    printf("%zu\n", sizeof(std::array<char, 2>));
    printf("%zu\n", sizeof(char[2]));
    printf("%zu\n", sizeof(char *));
}

int main() {
    print_size();
    return 0;
}

