//
// Created by 徐浩闻 on 2023/12/17.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string discountPrices(string sentence, int discount) {
        string ret;
        for(int i = 0, j = 0; i <= sentence.size(); ++i) {
            if(i == sentence.size() || sentence[i] == ' ') {
                string s = sentence.substr(j, i-j);
                bool price = false;
                if(s[0] == '$' && s.size() > 1) {
                    bool isnum = true;
                    for(int k = 1; k < s.size(); ++k)
                        if(!isdigit(s[k])) isnum = false;
                    if(isnum) price = true;
                }
                if(price) {
                    long long after = stoll(s.substr(1)) * (100 - discount);
                    char tmp[20];
                    sprintf(tmp, "$%lld.%02lld", after / 100, after % 100);
                    ret += tmp;
                    ret += " ";
                } else {
                    ret += s;
                    ret += " ";
                }
                j = i+1;
            }
        }
        ret.pop_back();
        return ret;
    }
};


int main() {
    string ss = "1 2 $3 4 $5 $6 7 8$ $9 $10$";
    Solution s;
    cout <<s.discountPrices(ss, 100);

}