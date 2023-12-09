//
// Created by 徐浩闻 on 2023/12/10.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int modPow(long long base, int exponent, int mod) {
        base %= mod;
        long long result = 1;
        while (exponent > 0) {
            if (exponent % 2 == 1)
                result = (result * base) % mod;
            base = (base * base) % mod;
            exponent /= 2;
        }
        return result;
    }

    vector<int> getGoodIndices(vector<vector<int>> &variables, int target) {
        vector<int> ans;
        for (int i = 0; i < variables.size(); i++) {
            int a = variables[i][0];
            int b = variables[i][1];
            int c = variables[i][2];
            int m = variables[i][3];
            int mod1 = modPow(a, b, 10);;
            int mod2 = modPow(mod1, c, m);
            if(mod2 == target) ans.emplace_back(i);
        }
        return  ans;
    }
};

int main() {


}