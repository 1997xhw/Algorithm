//
// Created by 徐浩闻 on 2024/1/17.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maximumNumberOfStringPairs(vector<string> &words) {
        int ans = 0;
        unordered_map<string, int> mp;
        for (int i = 0; i < words.size(); i++) {
            if (mp.find(words[i])!=mp.end()) {
                ans += mp[words[i]];
            }
            string reversed = words[i];
            reverse(reversed.begin(), reversed.end());
            mp[reversed]++;
        }
        return ans;
    }
};

int main() {


}