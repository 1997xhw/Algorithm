//
// Created by 徐浩闻 on 2023/11/30.
//
#include "bits/stdc++.h"

using namespace std;

class FrequencyTracker {
public:
    unordered_map<int, int> cnt;
    unordered_map<int, int> freq;

    FrequencyTracker() {
    }

    void add(int number) {
        --freq[cnt[number]];
        ++freq[++cnt[number]];
    }

    void deleteOne(int number) {
        if (!cnt[number]) return;
        --freq[cnt[number]];
        ++freq[--cnt[number]];
    }

    bool hasFrequency(int frequency) {
        return freq[frequency];
    }
};

int main() {


}