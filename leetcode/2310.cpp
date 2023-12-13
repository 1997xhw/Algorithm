//
// Created by 徐浩闻 on 2023/12/12.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minimumNumbers(int num, int k) {
        if (num == 0) return 0;
        for (int i = 1; i <= num; i++) {
            if((num-i*k)<0) break;
            if((num-i*k)%10==0) return i;
        }
        return -1;

    }
};

int main() {
    Solution s;
    cout << s.minimumNumbers(58, 9);

}
