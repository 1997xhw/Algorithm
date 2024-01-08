//
// Created by 徐浩闻 on 2024/1/7.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        //只处理一次访问状态
        //车在同一水平线
        if (a == e) {
            if (c != e || c == e && !((b < d && d < f) || (f < d && d < b))) return 1;
        }
        //车在同一垂直线
        if (b == f) {
            if (d != f || d == f && !((a < c && c < e) || (e < c && c < a))) return 1;
        }

        //象在主对角线（斜向下）
        if (e - f == c - d) {
            if (c - d != a - b || !((c < a && a < e) || (e < a && a < c))) return 1;
        }
        //象在副对角线（斜向上）
        if (e + f == c + d) {
            if (c + d != a + b || !((c < a && a < e) || (e < a && a < c))) return 1;
        }
        return 2;
    }
};

int main() {


}