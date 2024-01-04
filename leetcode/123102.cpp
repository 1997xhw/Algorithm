//
// Created by 徐浩闻 on 2023/12/31.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maximumLength2(string s) {
        int n = s.length();
        if (n < 3) return -1;
        vector<vector<int>> freq(n + 1, vector<int>(26, 0));
        unordered_map<char, int> hs;
        for (int i = 1; i <= n; ++i) {
            hs[s[i]]++;
            freq[i] = freq[i - 1];
            freq[i][s[i - 1] - 'a']++;
        }
        int maxLen = -1;
        for (auto &[c, _]: hs) {
            for (int len = 1; len <= n; ++len) {
                int count = 0;
                for (int start = 0; start <= n - len; ++start) {
                    if (freq[start + len][c - 'a'] - freq[start][c - 'a'] == len) {
                        count++;
                        if (count == 3) {
                            maxLen = max(maxLen, len);
                            break;
                        }
                    }
                }
            }
        }
        return maxLen;
    }

};

int main() {
    string s = "aaaa";
    Solution ss;
    cout << "Maximum length: " << ss.maximumLength(s) << endl;
    return 0;

}