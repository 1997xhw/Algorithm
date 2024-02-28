//
// Created by 徐浩闻 on 2024/2/25.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string> &nums, vector<vector<int>> &queries) {
        set<int> trims;
        for (auto i: queries) {
            trims.insert(i[1]);
        }
        map<int, vector<pair<string, int>>> sortedNumsByTrim;
        for (auto trim: trims) {
            vector<pair<string, int>> trimmedNums;
            for (int i = 0; i < nums.size(); i++) {
                string trimmed = nums[i].substr(nums[i].length() - trim);
                trimmedNums.emplace_back(trimmed, i);
            }
            sort(trimmedNums.begin(), trimmedNums.end()); // 按裁剪后的字符串排序
            sortedNumsByTrim[trim] = trimmedNums;
        }
        vector<int> result;
        for (const auto &query: queries) {
            int k = query[0], trim = query[1];
            // 根据查询找到第k个最小元素的原始索引
            result.push_back(sortedNumsByTrim[trim][k - 1].second);
        }

        return result;
    }
};

int main() {


}