//
// Created by 徐浩闻 on 2024/2/8.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maximumCandies(vector<int> &candies, long long k) {
        sort(candies.begin(), candies.end());
        long long sum = 0;
        for (auto &item: candies) sum += item;
        if (sum < k) return 0;
        long long left = 1, right = sum / k + 1;
        auto check = [&](int mid) -> bool {
            long long cnt = 0;
            for (auto &item: candies) {
                cnt += item / mid;
            }
            if (cnt >= k) return true;
            else return false;
        };
        while (left < right) {
            long long mid = (left + right) / 2;
            if (check(mid)) left = mid + 1;
            else right = mid;
        }
        return left-1;
    }
};

int main() {


}