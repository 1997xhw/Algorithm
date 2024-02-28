//
// Created by 徐浩闻 on 2024/2/28.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    long long numberOfWays(string s) {
        vector<pair<int, int>> left, right;
        left.emplace_back(make_pair(0, 0));
        right.emplace_back(make_pair(0, 0));
        int len = s.length();
        for (int i = 1; i <= len; i++) {
            if (s[i - 1] == '0')
                left.emplace_back(left[i - 1].first + 1, left[i - 1].second);
            else left.emplace_back(left[i - 1].first, left[i - 1].second + 1);
        }
        left.erase(left.begin());

        int j = 1;
        for (int i = len - 1; i >= 0; i--) {
            if (s[i] == '0')
                right.emplace_back(right[j - 1].first + 1, right[j - 1].second);
            else right.emplace_back(right[j - 1].first, right[j - 1].second + 1);
            j++;
        }
        right.erase(right.begin());
        reverse(right.begin(), right.end());

        long long cnt = 0;
        for (int i = 1; i < len - 1; ++i) {
            if (s[i] == '1') cnt = cnt + left[i - 1].first * right[i + 1].first;
            else cnt = cnt + left[i - 1].second * right[i + 1].second;
        }
        return cnt;
    }
};

int main() {
    Solution s;
    cout << s.numberOfWays("001101");

}