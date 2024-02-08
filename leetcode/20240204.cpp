//
// Created by 徐浩闻 on 2024/2/4.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        int n = word.length();
        int tail = word[n - 1];

    }
};

int minTimeToRevert(string word, int k) {
    int n = word.length(), cnt = 0;
    string ori = word;
    while (cnt == 0 || ori != word) {
        string tmp = ori.substr(0, k);
        ori = ori.substr(k, n-k);

        if (ori.find(tmp) != string::npos ){

        }
            cnt++;

    }

}

int main() {
//    cout << "Min time for 'abacaba', k=3: " << minTimeToRevert("abacaba", 3) << endl;
//    cout << "Min time for 'abacaba', k=4: " << minTimeToRevert("abacaba", 4) << endl;
//    cout << "Min time for 'abcbabcd', k=2: " << minTimeToRevert("abcbabcd", 2) << endl;

}