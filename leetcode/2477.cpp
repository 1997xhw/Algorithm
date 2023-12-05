//
// Created by 徐浩闻 on 2023/12/5.
//
#include "bits/stdc++.h"

using namespace std;
const int n = 1e5 + 5;

class Solution {
public:
    int seat;
    long long gas;
    unordered_map<int, vector<int>> maps;
    int sumGas(int fromCity, int city) {
        int people = 1;
        if (maps[city].size() == 1) {
            gas +=1;
            return 1;
        };
        for (const auto &c: maps[city]) {
            if (c == fromCity) continue;
            people += sumGas(city, c);
        }
        gas += ceil((double) people / seat);
        return people;
    }

    long long minimumFuelCost(vector<vector<int>> &roads, int seats) {
        seat = seats;
        for (const auto &road: roads) {
            maps[road[0]].push_back(road[1]);
            maps[road[1]].push_back(road[0]);
        }
        for (const auto &city: maps[0]) {
            sumGas(0, city);
        }
        return gas;

    }
};

int main() {
    vector<vector<int>> roads = {{3, 1},
                                 {3, 2},
                                 {0, 4},
                                 {0, 5},
                                 {4, 6},
                                 {1, 0}};
    Solution s;
    cout << s.minimumFuelCost(roads, 2) << endl;

}