//
// Created by 徐浩闻 on 2023/12/20.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> alphabet = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int n = digits.size();
        vector<string> ans;
        string tmp;
        function<void(int)> dfs = [&](int pos)->void {
            if(pos == n) {
                if (tmp!="")
                    ans.push_back(tmp);
                return;
            }
            int num = digits[pos] - '0';
            for (auto &a: alphabet[num]) {
                tmp.push_back(a);
                dfs(pos+1);
                tmp.pop_back();
            }
        };
        dfs(0);
        return ans;
    }
};

int main() {


}