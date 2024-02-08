//
// Created by 徐浩闻 on 2024/1/28.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> prevPermOpt1(vector<int> &arr) {
        int n = arr.size();
        for (int i = n - 1; i > 0; i--) {
            if (arr[i] < arr[i - 1]) {
                for (int j = n - 1; j > i - 1; --j) {
                    if (arr[j] < arr[i-1] &&arr[j]!=arr[j-1]) {
                        swap(arr[i-1], arr[j]);
                        return arr;
                    }
                }
            }
        }
        return arr;
    }
};

int main() {


}