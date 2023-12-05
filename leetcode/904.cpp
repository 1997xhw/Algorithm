//
// Created by 徐浩闻 on 2023/12/1.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int totalFruit(vector<int> &fruits) {
        queue<int> basket, types;
        int baskets = 0;
        int ans = 0;
        for (int i = 0; i < fruits.size(); i++) {
            int fruit = fruits[i];
            if (types.empty()) {
                types.push(fruit);
                baskets++;
            } else if (types.size() == 1) {
//                cout << "**" << fruit << " i:" << i << endl;
                if (types.back() != fruit) {
                    types.push(fruit);
                }
                baskets++;
            } else {
                if (types.front() != fruit && types.back() != fruit) {
//                    cout << types.front() << " " << types.back() << " basket: " << baskets << endl;
                    ans = max(ans, baskets);
                    types.pop();
                    types.pop();

                    types.push(fruit);
                    types.push(fruits[i - 1]);
                    baskets = 0;
                    int front = fruits[i - 1];
//                    cout << "^^";
                    for (int j = i; j >= 0; j--) {
                        if (fruits[j] == types.front() || fruits[j] == types.back()) {
                            baskets++;
//                            cout << fruits[j] << " ";
                        } else {
//                            cout << "basket: " << baskets << endl;

                            break;
                        }
                    }


                }else {
                    baskets++;
                }
            }
        }
        return max(ans, baskets);
    }
};

int main() {
    Solution s;
    vector<int> fruits = {1,2,1};
    cout << s.totalFruit(fruits) << endl;

}