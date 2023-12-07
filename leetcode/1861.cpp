//
// Created by 徐浩闻 on 2023/12/6.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>> &box) {
        int m = box.size(), n = box[0].size();
        vector<vector<char>> ans(n, vector<char>(m, '.'));
        for (int i = 0; i < m; i++) {
            int stone = 0;
            for (int j = 0; j < n; j++) {
                char b = box[i][j];
                if (b == '#') {
                    stone++;
                } else if (b == '*') {
                    ans[j][m - i - 1] = '*';
                    for (int jj = j - 1; jj >= j - stone; jj--) {
                        ans[jj][m - i - 1] = '#';
                    }
                    stone = 0;
                }
            }
            int jj = n - 1;
            cout << stone << endl;
            while (stone) {
                ans[jj][m - i - 1] = '#';
                stone--;
                jj--;
            }
        }
        return ans;
    }
};

int main() {


}