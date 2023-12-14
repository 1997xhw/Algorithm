//
// Created by 徐浩闻 on 2023/12/13.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int> &hand, int groupSize) {
        int len = hand.size();
        if (len % groupSize ) return false;
        sort(hand.begin(), hand.end());
        unordered_map<int, int> mp;
        for (auto &item: hand) {
            mp[item]++;
        }
        for (int i = 0; i < hand.size(); i++) {
            if (mp[hand[i]] > 0) {
                int k = 0;
                while (k < groupSize) {
                    if(mp.find(hand[i]+k)==mp.end() || mp[hand[i]+k]==0) return false;
                    mp[hand[i]+k]--;
                    k++;
                }
            };
        }
        return true;
    }
};

int main() {
        vector<int> hand = {1,2,3,6,2,3,4,7,8};
        Solution s;
        cout << s.isNStraightHand(hand, 3);

}