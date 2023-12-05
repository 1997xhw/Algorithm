//
// Created by 徐浩闻 on 2023/12/5.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        map<char, int> first;
        map<char, int> last;
        int len = s.length();
        for (int i = 0; i < len; i++) {
            if (first.count(s[i])) {
                last[s[i]] = i;
            } else {
                first[s[i]] = i;
            }
        }

        int ans = 0;
        for (char i = 'a'; i < 'a' + 26; i++) {
            if (!first.count(i) || !last.count(i)) continue;
            int left = first[i], right = last[i];
            vector<int> cnt(26);
            for (int j = left + 1; j < right; j++) {
                cnt[s[j] - 'a'] = 1;
            }

            for (int j = 0; j < 26; j++) {
                if (cnt[j] == 1) ans++;
            }
        }
        return ans;

    }
};

int main() {


}