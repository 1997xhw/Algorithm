//
// Created by 徐浩闻 on 2024/1/7.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    pair<float, long long> mm = {0, 0};

    int areaOfMaxDiagonal(vector<vector<int>> &dimensions) {
        for (auto &i: dimensions) {
            float x = sqrt(i[0] * i[0] + i[1] * i[1]);
            long long y = i[0] * i[1];
            if ((mm.first == x && mm.second < y) || mm.first < x) {
                mm = {x, y};
            }

        }
        return (int)mm.second;
    }
};
int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {

}

int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> freq;
    // Count the frequency of each element in both arrays
    for (int num : nums1) freq[num]++;
    for (int num : nums2) freq[num]++;

    // Create a max heap to store the elements based on their frequency
    priority_queue<pair<int, int>> maxHeap;
    for (auto& it : freq) {
        maxHeap.push({it.second, it.first});
    }

    int n = nums1.size();
    int toRemove = n / 2;

    while (toRemove > 0 && !maxHeap.empty()) {
        auto top = maxHeap.top();
        maxHeap.pop();
        int count = min(top.first, toRemove);
        freq[top.second] -= count;
        toRemove -= count;
    }

    int uniqueElements = 0;
    for (auto& it : freq) {
        if (it.second > 0) uniqueElements++;
    }

    return uniqueElements;
}

int main() {


}