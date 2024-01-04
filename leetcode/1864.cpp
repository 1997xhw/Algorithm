//
// Created by 徐浩闻 on 2024/1/1.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minSwaps(string s) {
        int n = s.length(), one;
        int tmp = 0, br_s = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                br_s += 1;
                one++;
            }
            if (i % 2 == 0) tmp += 1;
            tmp = tmp << 1;
            br_s = br_s << 1;
        }
        if (one < n / 2) return -1;
        tmp = tmp >> 1;
        br_s = br_s >> 1;
        cout << tmp << " " << br_s << endl;
        int cha;
        cha = tmp ^ br_s;
        if (cha == 0 || cha == (pow(2, n) - 1)) return 0;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += (cha >> i) & 1;
        }
        int res = -1;
        if (sum % 2 == 0) res = sum / 2;
        if ((n - sum) % 2 == 0) res = res == -1 ? -1 : min(res, (n - sum) / 2);
        return res;
//        return sum % 2 == 0 || (n-sum) % 2 == 0 ? sum / 2 : -1;

    }
};

int main() {
    string s = "100";
    Solution ss;
    cout << ss.minSwaps(s);
}