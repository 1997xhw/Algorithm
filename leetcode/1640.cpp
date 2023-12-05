//
// Created by 徐浩闻 on 2023/12/2.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        for (int i = 0; i < arr.size();) {
            int k = 0;
            while (k < pieces.size() && pieces[k][0] != arr[i]) {
                ++k;
            }
            if (k == pieces.size()) {
                return false;
            }
            int j = 0;
            while (j < pieces[k].size() && arr[i] == pieces[k][j]) {
                ++i;
                ++j;
            }
        }
        return true;
    }
};

int main() {


}