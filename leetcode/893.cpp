//
// Created by 徐浩闻 on 2023/12/22.
//
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    string getSortedString(const string& s, int startIndex) {
        string result;
        for (int i = startIndex; i < s.length(); i+=2) {
            result += s[i];
        }
        sort(result.begin(), result.end());
        return result;
    }
    unordered_map<string, int> sm;
    int numSpecialEquivGroups(vector <string> &words) {
        for (auto &w: words) {
            string evenSorted = getSortedString(w, 0);
            string oddSorted = getSortedString(w, 1);
            string concatenated = evenSorted + oddSorted;
            sm[concatenated]++;
        }
        return sm.size();
    }
};


int main() {


}