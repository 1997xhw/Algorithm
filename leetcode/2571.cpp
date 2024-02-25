//
// Created by 徐浩闻 on 2024/2/14.
//
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int minOperations(int n) {
        int cnt = 0, ans;
        while(n) {
            if(n&1)cnt++;
            else {
                if(cnt==1) ans++, cnt = 0;
                else if (cnt > 1) ans++, cnt = 1;
            }
            n>>=1;
        }
        if(cnt==1)ans++;
        else if (cnt>1) ans+=2;
        return ans;
    }
};
int main() {


}