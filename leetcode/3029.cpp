//
// Created by 徐浩闻 on 2024/3/17.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        int n = word.length();
        string word2 = word;
        int cnt = 0;
        for (int i = 0; i < n / k; i++) {
            word2 = word2.substr(k, word2.length()-k);
            cnt++;
            if(word.find(word2)==0) return cnt;
        }
        return cnt+1;
    }
};

int main() {
    string s = "aab";
    Solution ss;
    cout << ss.minimumTimeToInitialState(s, 2);

}`