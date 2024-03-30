//
// Created by 徐浩闻 on 2024/3/28.
//
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        const int MOD = 1000000007;
        int n = nextVisit.size();
        vector<long> s(n);
        for (int i = 0; i < n - 1; ++i) {
            int j = nextVisit[i];
            s[i + 1] = (s[i] * 2 + 2 - s[j] + MOD) % MOD;
        }
        return s[n-1];
    }
};
int main() {


}