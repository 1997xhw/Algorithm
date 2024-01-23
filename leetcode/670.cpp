//
// Created by 徐浩闻 on 2024/1/22.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        vector<int> mp;
        while (num) {
            mp.emplace_back(num % 10);
            num /= 10;
        }
        reverse(mp.begin(), mp.end());


        for (int i = 0; i < mp.size() - 1; ++i) {
            int tmp = mp[i], pos = i;
            for (int j = i + 1; j < mp.size(); j++) {
                if (mp[j] >= tmp) {
                    tmp = mp[j];
                    pos = j;
                }
            }
            if (pos == i) {
                continue;
            } else if (mp[pos] != mp[i]) {
                int tt = mp[i];
                mp[i] = tmp;
                mp[pos] = tt;
                break;
            }
        }
        int ans = 0;
        for (int i = 0; i < mp.size(); i++) {
            ans *= 10;
            ans += mp[i];

        }
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.maximumSwap(98368);

}