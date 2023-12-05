//
// Created by 徐浩闻 on 2023/11/30.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<long long> wa1(30, 0);
        vector<long long> wa2(30, 0);

        for (int i: word1) {
            wa1[i - 97]++;
        }
        for (int i: word2) {
            wa2[i - 97]++;
        }
        for (int i = 0; i < 28; i++) {
            if (wa1[i] * wa2[i] == 0 && (wa1[i] != 0 || wa2[i] != 0)) return false;
        }


        sort(wa1.begin(), wa1.end(), greater<int>());
        sort(wa2.begin(), wa2.end(), greater<int>());

        int i = 0, j = 0;
        while (i < wa1.size() && j < wa2.size()) {
            if (wa1[i] != wa2[j]) return false;
            i++, j++;
        }
        if (i < wa1.size() || j < wa2.size()) return false;

        return true;
    }
};

int main() {
    Solution s;
    cout << s.closeStrings("cabbba", "abbccc") << endl;

}