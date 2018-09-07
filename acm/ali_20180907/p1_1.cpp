/*
 * by lizhen
 */
#include <iostream>
#include <list>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

#define DEBUG
using namespace std;

size_t len;
unordered_multimap<size_t, pair<size_t, size_t>> uom;
unsigned maxgrade = 0;
list<int> wordset;
list<int> curwordset;
vector<string> dict;
unsigned tmp;

void dfs(size_t index, unsigned grade) {
    if (index == len) {
        if (grade > maxgrade) {
            maxgrade = grade;
            wordset = curwordset;
        }
        return;
    }
    auto range = uom.equal_range(index);
    if (range.first == uom.end()) return;
    for (auto it = range.first; it != range.second; ++it) {
        curwordset.push_back(it->second.second);
        tmp = dict[it->second.second].length();
        dfs(it->second.first, grade + tmp * tmp);
        curwordset.pop_back();
    }
}

int main() {
    string sentence;
    cin >> sentence;
    len = sentence.length();
    int dictlen;
    cin >> dictlen;
    int i;
    string tmp;
    for (i = 0; i < dictlen; ++i) {
        cin >> tmp;
        dict.push_back(tmp);
    }
#ifdef DEBUG
    for (auto &item : dict) {
        cout << item << endl;
    }
#endif
    size_t index;
    for (i = 0; i < dictlen; ++i) {
        index = sentence.find(dict[i]);
        if (index == string::npos) continue;
        uom.insert(make_pair(index, make_pair(index + dict[i].length(), i)));
    }
#ifdef DEBUG
    for (auto &item : uom) {
        cout << dict[item.second.second] << " " << item.first << " "
             << item.second.first << endl;
    }
#endif
    dfs(0, 0);
    for (auto &item : wordset) {
        cout << dict[item] << " ";
    }
    cout << endl;
    return 0;
}
