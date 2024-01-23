//
// Created by 徐浩闻 on 2024/1/23.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int getLastMoment(int n, vector<int> &left, vector<int> &right) {
        int leftMostAnt=n;
        int rightMostAnt=0;
        if ( left.size() != 0 )
            rightMostAnt = *max_element(left.begin(),left.end());
        if ( right.size() != 0 )
            leftMostAnt = *min_element(right.begin(),right.end());
        return max(rightMostAnt, n-leftMostAnt);

    }
};

int main() {
    vector<int> left = {4, 3};
    vector<int> right = {0, 1};
    Solution s;
    cout << s.getLastMoment(4, left, right);

}