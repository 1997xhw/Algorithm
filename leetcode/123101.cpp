//
// Created by 徐浩闻 on 2023/12/31.
//
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int sum = 0;
        for (auto &item: nums) {
            if(item%2==0) sum++;
        }
        if(sum >= 2) return true;
        else return false;
    }
};
int main() {


}