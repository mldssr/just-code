/*
https://blog.csdn.net/zqxnum1/article/details/40592737

（1）二维数组就是一维数组
这个很好证明，依次输出地址，都是连续的，不多说。
（2）数组地址是什么？
先从一维数组开始int b[2]，数组地址就是对一个数组名进行取址，例如&b就是数组地址。
二维的int a[2][2]，a是二维数组名，&a就是二维数组地址；
a[0]是第一行的数组名（姑且叫第一行），&a[0]是第一行数组的数组地址，
同理a[1]，&a[1]分别是第二行数组名和数组地址。
（3）数组名可以转化为指针
首先纠正一点int b[2]，这里的b不是指针，同样的，int a[2][2]，里边的a也不是指针，
但是a和b可以转化为指针，可以转化不代表它就是，谁告诉你int就是short了。
https://segmentfault.com/q/1010000008897519
 */

// #include <bits/stdc++.h>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <typeinfo>

using namespace std;

// typedef long long ll;

char ch[2][3];       // 直接定义
typedef char PP[3];  // 间接定义，类型P为大小为3的char数组
PP ch1[2];
char (*p)[3];  // p 为一个指针，指向一个大小为3的char数组

void test0() {
    // 二维数组地址连续
    // addr of ch[0][0] : 0xbf9efb56
    // addr of ch[0][2] : 0xbf9efb58
    // addr of ch[1][0] : 0xbf9efb59
    // addr of ch[1][2] : 0xbf9efb5b
    printf("\n%p\n%p\n%p\n%p\n", &ch[0][0], &ch[0][2], &ch[1][0], &ch[1][2]);

    // char(*p)[3];
    cout << typeid(p).name() << endl;     // PA3_c
    cout << typeid(p[0]).name() << endl;  // A3_c

    // 以下的值均相同
    // 名称         类型
    // ch           int[2][2]
    // &ch          int[2][2] *
    // ch+0         int[2] *
    // ch[0]        int[2]
    // &ch[0]       int[2] *
    printf("\n%p\n%p\n%p\n%p\n%p\n", ch, &ch, ch[0], &ch[0], &ch[0][0]);

    PP *q = new PP[2];
    // 除了 &p，其余的值均相同
    printf("\n%p\n%p\n%p\n%p\n", &q, q[0], &q[0], &q[0][0]);
}

void test1() {
    int(*ptr)[2];  // ptr 为一个指针，指向一个大小为2的int数组
    int torf[2][2] = {12, 14, 16};
    // 12, 14, 16, 0
    printf("torf: %d, %d, %d, %d\n", torf[0][0], torf[0][1], torf[1][0],
           torf[1][1]);

    ptr = torf;
    printf("%d, %d\n", **ptr, **(ptr + 1));  // 12, 16
}

void test2() {
    int(*ptr)[2];
    int torf[2][2] = {{12}, {14, 16}};
    // 12, 0, 14, 16
    printf("torf: %d, %d, %d, %d\n", torf[0][0], torf[0][1], torf[1][0],
           torf[1][1]);

    ptr = torf;
    printf("%d, %d\n", **ptr, **(ptr + 1));  // 12, 14
}

int main() {
    test0();
    // test1();
    // test2();
    return 0;
}