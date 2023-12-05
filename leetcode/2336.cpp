//
// Created by 徐浩闻 on 2023/11/29.
//
#include "bits/stdc++.h"

using namespace std;

class SmallestInfiniteSet {

public:
    int flag;
    int nums[2005];

    SmallestInfiniteSet() {
        for (int i = 1; i < 2005; i++) nums[i] = 1;
        flag = 1;
    }

    int popSmallest() {
        int popn = flag;
        nums[flag] = 0;
        while (!nums[flag]) flag++;
        return popn;
    }

    void addBack(int num) {
        nums[num] = 1;
        if (num < flag) flag = num;
    }
};

int main() {
    SmallestInfiniteSet smallestInfiniteSet;
    cout << smallestInfiniteSet.popSmallest() << endl;
    cout << smallestInfiniteSet.popSmallest() << endl;
    cout << smallestInfiniteSet.popSmallest() << endl;
    cout << smallestInfiniteSet.popSmallest() << endl;
    smallestInfiniteSet.addBack(1);
    smallestInfiniteSet.addBack(2);
    cout << smallestInfiniteSet.popSmallest() << endl;

}