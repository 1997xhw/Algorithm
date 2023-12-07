//
// Created by 徐浩闻 on 2023/12/6.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long> ans;
        if (finalSum % 2) return ans;

        for (long long i = 2; i <= finalSum; i += 2) {
            ans.push_back(i);
            finalSum -= i;
        }
        ans.back()+=finalSum;
        return ans;
    }
};

int main() {

Solution s;
vector<long long> ans = s.maximumEvenSplit(21312);
    for (const auto &item: ans){
        cout << item << " ";
    }
}