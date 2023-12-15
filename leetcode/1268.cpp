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
        vector<vector<string>> res;
        for (int i = 0; i < searchWord.length(); i++) {
            tmp += searchWord[i];
            int k = 0;
            while (products[k] < tmp) k++;

        }
    }
};

int main() {


}