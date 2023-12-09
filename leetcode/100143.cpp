//
// Created by 徐浩闻 on 2023/12/10.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:

    int countTestedDevices(vector<int> &batteryPercentages) {
        int n = batteryPercentages.size();
        int td = 0;

        for (int i = 0; i < n; ++i) {
            if (batteryPercentages[i] - td > 0) {
                td++;
            }
        }

        return td;
    }
};

int main() {
    vector<int> bp = {1, 1, 2, 1, 3};
    Solution s;
    cout << s.countTestedDevices(bp);

}