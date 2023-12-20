//
// Created by 徐浩闻 on 2023/12/18.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int n = 0, m = 0;

    pair<int, int> countij(int ind) {
        int x = ind / m;
        int y = ind % m;
        return {x, y};
    }

    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        n = matrix.size(), m = matrix[0].size();
        int left = 0, right = n * m;
        while(left < right) {
            int mid = (left + right) >> 1;
            pair<int, int> xy = countij(mid);
            if(matrix[xy.first][xy.second] < target) left = mid + 1;
            else if(matrix[xy.first][xy.second] > target){
                right = mid;
            } else return true;
        }
        return false;
    }

};

int main() {


}