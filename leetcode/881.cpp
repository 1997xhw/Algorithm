//
// Created by 徐浩闻 on 2023/12/2.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int> &people, int limit) {
        sort(people.begin(), people.end());
        int i = 0, j = people.size() - 1;
        int ans = 0;
        while (i < j) {
            if (people[i] + people[j] <= limit)
                i++;
            ans++;
            j--;
        }
        if (i == j) ans++;
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> people = {3, 2, 2, 1};
    cout << s.numRescueBoats(people, 3) << endl;

}