//
// Created by 徐浩闻 on 2023/12/5.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int n2 = 0;
        while (num2) {
            if ((num2 & 1) == 1) n2++;
            num2 = num2 >> 1;
        }
        int tmp = num1;
        int n1 = 0;
        while (tmp) tmp = tmp >> 1, n1++;
        int i = n1 - 1;
        for (; i >= 0 && n2 > 0; i--) {
            if ((num1 >> i) & 1) n2--;
        }
        if (n2 == 0) {
            while (i>=0) {
                if ((num1 >> i) & 1) num1 -= (1 << i);
                i--;
            }
        }
        int cnt = 0;
        while (n2) {
            if (((num1 >> cnt) & 1) == 0) {
                num1 += (1 << cnt);
                n2--;
            }
            cnt++;
        }
        return num1;
    }
};

int main() {
    Solution s;
    cout << s.minimizeXor(25, 72);

}
