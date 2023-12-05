//
// Created by 徐浩闻 on 2023/12/4.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size()<k) return false;
        unordered_map<char, int> map;
        for (const auto &item: s) {
            map[item]++;
        }
        int a = 0, b = 0;
        for (const auto &item: map) {
            a +=  item.second % 2;
            b+= item.second / 2;
        }
        cout << "a: " << a << " b:" << b << endl;

        if ((b>=k && a<=k)||((b<k)&&(a<=k)&&(a+b>=k)) || ((a + b < k) && (a+2*b>=k))) return true;
        else return false;
    }
};

int main() {

    Solution s;
    cout << s.canConstruct("abcdefghijklmnopqrstuvwxyz", 25) << "\n";

}