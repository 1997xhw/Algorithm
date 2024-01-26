//
// Created by 徐浩闻 on 2024/1/25.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minimumBuckets(string hamsters) {
        int pre = -2, ans = 0, n = hamsters.size();
        for (int i = 0; i < n; i++) {
            if (hamsters[i] == 'H') {
                if (pre == i - 1) {
                    continue;
                } else if (i + 1 < n && hamsters[i + 1] == '.') {
                    pre = i + 1;
                    ans++;
                } else if (i - 1 >= 0 && hamsters[i-1]=='.') {
                    pre = i-1;
                    ans++;
                } else {
                    return -1;
                }
            }
        }
        return ans;
    }
};

int main() {


}