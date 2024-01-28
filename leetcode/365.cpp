//
// Created by 徐浩闻 on 2024/1/28.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int gcd(int a, int b) {
        return b ? gcd(b, a % b) : a;
    }

    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        if (jug1Capacity + jug2Capacity < targetCapacity) return false;
        else return targetCapacity % gcd(jug1Capacity, jug2Capacity) == 0;
    }
};

int main() {


}