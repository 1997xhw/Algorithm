//
// Created by 徐浩闻 on 2023/12/8.
//
#include "bits/stdc++.h"
using namespace std;

int main() {
    int n ;// 长度
    int x;
    int left = 0, right = n;
    int mid;
    while(left < right) {
        mid = (left + right) /2;
        if(mid == x) break;
        else if(a[mid] < x) left = mid;
        else if(a[mid] > x) right = mid;
    }
    //将插入位置之后的所有元素后移一位
    ....


    //将x插入a[left]
    a[left] = x;
}

