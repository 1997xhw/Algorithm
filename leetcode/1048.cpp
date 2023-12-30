//
// Created by 徐浩闻 on 2023/12/30.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int longestStrChain1(vector<string> &words) {
        unordered_map<string, int> hs;
        for (auto &w: words) hs[w] = 0;
        function<int(string)> dfs = [&](string s) -> int {
            int res = hs[s];
            if (res) return res;
            for (int i = 0; i < s.length(); i++) {
                auto t = s.substr(0, i) + s.substr(i + 1);
                if (hs.count(t)) res = max(res, dfs(t));
            }
            return hs[s] = res + 1;
        };
        int res = 0;
        for (auto &[s, _]: hs) {
            res = max(res, dfs(s));
        }
        return res;
    }

    int longestStrChain(vector<string> &words) {
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.length() < a.length();
        });
        int ans = 0;
        unordered_map<string, int> hs;
        for (auto &item: words) {
            int res = 0;
            for (int i = 0; i < item.length(); ++i) {
                auto it = hs.find(item.substr(0, i) + item.substr(i + 1));
                if (it != hs.end()) res = max(res, it->second);
            }
            ans = max(ans, hs[item] = res + 1);
        }
        return ans;
    }
};

int main() {


}