//
// Created by 徐浩闻 on 2023/12/14.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n) {
        vector<int> ff(n, 0);
        for (auto &booking: bookings) {
            ff[booking[0] - 1] += booking[2];
            if (booking[1] < n) {
                ff[booking[1]] -= booking[2];
            }
        }
        for (int i = 1; i < n; i++)
            ff[i] += ff[i - 1];
        return ff;
    }
};

int main() {


}