//
// Created by 徐浩闻 on 2024/2/8.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> dict;
        int n = s.length();
        dict['a'] = 0;
        dict['b'] = 0;
        dict['c'] = 0;
        int cnt = 0;
        for (int i = 0, j = 0; i <= n - 3; i++) {
            if (i != 0) dict[s[i - 1]]--;
            while ((dict['a'] == 0 || dict['b'] == 0 || dict['c'] == 0) && j < n) {
                dict[s[j]]++;
                j++;
            }
            if (dict['a'] > 0 && dict['b'] > 0 && dict['c'] > 0) {
                cnt += n - j + 1;
            }
        }
        return cnt;
    }
};

int main() {
    Solution s;
    cout << s.numberOfSubstrings("abcabc");

}