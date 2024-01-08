//
// Created by 徐浩闻 on 2024/1/6.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int longestString(int x, int y, int z) {
        if (x >= y)
            return (2 * y + 1 + z) * 2;
        else
            return (2 * x + 1 + z) * 2;
    }
};

int main() {


}