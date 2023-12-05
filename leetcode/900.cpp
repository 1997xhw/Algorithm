//
// Created by 徐浩闻 on 2023/12/4.
//
#include "bits/stdc++.h"

using namespace std;

class RLEIterator {
public:
    vector<long long > vt;
    vector<int> val;
    long long cur_index;
    long long sum_step;

    RLEIterator(vector<int>& encoding) {
        long long pre_sum=0;
        for(int i=0;i<encoding.size();i+=2){
            pre_sum+=encoding[i];
            vt.push_back(pre_sum);
            val.push_back(encoding[i+1]);
        }
        cur_index=0;
        sum_step=0;
    }

    int next(int n) {
        sum_step+=n;
        int i=cur_index;
        for(;i<vt.size();i++){
            if(sum_step<=vt[i]){
                cur_index=i;
                break;
            }
        }
        return (i==vt.size())?-1:val[cur_index];
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */



int main() {
    vector<int> w = {3, 8, 0, 9, 2, 5};
    RLEIterator rleIterator(w);
    cout << rleIterator.next(2) << endl;
    cout << rleIterator.next(1) << endl;
    cout << rleIterator.next(1) << endl;
    cout << rleIterator.next(2) << endl;
    cout << rleIterator.next(2) << endl;

}