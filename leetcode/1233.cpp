//
// Created by 徐浩闻 on 2023/12/8.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<string> removeSubfolders(vector<string> &folder) {
//        sort(folder.begin(), folder.end(), [](const string &a, const string &b) {
//            return a.length() < b.length();
//        });
        sort(folder.begin(), folder.end());
        string prefix = "";
        vector<string> ans;
        for (int i = 0; i < folder.size(); ++i) {
            if (prefix!="" && folder[i].find(prefix) == 0) continue;
            prefix = folder[i] + "/";
            ans.emplace_back(folder[i]);
        }
        return ans;

    }
};

int main() {


}