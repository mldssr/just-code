/*
两个大数使用string表示，请实现一个函数，将他们相加。
注意：
1. 大数可能包含小数，比如：123.07 + 8796
2. 输入可能有误，请检查是否合法，不合法返回值为false。
3. 大数不包含科学计数法

编译器版本: gcc 4.8.4
请使用标准输入输出(stdin，stdout)
；请把所有程序写在一个文件里，勿使用已禁用图形、文件、网络、系统相关的头文件和操作，如sys/stat.h
, unistd.h , curl/curl.h , process.h 时间限制: 3S (C/C++以外的语言为: 5 S)
内存限制: 128M (C/C++以外的语言为: 640 M) 输入: 两个string表示的数 输出:
两个string，在一个行上
第一个：输入是否合法
第二个：如果合法输出结果
输入范例:
123.07 8796
输出范例:
true 8919.07
或者
false ""
 */

#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int MAX = 1000;

char num1[MAX];
char num2[MAX];

// -12.345   true
bool ok(char *num) {
    char ch;
    int stat = 0;  // 0:init  1:sign  2:nums  3:.  4:nums   5:failed
    while (*num != '\0') {
        ch = *num;
        num++;
        switch (stat) {
            case 0:
                if (ch == '+' || ch == '-')
                    stat = 1;
                else if (ch >= '0' && ch <= '9')
                    stat = 2;
                else
                    stat = 5;
                break;
            case 1:
                if (ch >= '0' && ch <= '9')
                    stat = 2;
                else
                    stat = 5;
                break;
            case 2:
                if (ch >= '0' && ch <= '9')
                    stat = 2;
                else if (ch == '.')
                    stat = 3;
                else
                    stat = 5;
                break;
            case 3:
                if (ch >= '0' && ch <= '9')
                    stat = 4;
                else
                    stat = 5;
                break;
            case 4:
                if (ch >= '0' && ch <= '9')
                    stat = 4;
                else
                    stat = 5;
                break;
            default:
                break;
        }
    }
    bool ret = false;
    if (stat == 2 || stat == 4) ret = true;
    return ret;
}

int main() {
    scanf("%s", num1);
    scanf("%s", num2);

    if (!ok(num1) || !ok(num2)) {
        printf("false \"\"\n");
    } else {
        printf("ok\n");
    }

    return 0;
}