//
// Created by 徐浩闻 on 2024/1/28.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>> &composition, vector<int> &stock,
                          vector<int> &cost) {
        function<bool(int)> isValid = [&](int target) -> bool {
            for (int i = 0; i < k; i++) {
                long long remain = budget;
                auto com = composition[i];
                for (int j = 0; j < n; j++) {
                    long long need = max(0, target * com[j] - stock[j]);
                    remain -= need * cost[j];
                }
                if (remain >=0) return true;
            }
            return false;
        };
        long long l = 0, r = budget + stock[0];
        while (l < r) {
            long long mid = l + r >> 1;
            if (isValid(mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};

int main() {


}