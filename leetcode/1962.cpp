//
// Created by 徐浩闻 on 2023/12/23.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minStoneSum(vector<int> &piles, int k) {
        priority_queue<int, vector<int>, less<int>> heap;
        for (auto &item: piles) {
            heap.push(item);
        }
        for (int i = 0; i < k; i++) {
            int tmp = heap.top() - heap.top()/2;
            heap.pop();
            heap.push(tmp);
        }
        int res  = 0;
        while(!heap.empty()) {
            res+=heap.top();
            heap.pop();
        }
        return res;
    }
};

int main() {


}