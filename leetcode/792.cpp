#include <bits/stdc++.h>
using namespace std;
int numMatchingSubseq(string s, vector<string> &words)
{
    int cnt = 0;
    for (string &word : words)
    {
        int cur = -1;
        bool ok = true;
        for (char &c : word)
        {
            cur = s.find(c, cur + 1);
            if (cur == string::npos)
            {
                ok = false;
                break;
            }
        }
        if (ok)
            cnt++;
    }
    return cnt;
}

int main()
{
    string ww[4] = {"a", "bb", "acd", "ace"};
    vector<string> word(ww, ww + 4);
    cout << numMatchingSubseq("abcde", word);
}
