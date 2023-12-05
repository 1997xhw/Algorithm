#include<bits/stdc++.h>
using namespace std;


int beautySum(string s) {
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        vector<int> cc(26, 0);
        for (int j = i; j < s.size(); j++) {
            cc[s[j] - 'a']++;
            int maxx = INT32_MIN;
            int minn = INT32_MAX;
            for (auto c : cc) {
                if(!c) {
                    maxx = max(maxx, c);
                    minn = min(minn, c);
                }
            }
            ans += maxx - minn;
        }
    }
    return ans;
}

int main() {


}

