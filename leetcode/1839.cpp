//
// Created by 徐浩闻 on 2023/12/19.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int longestBeautifulSubstring(string word) {
        stack<char> cword;
        unordered_map<char, int> vis;
        int i, j, max_len = 0, freq = 0;
        for (i = 0, j = 0; j < word.length();) {
            if (cword.empty() || cword.top() <= word[j]) {
                vis[word[j]]++;
                if (vis[word[j]] == 1) freq++;
                cword.push(word[j++]);
                if (cword.top() == 'u' && freq == 5) max_len = max(max_len, static_cast<int>(cword.size()));
            } else if (cword.top() > word[j]) {
                while (!cword.empty()) {
                    vis[cword.top()]--;
                    cword.pop();
                }
                i = j;
                freq = 0;
            }
        }
        return max_len;
    }
};

int main() {
    string s = "u";
    Solution ss;
    cout << ss.longestBeautifulSubstring(s);
}