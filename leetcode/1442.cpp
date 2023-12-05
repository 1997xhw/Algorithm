//
// Created by 徐浩闻 on 2023/12/2.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int countTriplets(vector<int> &arr) {
        int len = arr.size();
        if (arr.size() < 2) return 0;
        int ans = 0;
        int arrr[len];
        arrr[0] = arr[0];
        for (int i = 1; i < len; ++i) {
            arrr[i] = arrr[i - 1] ^ arr[i];
        }
        for (int i = 0; i < len - 1; i++) {
            for (int j = i + 1; j < len; ++j) {
                int zuo;
                if (i==0) {
                    zuo = 0;
                }else {
                    zuo = arrr[i - 1];
                }
                if((zuo ^ arrr[j]) == 0) {
                    ans += (j - i);
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> arr = {1,1,1,1,1};
    cout << s.countTriplets(arr) << endl;

}