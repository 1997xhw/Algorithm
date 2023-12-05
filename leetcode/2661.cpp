//
// Created by 徐浩闻 on 2023/12/1.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat) {
        int m = mat.size();
        int n = mat[0].size();
        cout << m << " " << n << endl;
        unordered_map<int, pair<int, int>> arr_map;
        int row[m], col[n];
        memset(row, 0, sizeof row);
        memset(col, 0, sizeof col);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                arr_map.insert({mat[i][j], {i, j}});
            }
        }
        for (int i = 0; i < arr.size(); i++) {
            pair<int, int> arr_item = arr_map[arr[i]];
            row[arr_item.first]++;
            col[arr_item.second]++;
            if (row[arr_item.first] == n || col[arr_item.second] == m) return i;
        }
        return 0;
    }
};

int main() {
    vector<vector<int>> mat = {{3,2,5},
                               {1,4,6},
                               {8,7,9}};
    vector<int> arr = {2,8,7,4,1,3,5,6,9};
    Solution s;
    cout << s.firstCompleteIndex(arr, mat) << endl;

}