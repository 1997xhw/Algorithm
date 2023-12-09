//
// Created by 徐浩闻 on 2023/12/10.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int xorBeauty(vector<int> &nums) {
        int ans = 0;
        for (int x : nums) ans ^= x;
        return ans;
    }
};

int main() {


}