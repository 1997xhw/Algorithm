//
// Created by 徐浩闻 on 2023/12/17.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> divideArray(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> temp;
        for (int num : nums) {
            if (temp.empty() || abs(num - temp[0]) <= k) {
                temp.push_back(num);
                if (temp.size() == 3) {
                    result.push_back(temp);
                    temp.clear();
                }
            } else {
                return {};
            }
        }
        return result;
    }
};

int main() {


}