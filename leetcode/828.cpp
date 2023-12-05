//
// Created by 徐浩闻 on 2023/11/26.
//

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int uniqueLetterString(string s) {
        vector<vector<int>> words(26, {-1});
        for (int i = 0; i < s.size(); i++) {
            words[s[i] - 'A'].push_back(i);
        }
        int ans = 0;
        for (auto& i : words) {
            i.push_back(s.size());
            for (int j = 1; j < i.size() - 1; j ++) {
                ans += (i[j] - i[j - 1])*(i[j + 1]-i[j]);
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
//    cout << (int) 'A' << endl;
    cout << s.uniqueLetterString("ABC") << endl;

}