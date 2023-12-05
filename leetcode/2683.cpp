//
// Created by 徐浩闻 on 2023/12/2.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool doesValidArrayExist(vector<int> &derived) {
        int ans = 0;
        for (const auto &item: derived)
            ans ^= item;
        return ans == 0;
    }
};

int main() {
    Solution s;
    vector<int> derived = {1, 0};
    cout << s.doesValidArrayExist(derived) << endl;

}