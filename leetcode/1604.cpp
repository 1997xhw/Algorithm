//
// Created by 徐浩闻 on 2024/1/6.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<string> alertNames(vector<string> &keyName, vector<string> &keyTime) {
        vector<string> names;
        map<string, vector<int>> map;
        for (int i = 0; i < keyName.size(); i++) {
            string na = keyName[i];
            string ti = keyTime[i];
            int ho = (ti[0] - '0') * 10 + ti[1] - '0';
            int mi = (ti[3] - '0') * 10 + ti[4] - '0';
            map[na].emplace_back(ho * 60 + mi);
        };
        function<bool(vector<int>)> judge = [&](vector<int> ve) -> bool {
            sort(ve.begin(), ve.end());
            for (int i = 2; i < ve.size(); i++) {
                if (ve[i] - ve[i - 2] <= 60) return true;
            }
            return false;
        };
        for (auto [k, v]: map) {
            if (judge(v)) names.emplace_back(k);
        }
        return names;

    }
};

int main() {


}
