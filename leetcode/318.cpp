#include<bits/stdc++.h>
using namespace std;
int maxProduct(vector<string>& words) {
    int mask[1005];
    for(int i = 0; i < words.size(); i++) {
        int m = 0;
        for(auto j : words[i])
            m = m | (1 << (j - 'a'));
        mask[i] = m;
    }
    int max = 0;
    for(int i = 0; i < words.size(); i++) {
        for(int j = i + 1; j < words.size(); j++) {
            if(max < words[i].size() * words[j].size() && ((mask[i] & mask[j]) == 0)) max = words[i].size() * words[j].size();
        }
    }
    return max;

}
int main () {
    vector<string> words{"a","ab","abc","d","cd","bcd","abcd"};
    cout << maxProduct(words) << endl;



}