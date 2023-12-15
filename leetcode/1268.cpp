//
// Created by 徐浩闻 on 2023/12/14.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord) {
        string tmp = "";
        sort(products.begin(), products.end());
        vector<vector<string>> res(searchWord.length(), vector<string>(0, ""));
        for (int i = 0; i < searchWord.length(); i++) {
            tmp += searchWord[i];
            int k = 0;
            while (k < products.size() && res[i].size() < 3) {
                if(products[k].substr(0, i+1)==tmp)
                res[i].emplace_back(products[k]);
                k++;
            }
            for (int j = 0; j < res[i].size(); j++) cout << res[i][j] << " ";
            cout << endl;
        }
        return res;
    }
};

int main() {
    vector<string> products = {"mobile", "mouse", "moneypot", "monitor", "mousepad"};
    Solution s;
    s.suggestedProducts(products, "mouse");

}