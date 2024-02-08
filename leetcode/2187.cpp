//
// Created by 徐浩闻 on 2024/2/2.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    long long minimumTime(vector<int> &time, int totalTrips) {
        map<int, int> cars;
        for (auto &item: time) cars[item]++;
        long long l = 0, r = static_cast<long long>(cars.begin()->first) * totalTrips;
        while (l < r) {
            long long mid = (l + r) / 2;
            long long cnt = 0;
            bool flag = false;
            for (auto &item: cars) {
                cnt += mid / item.first * item.second;
                if (cnt >= totalTrips) {
                    flag = true;
                    break;
                }
            }
            if (!flag) l = mid + 1;
            else r = mid;
        }
        return l;
    }
};

int main() {
    Solution solution;
    vector<int> time = {10000};
    cout << solution.minimumTime(time, 10000000);

}