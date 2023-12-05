//
// Created by 徐浩闻 on 2023/12/4.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int distMoney(int money, int children) {
        money -= children;
        if (money < 0) return -1;
        int ans = min(money / 7, children);
        money -= ans*7;
        children -= ans;
        if(children == 0 && money || children == 1 && money==3) --ans;
        return ans;

    }
};

int main() {


}