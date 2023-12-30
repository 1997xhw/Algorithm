//
// Created by 徐浩闻 on 2023/12/30.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minimumSwap(string s1, string s2) {
        unordered_map<string, int> hash;
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] == 'x' && s2[i] == 'y') hash["xy"]++;
            if (s1[i] == 'y' && s2[i] == 'x') hash["yx"]++;
        }
        if (hash["xy"] + hash["yx"] >> 1) return -1;
        return hash["xy"] / 2 + hash["yx"] / 2 + max(hash["xy"] % 2, hash["yx"] % 2);
    }
};

int main() {


}