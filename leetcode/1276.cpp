//
// Created by 徐浩闻 on 2023/12/25.
//
#include "bits/stdc++.h"

using namespace std;
class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        if ((tomatoSlices - 2*cheeseSlices) % 2) return {};
        int x = (tomatoSlices - 2*cheeseSlices)/2;
        int y = cheeseSlices - x;
        return {x, y};
    }
};
int main() {


}
