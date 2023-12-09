//
// Created by 徐浩闻 on 2023/12/8.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool canReorderDoubled(vector<int> &arr) {
        unordered_map<int, int> arrs;
        for (auto &item: arr) arrs[item]++;
        sort(arr.begin(), arr.end());
        if (arrs[0] % 2) return false;
        vector<int> vals;
        vals.reserve(arrs.size());
        for (auto &[x, _]: arrs) vals.emplace_back(x);
        sort(vals.begin(), vals.end(), [](int a, int b) { return abs(a) < abs(b); });
        for (auto &val: vals) {
            if(arrs[val*2] < arrs[val]) return false;
            arrs[2*val] -= arrs[val];
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<int> arr = {3, 1, 3, 6};
    cout << s.canReorderDoubled(arr);

}