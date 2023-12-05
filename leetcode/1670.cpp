//
// Created by 徐浩闻 on 2023/11/28.
//
#include "bits/stdc++.h"

using namespace std;

class FrontMiddleBackQueue {
public:
    FrontMiddleBackQueue() {

    }

    int l[2010], r[2010], lhead = 1010, rhead = 1010, ltail = 1010, rtail = 1010;

    int getSize(int head, int tail) {
        return tail - head;
    }

    void update() {
        while(getSize(lhead, ltail) > getSize(rhead, rtail)) r[rhead--] = l[ltail--];
        while(getSize(rhead, rtail) - getSize(lhead, ltail) > 1) l[++ltail] = r[++rhead];
    }

    void pushFront(int val) {
        l[lhead--] = val;
        update();
    }

    void pushMiddle(int val) {
        l[++ltail] = val;
        update();
    }

    void pushBack(int val) {
        r[++rtail] = val;
        update();
    }

    int popFront() {
        if (getSize(lhead, ltail) == 0 && getSize(rhead, rtail) == 0) return -1;
        int ans = getSize(lhead, ltail) !=0 ? l[++lhead] : r[++rhead];
        update();
        return  ans;
    }

    int popMiddle() {
        if (getSize(lhead, ltail) == 0 && getSize(rhead, rtail) == 0) return -1;
        int ans = getSize(lhead, ltail) == getSize(rhead, rtail) ? l[ltail--] : r[++rhead];
        update();
        return ans;
    }

    int popBack() {
        if (getSize(lhead, ltail) == 0 && getSize(rhead, rtail) == 0) return -1;
        int ans = getSize(rhead, rtail) !=0 ? r[rtail--] : l[ltail--];
        update();
        return ans;
    }
};

int main() {


}