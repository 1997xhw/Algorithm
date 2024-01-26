//
// Created by 徐浩闻 on 2024/1/24.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    long long maximumSumOfHeights(vector<int> &maxHeights) {
        int n = maxHeights.size();
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long tmp = 0;
            stack<long long> ll, rr;
            ll.push(maxHeights[i]);
            rr.push(maxHeights[i]);
            int l = i;
            while (l > 0) {
                l--;
                if (maxHeights[l] >= ll.top()) ll.push(ll.top());
                else ll.push(maxHeights[l]);
            }
            int r = i;
            while (r < n - 1) {
                r++;
                if (maxHeights[r] >= rr.top()) rr.push(rr.top());
                else rr.push(maxHeights[r]);
            }
            function<long long(stack<long long>)> accSTK = [&](stack<long long> ss) -> long long {
                long long sum = 0;
                while (!ss.empty()) {
                    sum += ss.top();
                    ss.pop();
                }
                return sum;
            };
            if (i == 0)
                tmp = accSTK(rr);
            else if (i == n - 1) tmp = accSTK(ll);
            else tmp = accSTK(ll) + accSTK(rr) - maxHeights[i];
            ans = max(ans, tmp);
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {5, 3, 4, 1, 1};
    Solution s;
    cout << s.maximumSumOfHeights(nums);

}