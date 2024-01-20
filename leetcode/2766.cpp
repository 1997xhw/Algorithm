//
// Created by 徐浩闻 on 2024/1/18.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> relocateMarbles(vector<int> &nums, vector<int> &moveFrom, vector<int> &moveTo) {
        set<int> mp;
        for (auto &item: nums) {
            mp.insert(item);
        }
        for (int i = 0; i < moveFrom.size(); i ++) {
            mp.erase(moveFrom[i]);
            mp.insert(moveTo[i]);
        }
        vector<int> ans;
        for (auto &item: mp) {
            ans.emplace_back(item);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main() {


}