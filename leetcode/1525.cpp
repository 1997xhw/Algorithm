//
// Created by 徐浩闻 on 2023/11/28.
//
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int numSplits(string s) {
        vector<int> left(28, 0), right(28, 0);
        for (int i = 0; i < s.length(); ++i) {
            right[s[i] - 'a'] ++;
            if(right[s[i] - 'a'] == 1) right[27] ++;
        }
        int ans = 0;
        for (int i = 0; i < s.length(); i ++) {
            int num = s[i] - 'a';
            int prel = left[num];
            left[num] ++;
            right[num] --;
            if (right[num] == 0) right[27]--;
            if (left[num] == 1) left[27]++;
            if (right[27] == left[27]) ans++;
        }
        return ans;
    }
};
int main() {
    Solution s;
    cout << s.numSplits("acbadbaada") << endl;

}