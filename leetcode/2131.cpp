//
// Created by 徐浩闻 on 2023/12/11.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> wordCount;
        int length = 0;
        bool hasMid = false;

        for (auto& word: words) {
            wordCount[word]++;
        }

        for (auto& item: wordCount) {
            string word = item.first;
            string reversedWord = string() + word[1] + word[0];

            if (word == reversedWord) {
                // For words like "gg", "cc", etc.
                length += (item.second / 2) * 4; // Add length for pairs
                if (item.second % 2 != 0) hasMid = true; // If odd count, possible middle element
            } else if (wordCount.find(reversedWord) != wordCount.end()) {
                // For words like "ab" with a counterpart "ba"
                int pairs = min(item.second, wordCount[reversedWord]);
                length += pairs * 4; // Add length for pairs
                wordCount[reversedWord] -= pairs; // Reduce the count of the counterpart
                item.second -= pairs; // Reduce the count of the current word
            }
        }

        if (hasMid) length += 2; // Add 2 for the middle element
        return length;
    }
};

int main() {
    Solution s;
    vector<string> words = {"cc", "ll", "xx"};
    cout << s.longestPalindrome(words);

}