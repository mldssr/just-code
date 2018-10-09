#include <cstdio>
#include <cstring>

/*
scanf()
int scanf ( const char * format, ... )
A single whitespace in the format string validates any quantity of whitespace characters extracted from the stream (including none).
(whitespace characters include spaces, newline and tab characters -- see isspace)
 */
void test_scanf() {
    // %c: 匹配下一字符，包括空白字符
    char ch;
    scanf("%c", &ch);  // 输入 A 并按下回车，回车键会影响到接下来的输入语句
    scanf("%c", &ch);  // 获取到回车
    scanf("%c", &ch);  // 输入 A 并按下回车
    scanf(" %c", &ch); // 空格保证之前的回车被忽略

    // %s: 匹配非空字符，遇到第一个空字符停止（这个空字符处于未读状态）
    char str[100];
    scanf("%s", str);   // 输入 A 并按下回车，回车键会影响到接下来的输入语句
    scanf("%c", &ch);   // 获取到回车

    // 不会跳过未匹配的字符
    int tmp;
    while (1) {
        if (scanf("%d", &tmp) != 1) { /* 输入 "abc" 会产生死循环*/
            printf("Invalid input. Try again\n");
        } else {
            break;
        }
    }
}


/*
fgets()
char * fgets ( char * str, int num, FILE * stream );
最多读取 num-1 个字符，遇到回车或EOF提前终止
回车也是个有效字符
 */

void test_fgets() {
    char line[10];

    // 输入 ABC\n，line为 ABC\n\0
    if (fgets(line, sizeof line, stdin) == NULL) {
        printf("Input error.\n");
    }
    line[strcspn(line, "\n")] = 0; /* removes the trailing newline, if present */
}

int main() {
    return 0;
}