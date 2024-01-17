//
// Created by 徐浩闻 on 2024/1/17.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string minimizeResult(string expression) {
        int a = expression.find("+"), n = expression.length();
//        cout << a << endl;
        long long ans = LONG_MAX;
        pair<int, int> res;
//        cout << left << " " << right << endl;
        for (int i = 0; i < a; i++) {
            for (int j = expression.length() - 1; j > a; j--) {
                int num1, num2, num3, num4;
                num1 = (i == 0) ? 1 : stoi(expression.substr(0, i));
                num4 = (j == expression.length() - 1) ? 1 : stoi(expression.substr(j + 1, n - j));
                num2 = stoi(expression.substr(i, a - i));
                num3 = stoi(expression.substr(a + 1, j - a));
//                cout << i << " " << j << endl;
//                cout << num1 << " " << num2 << " " << num3 << " " << num4 << endl;
                long long cnt = num1 * (num2 + num3) * num4;
//                cout << cnt << endl;
                if (ans > cnt) {
                    res = {i, j};
                    ans = cnt;
                }
            }
        }
//        cout << res.first << " " << res.second << endl;
        expression.insert(res.first, 1, '(');
        expression.insert(res.second + 2, 1, ')');
//        cout << ans << endl;
        return expression;
    }
};

int main() {
    Solution s;
    string ss = "6+253";
    cout << s.minimizeResult(ss);
}