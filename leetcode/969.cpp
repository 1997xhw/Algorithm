//
// Created by 徐浩闻 on 2023/12/24.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> pancakeSort(vector<int> &arr) {
        vector<int> res;
        int n = arr.size();
        for (int i = 0; i < arr.size(); i++) {
            auto max = max_element(arr.begin(), prev(arr.end(), i));
            if (max == prev(arr.end(), i+1)) continue;
            else {
                reverse(arr.begin(), next(max));
//                cout << max - arr.begin() << endl;
                res.emplace_back((max - arr.begin()) + 1);
                reverse(arr.begin(), prev(arr.end(), i));
                res.emplace_back(n - i);
            }
        }
        return res;
    }
};

int main() {
    vector<int> arr = {3,2,4,1};
    Solution s;
    vector<int> res = s.pancakeSort(arr);
    for (auto &item: res) {
        cout << item << " ";
    }

}