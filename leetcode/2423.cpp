//
// Created by 徐浩闻 on 2024/2/14.
//
#include "bits/stdc++.h"
using namespace std;
class Solution {
    bool is_same(unordered_map<char, int> &cnt) {
        int c0 = cnt.begin()->second;
        for (auto &[_, c]: cnt)
            if (c != c0)
                return false;
        return true;
    }
public:
    bool equalFrequency(string word) {
        int n = word.length();
        for (int i = 0; i < n; ++i) { // 枚举删除的字符
            unordered_map<char, int> cnt;
            for (int j = 0; j < n; ++j)
                if (j != i)
                    ++cnt[word[j]]; // 统计出现次数
            if (is_same(cnt)) // 出现次数都一样
                return true;
        }
        return false;
    }
};

int main() {


}
