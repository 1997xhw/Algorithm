//
// Created by 徐浩闻 on 2024/1/30.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string largestPalindromic(string num) {
        map<char, int> mp;
        for (auto &ch: num) {
            mp[ch]++;
        }
        string ans = "";
        int single = 0;
        string middle = "", half = "";
        for (auto it = mp.rbegin(); it != mp.rend(); ++it) {

            if (it->second % 2 == 1) {
                if (middle.empty())
                    middle = it->first;
                it->second--;
            }
            half +=string(it->second/2, it->first);
        }
        string rev_half = half;
        reverse(rev_half.begin(), rev_half.end());

        if (half.size()> 0 && half[0]=='0') {
            return middle.size() > 0 ? middle : "0";
        }
        return half + middle + rev_half;
    }
};

int main() {


}