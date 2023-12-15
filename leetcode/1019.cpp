//
// Created by 徐浩闻 on 2023/12/14.
//
#include "bits/stdc++.h"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<int> nextLargerNodes(ListNode *head) {
        stack<pair<int, int>> stm;
        int res[10005] = {0};
        vector<int> ans;
        int len = 0;
        while (head != nullptr) {

            if(stm.empty() || stm.top().first>=head->val) {
                stm.push({head->val, len});
            }
            else {
                while(!stm.empty() && stm.top().first<head->val) {
                    res[stm.top().second]=head->val;
                    stm.pop();
                }
                stm.push({head->val, len});
            }
            head = head->next;
            len++;
        }
        for(int i =0; i < len; i++) ans.emplace_back(res[i]);
        return ans;
    }
};

int main() {


}