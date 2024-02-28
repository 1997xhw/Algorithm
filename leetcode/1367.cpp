//
// Created by 徐浩闻 on 2024/2/25.
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool dfs(ListNode *head, TreeNode *root) {
        if (head == nullptr) return true;
        if (root == nullptr) return false;
        return head->val == root->val && (dfs(head->next, root->left)|| dfs(head->next, root->right));
    }

    bool isSubPath(ListNode *head, TreeNode *root) {
        int aim = head->val;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            auto tmp = q.front();
            q.pop();
            if (tmp->val == aim && dfs(head, tmp))return true;
            if(tmp->left) q.push(tmp->left);
            if(tmp->right) q.push(tmp->right);
        }
        return false;
    }
};

int main() {


}