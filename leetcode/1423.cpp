//
// Created by 徐浩闻 on 2023/12/3.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxScore(vector<int> &cardPoints, int k) {
        int len = cardPoints.size();
        vector<int> cardsum(len, 0);
        cardsum[0] = cardPoints[0];
        for (int i = 1; i < len; i++) {
            cardsum[i] = cardsum[i - 1] + cardPoints[i];
        }
        if (k == len) return cardsum[len - 1];
        int ans = cardsum[k - 1];
        int i = k - 1, j = len - 1;
        for (int kk = 1; kk <= k; kk++) {
            int currentSum = cardsum[len - 1] - cardsum[j - kk];
            if (i - kk >= 0) {
                currentSum += cardsum[i - kk];
            }
            ans = max(ans, currentSum);
        }

        return ans;
    }
};

int main() {
    Solution s;
    vector<int> cardPoints = {1, 2, 3, 4, 5, 6, 1};
    cout << s.maxScore(cardPoints, 3) << endl;

}