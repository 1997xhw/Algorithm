//
// Created by 徐浩闻 on 2023/11/8.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
    int f(string s, int k) {
        int res = 0;
        for (int m = 1; m <= 26 && k * m <= s.length(); m++) {
            int cnt[26]{};
            int right, left;
            auto check = [&]() {
                for (int i = 0; i < 26; i++) {
                    if (cnt[i] && cnt[i] != k) {
                        return;
                    }
                }
                res++;
            };
            for (right = 0; right < s.length(); right++) {
                cnt[s[right] - 'a']++;
                left = right + 1 - k * m;
                if (left >= 0) {
                    check();
                    cnt[s[left] - 'a']--;
                }
            }
        }
        return res;
    }

public:
    int countCompleteSubstrings(string word, int k) {
        int n = word.length();
        int ans = 0;
        for (int i = 0; i < n;) {
            int st = i;
            for (i++; i < n && abs(int(word[i]) - int(word[i - 1])) <= 2; i++);
            ans += f(word.substr(st, i - st), k);
        }
        return ans;
    }
};


int main() {
    Solution s;
//    string word = "";
    string word = "";
//    cout << "word.size:" << word.size() << endl;
    cout << s.countCompleteSubstrings(word, 3846);
//    cout << s.countCompleteSubstrings(word, 12210);




}