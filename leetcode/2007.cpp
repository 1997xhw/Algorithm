//
// Created by 徐浩闻 on 2023/12/12.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> findOriginalArray(vector<int> &changed) {
        vector<int> ans;
        unordered_map<int, int> col;
        sort(changed.begin(), changed.end());
        for (auto &c: changed) {
            if(col.find(c)==col.end() || col[c]==0) {
                col[c*2] ++;
                ans.push_back(c);
            } else {
                col[c]--;
                if(col[c]==0)
                    col.erase(c);
            }
        }
        if(col.size()==0) {
            return ans;
        }
        return  {};
    }
};

int main() {


}