//
// Created by 徐浩闻 on 2023/12/24.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int numWays(string s) {
        long long len = s.length(), cnt = 0;
        unordered_map<long long, long long> mp;
        for (int i = 0; i < len; i++) {
            if(s[i] == '1') {
                cnt++;
                mp[cnt] = i;
            }
        }
        if(cnt == 0) return ((len-1)*(len-2)/2) % 1000000007;
        if(cnt %3!=0) return 0;
        long long t = cnt / 3;
        return ((mp[t+1]-mp[t])*(mp[2*t+1]-mp[2*t]))% 1000000007;
    }
};

int main() {
    Solution s;
    cout << s.numWays("100100010100110");

}