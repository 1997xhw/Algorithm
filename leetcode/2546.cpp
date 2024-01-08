//
// Created by 徐浩闻 on 2024/1/6.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        pair<int, int> cnt_s{0, 0}, cnt_t = {0, 0};
        for (auto &item: s) item == '0' ? cnt_s.first++ : cnt_s.second++;
        for (auto &item: target) item == '0' ? cnt_t.first++ : cnt_t.second++;
        if (cnt_s.second==0 && cnt_t.second!=0) return false;
        if(cnt_s.second!=0 && cnt_t.second==0) return false;
        return true;
    }
};

int main() {


}