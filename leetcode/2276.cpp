//
// Created by 徐浩闻 on 2023/12/16.
//
#include "bits/stdc++.h"

using namespace std;

class CountIntervals {
    int ans = 0;
    set<pair<int, int>> st;
public:
    CountIntervals() {

    }

    void add(int left, int right) {
        int l = left, r = right;
        for (auto it = st.lower_bound({left, INT_MIN}); it != st.end() && it->second <= right; st.erase(it++)) {
            l = min(l, it->second);
            r = max(r, it->first);
            ans -= it->first - it->second + 1;
        }
        ans += r - l + 1;
        st.insert({r, l});
    }

    int count() {
        return ans;
    }
};

int main() {


}