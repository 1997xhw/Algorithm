//
// Created by 徐浩闻 on 2024/1/26.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int countWays(vector<vector<int>> &ranges) {
        sort(ranges.begin(), ranges.end(), less<vector<int>>());
        stack<pair<int, int>> st;
        for (int i = 0; i < ranges.size(); ++i) {
            if (st.empty()) st.push({ranges[i][0], ranges[i][1]});
            else {
                pair<int, int> tmp = st.top();
                if (tmp.second >= ranges[i][0] && tmp.second < ranges[i][1]) {
                    st.pop();
                    st.push({tmp.first, ranges[i][1]});
                }
                if (tmp.second < ranges[i][0]) st.push({ranges[i][0], ranges[i][1]});
            }
        }
        const int MOD = 1e9 + 7;
        long long ans = 1;
        for (int i = 1; i <= st.size(); i++) ans = ans * 2 % MOD;
        return ans;
    }
};

int main() {
    vector<vector<int>> ranges = {{6, 10},
                                  {5, 15},
                                  {1, 2},
                                  {2, 4}};
    Solution s;
    cout << s.countWays(ranges);

}