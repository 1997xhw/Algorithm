//
// Created by 徐浩闻 on 2023/12/7.
//
#include "bits/stdc++.h"

using namespace std;

class NumberContainers {
public:
    unordered_map<int, int> m;

    unordered_map<int, priority_queue<int, vector<int>, greater<int> >> ms;

    NumberContainers() {

    }

    void change(int index, int number) {
        m[index] = number;
        ms[number].push(index);
    }

    int find(int number) {
        auto it = ms.find(number);
        if (it == ms.end()) return -1;
        auto &q = it->second;
        while (!q.empty() && m[q.top()] != number) q.pop();
        return q.empty() ? -1 : q.top();
    }
};

int main() {


}