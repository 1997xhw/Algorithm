//
// Created by 徐浩闻 on 2024/1/7.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<int, int> nums;
        for (auto &item: magazine) {
            nums[item - 'a']++;
        }
        for (auto &item: ransomNote) {
            if (nums.find(item - 'a') == nums.end() || nums[item - 'a'] == 0) return false;
            else {
                nums[item - 'a']--;
            }
        }
        return true;
    }
};

int main() {


}