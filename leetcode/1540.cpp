//
// Created by 徐浩闻 on 2024/1/26.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        unordered_map<int, int> mp;
        if(s == t) return true;
        if(s.size() != t.size()) return false;
        for (int i = 0; i < s.length(); i++) {
            int cha = (t[i] - s[i] + 26) % 26;
            if (cha == 0) continue;
            mp[cha]++;
            cout << mp.count(cha) << endl;
            if (cha + (mp[cha]-1)*26 > k) return false;
        }
        return true;
    }
};

int main() {
    Solution s;
    cout << s.canConvertString("jicfxaa", "ocxltbp", 15) << endl;

}