//
// Created by 徐浩闻 on 2023/12/21.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {

public:
    int findDuplicate(vector<int> &nums) {
        int len = nums.size();
        int left = 1, right = len - 1;
        while (left < right) {
            int mid = (left + right) >> 1;

            int cnt = 0;
            for (auto &item: nums) {
                if(item <= mid) cnt++;
            }

            if(cnt > mid) right = mid; else left = mid + 1;
        }
        return left;
    }

};

int main() {


}