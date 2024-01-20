//
// Created by 徐浩闻 on 2024/1/19.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int numberOfArrays(vector<int> &differences, int lower, int upper) {
        long long ll = 0, rr = 0, tmp = 0;
        for (auto &d: differences) {
            tmp += d;
            ll = min(ll, tmp);
            rr = max(rr, tmp);
        }
        cout << ll << " " << rr << endl;
        long long ans = upper - lower - (rr - ll) + 1;
        return ans > 0 ? ans : 0;

    }
};

int main() {
    vector<int> diff = {-40};
    Solution s;
    cout << s.numberOfArrays(diff, -46, 53);

}