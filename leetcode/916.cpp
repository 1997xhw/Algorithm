//
// Created by 徐浩闻 on 2024/1/25.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2) {
        unordered_map<char, int> mp;
        for (auto &item: words2) {
            unordered_map<char, int> mp2;
            for (auto &ch: item) {
                mp2[ch]++;
                mp[ch] = max(mp[ch], mp2[ch]);
            }
        }
        vector<string> ans;
        for (auto &item: words1) {
            bool flag = true;
            for (auto &ch: mp) {
                if (count(item.begin(), item.end(), ch.first) >= ch.second) continue;
                else {
                    flag = false;
                    break;
                }
            }
            if (flag) ans.emplace_back(item);
        }
        return ans;
    }
};

int main() {
    vector<string> word1 = {"amazon", "apple", "facebook", "google", "leetcode"};
    vector<string> word2 = {"lo", "eoo"};
    Solution s;
    s.wordSubsets(word1, word2);

}