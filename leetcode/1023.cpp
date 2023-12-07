//
// Created by 徐浩闻 on 2023/12/6.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<bool> camelMatch(vector<string> &queries, string pattern) {
        unordered_map<char, bool> noun;
        int plen = pattern.length();
        vector<bool> ans;
        for (int i = 0; i < 26; i++) noun['a' + i] = true, noun['A' + i] = false;
        for (const auto &query: queries) {
            int i = 0, j = 0;
            bool is_ans = true;
            while (i < query.length() && j < plen) {
                if (query[i] == pattern[j]) {
                    i++;
                    j++;
                } else {
                    if (!noun[pattern[j]]) {
                        if (noun[query[i]])
                            i++;
                        else {
                            is_ans = false;
                            break;
                        }
                    } else {
                        if (noun[query[i]]) {
                            i++;
                        } else {
                            is_ans = false;
                            break;
                        }
                    }
                }
            }
            if (!is_ans) {
                ans.push_back(false);
                continue;
            } else {
                if (i < query.length() && j == plen) {
                    bool  is_ans2 = true;
                    while (i < query.length())
                        if (!noun[query[i++]]) {
                            is_ans2 = false;
                            break;
                        }
                    if (!is_ans2) {
                        ans.push_back(false);
                        continue;
                    } else{
                        ans.push_back(true);
                        continue;
                    }
                } else if (j< plen){
                    ans.push_back(false);
                    continue;
                }
                ans.push_back(true);
            }
        }
        return ans;
    }
};

int main() {


}