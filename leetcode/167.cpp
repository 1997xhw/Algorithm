//
// Created by 徐浩闻 on 2023/12/18.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        for (int i = 0; i < numbers.size() - 1; i++) {
            int left = i + 1, right = numbers.size();
            int tt = target - numbers[i];

            while (left < right) {
                int mid = left + right / 2;
                cout << left << " " << right << " " <<mid <<endl;
                if (numbers[mid] < tt) left = mid + 1;
                else right = mid;
            }
            if (left < numbers.size() && numbers[i] + numbers[left] == target) return {i+1, left+1};
        }
        return {-1, -1};
    }
};

int main() {
    vector<int> numbers = {2, 7, 11, 15};
    int target = 5;
    Solution s;
    vector<int> pp = s.twoSum(numbers, target);
    cout << pp[0] << " " << pp[1];
}