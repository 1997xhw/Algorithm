//
// Created by 徐浩闻 on 2023/11/10.
//
#include "bits/stdc++.h"

using namespace std;


class Solution {
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success) {
        vector<int> ans(spells.size());


        sort(potions.begin(), potions.end());

        int len = potions.size() - 1;
        for (int i = 0; i < spells.size(); i++) {
            int v = spells[i];
            if (potions[len] < success * 1.0 / v) {
                ans[i] = 0;
                continue;
            }
            int ll = 0, rr = len;
            while (ll < rr) {
                int mid = (ll + rr) >> 1;
//                cout << "mid" << mid << endl;
                if (potions[mid] >= success * 1.0 / v) rr = mid;
                else ll = mid + 1;
            }
//            cout << "ll: " << ll << endl;
            ans[i] = potions.size() - ll;

        }

        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> spells = {3, 1, 2};
    vector<int> potions = {8, 5, 8};
    int success = 16;
    for (auto i: solution.successfulPairs(spells, potions, success)) {
        cout << i << " ";
    }

}