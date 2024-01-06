//
// Created by 徐浩闻 on 2024/1/5.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minimumPartition(string s, int k) {
        long long ans = 1, tmp = 0;
        for (int i = 0; i < s.length(); i++) {
            if(s[i] - '0' > k) return -1;
            tmp = tmp* 10 + s[i]-'0';
            if (tmp > k) {
                ans++;
                tmp = s[i]-'0';
            }
        }
        return ans;
    }
};

int main() {


}
