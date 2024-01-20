//
// Created by 徐浩闻 on 2024/1/20.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string> &words, char separator) {
        vector<string> ans;
        for (auto &w: words) {
            while (w.find(separator) != w.npos) {

                string tmp = w.substr(0, w.find(separator));
                if (tmp != "")
                    ans.emplace_back(tmp);
                w = w.substr(w.find(separator) + 1, w.length());
            }
            if (w != "")
                ans.emplace_back(w);
        }
        return ans;
    }
};

int main() {
    vector<string> ss = {"$$", "$$"};
    Solution s;
    vector<string> ans = s.splitWordsBySeparator(ss, '$');
    for (auto &item: ans) {
        cout << item << " ";
    }

}