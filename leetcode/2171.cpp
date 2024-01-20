//
// Created by 徐浩闻 on 2024/1/18.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    long long minimumRemoval(vector<int> &beans) {
        sort(beans.begin(), beans.end());
        long long n = beans.size();
        vector<long long> ss(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            ss[i] = ss[i - 1] + beans[i - 1];
        }
        ss.erase(ss.begin());
//        if (ss[n - 1] == ss[0] * n) return 0;
        int i = 0;
        long long ans = LONG_MAX;
        while (i < n) {
            if (i + 1 < n && beans[i] == beans[i + 1]) {
                i++;
                continue;
            }
            int left = i, right = i;
            while (left - 1 >= 0 && beans[i] == beans[left - 1])left--;
            long long tmp;
            if (left == 0) tmp = 0;
            else {
                tmp = ss[left - 1];
            }
            cout << tmp << endl;
            tmp += (ss[n - 1] - ss[i] - (n - right - 1) * beans[i]);
            ans = min(ans, tmp);
            cout << left << " " << i << " " << ans << endl;
            i++;
        }
        return ans;

    }
};

int main() {
    vector<int> beans = {1, 1, 1};
    Solution s;
    cout << s.minimumRemoval(beans);
// 1 4 5 6
}