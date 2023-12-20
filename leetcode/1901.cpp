//
// Created by 徐浩闻 on 2023/12/19.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:

    vector<int> findPeakGrid(vector<vector<int>> &mat) {
        int left = 0, right = mat.size() - 1;
        while (left < right) {
            int i = left + right >> 1;
            int j = max_element(mat[i].begin(), mat[i].end()) - mat[i].begin();
            if (mat[i][j] > mat[i + 1][j]) {
                right = i;
            } else {
                left = i + 1;
            }
        }
        right = max_element(mat[left].begin(), mat[left].end()) - mat[left].begin();
        return {left, right};

    }
};

int main() {


}