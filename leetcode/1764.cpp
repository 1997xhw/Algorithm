//
// Created by 徐浩闻 on 2023/12/19.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int i, j;
        for(i = 0, j = 0; i < nums.size() && j < groups.size();) {
            if((i + groups[j].size()-1 < nums.size()) && check(groups[j], nums, i)) {
                i+=groups[j].size();
                j++;
            }else {
                i++;
            }
        }
        if(j == groups.size()) return true;
        else return false;
    }

    bool check(vector<int>a, vector<int> nums, int i) {
        for (auto j : a) {
            if(j != nums[i]) return false;
            i++;
        }
        return true;
    }
};

int main() {


}
