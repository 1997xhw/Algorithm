//
// Created by 徐浩闻 on 2023/12/13.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>> &favoriteCompanies) {
        set<vector<string>> se;
        vector<int> res;
        for (auto &favoriteCompany: favoriteCompanies) {
            sort(favoriteCompany.begin(), favoriteCompany.end());
        }
        for (int i = 0; i < favoriteCompanies.size(); i++) {
            bool flag = true;
            for (int j = 0; j < favoriteCompanies.size(); j++) {
                if(i!=j && favoriteCompanies[i].size() <= favoriteCompanies[j].size()) {
                    if(includes(favoriteCompanies[j].begin(), favoriteCompanies[j].end(), favoriteCompanies[i].begin(), favoriteCompanies[i].end())) {
                        flag = false;
                        break;
                    }
                }
            }
            if(flag) res.push_back(i);
        }
        return res;
    }
};

int main() {


}
