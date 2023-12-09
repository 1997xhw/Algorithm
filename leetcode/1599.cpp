//
// Created by 徐浩闻 on 2023/12/9.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minOperationsMaxProfit(vector<int> &customers, int boardingCost, int runningCost) {
        int tax_max = -1;
        pair<int, int> ans = {-1, -1};
        int tax_now = 0;
        int waiter = 0;
        int time = 0;
        while (time < customers.size() || waiter > 0) {
            if (time < customers.size()) {
                waiter += customers[time];
            }
            int boarder = waiter > 4 ? 4 : waiter;
            tax_now += boarder * boardingCost - runningCost;
            waiter -= boarder;
            time++;
            if (tax_now > ans.first) ans = {tax_now, time};
        }
        return ans.second > 0 ? ans.second : -1;

    }
};

int main() {
    vector<int> customers = {10, 9, 6};
    Solution s;
    cout << s.minOperationsMaxProfit(customers, 6, 4);

}