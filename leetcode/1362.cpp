//
// Created by 徐浩闻 on 2023/12/5.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> closestDivisors(int num) {
        int mid = sqrt(num + 2);
        int n1 = num + 1;
        int n2 = num + 2;
        vector<int> a;
        while (mid != 0) {
            if (n1 % mid == 0) {
                a = {mid, n1 / mid};
                return a;
            }
            if (n2 % mid == 0) {
                a = {mid, n2 / mid};
                return a;
            }
            mid -= 1;
        }
        return a;
    }
};

int main() {
    Solution s;
    s.closestDivisors(8);

}