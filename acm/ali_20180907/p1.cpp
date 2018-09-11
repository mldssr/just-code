/*
智能分词

分词是指将一个字符串分割成词语序列，其中所有词语都来自事先指定的词汇表。例如：
有字符串"github"，以及词汇表["git", "hub"]，那么分词方式为:"git hub"。

分词可能有多重方式，例如字符串"asdfjkl"，以及词汇表["as", "asd", "df", "fjkl",
"jkl"]，可能有两种分词方法:"as df jkl"、"asd
fjkl"。先定义每种分词方法的合理性得分为：分词方案中每个单词长度的平方和。例如上述两种分词方案的得分分别为
2^2 + 2^2 + 3^2 = 17，以及 3^2 + 4^2 = 25。

现给出词汇表（均为小写字母，单词最长50字符，最多10个万单词），以及一句话（均为小写字母，最长10万字符），找出最合理的分词方案。若有多种得分相同的最合理方案，输出长词尽量靠前的方案。例如"ab
cdef"与"abcd ef"这两种最优方案得分相同，输出"abcd ef"。

编译器版本: gcc 4.8.4
请使用标准输入输出(stdin，stdout)
；请把所有程序写在一个文件里，勿使用已禁用图形、文件、网络、系统相关的头文件和操作，如sys/stat.h
, unistd.h , curl/curl.h , process.h 时间限制: 3S (C/C++以外的语言为: 5 S)
内存限制: 128M (C/C++以外的语言为: 640 M) 输入:
第一行为待分语句；第二行为词汇表中的单词数量N；接下来N行，每行一个单词。
输出:
一行，分隔后的语句，以空格分隔各个单词。
输入范例:
asdfjkl
5
as
asd
df
fjkl
jkl
输出范例:
asd fjkl
 */

// #include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

set<string> dict;
vector<int> ans;
int matched_len = 0;

bool matched(string word) {
    auto search = dict.find(word);
    if (search != dict.end()) {
        return true;
    }
    return false;
}

// 返回 str 从 start 下标开始能匹配到的最大单词的长度
int max_match(string str, int start) {
    int str_len = str.length();
    int left_len = str_len - start;
    int len = left_len < 50 ? left_len : 50;
    for (; len > 0; --len) {
        if (matched(str.substr(start, len))) {
            break;
        }
    }
    return len;
}

int main() {
    string str;
    cin >> str;
    int num;
    cin >> num;

    string tmp;
    for (int i = 0; i < num; ++i) {
        cin >> tmp;
        dict.insert(tmp);
    }

    while (matched_len < str.length()) {
        int max = max_match(str, matched_len);
        printf("Matched %d chars\n", max);
        if (max > 0) {
            matched_len += max;
            ans.push_back(max);
        }
    }

    int printed = 0;
    for (unsigned int i = 0; i < ans.size() - 1; ++i) {
        cout << str.substr(printed, ans[i]) << " ";
        printed += ans[i];
    }
    cout << str.substr(printed, ans[ans.size() - 1]);

    return 0;
}