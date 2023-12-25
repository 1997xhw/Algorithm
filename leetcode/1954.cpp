//
// Created by 徐浩闻 on 2023/12/24.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long res = 0, cnt = 2;
        while (res < neededApples) {
            res += 3 * cnt * cnt;
            cnt += 2;
        }
        return 4 * (cnt - 2);
    }
};

int main() {
    Solution solution;
    cout << solution.minimumPerimeter(1000000000);

}