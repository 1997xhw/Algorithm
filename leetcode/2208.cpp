//
// Created by 徐浩闻 on 2023/12/10.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int halveArray(vector<int> &nums) {
        priority_queue<double> heap;
        double sum = 0.0;
        for (auto &num: nums) {
            heap.emplace(num);
            sum += num;
        };
        int cnt = 0;
        double half = sum / 2;
        while (sum > half) {
            double tmp = heap.top();
            heap.pop();
            sum -= tmp / 2;
            heap.push(tmp / 2);
            cnt++;
        }
        return cnt;

    }
};

int main() {
    vector<int> nums = {3,8,20};
    Solution s;
    cout << s.halveArray(nums);
}