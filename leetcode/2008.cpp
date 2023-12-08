//
// Created by 徐浩闻 on 2023/12/8.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>> &rides) {
        vector<vector<pair<int, int>>> groups(n + 1);
        for (auto &r: rides) {
            int start = r[0], end = r[1], tip = r[2];
            groups[end].emplace_back(start, end - start + tip);
        }
        vector<long long> f(n + 1);
        for (int i = 2; i <= n; ++i) {
            f[i] = f[i-1];
            for(auto&[s, t]:groups[i]) {
                f[i] = max(f[i], f[s]+t);
            }
        }
        return f[n];
    }
//    long long maxTaxiEarnings(int n, vector<vector<int>> &rides) {
//        vector<vector<pair<int, int>>> groups(n + 1);
//        for (auto &ride: rides) {
//            int start = ride[0], end = ride[1], tip = ride[2];
//            groups[end].emplace_back(start, end - start + tip);
//        }
//
//        vector<long long> memo(n + 1, -1);
//        function<long long(int)> dfs = [&](int i) -> long long {
//            if (i == 1) {
//                return 0;
//            }
//            auto &res = memo[i];
//            if (res != -1) {
//                return res;
//            }
//            res = dfs(i - 1);
//            for (auto &[s, t]: groups[i]) {
//                res = max(res, dfs(s)+t);
//            }
//            return res;
//        };
//        return dfs(n);
//    }
};

int main() {


}