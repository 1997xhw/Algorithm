//
// Created by 徐浩闻 on 2024/3/26.
//
#include "bits/stdc++.h"
using namespace std;
string reverseLetterSubstrings(const string& str) {
    string result = str;
    int start = -1;

    for (int i = 0; i <= result.length(); ++ i) {
        if (i < result.length() && isalpha(result[i])) {
            if (start == -1) {
                start = i;
            }
        } else if (start != -1) {
            reverse(result.begin() + start, result.begin() + i);
            start = -1;
        }
    }
    return result;channels:

}
int main() {

    string input = "abc12";
    string output = reverseLetterSubstrings(input);
   cout << "Original: " << input << "\nReversed: " << output << std::endl;
    return 0;
}