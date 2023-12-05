//
// Created by 徐浩闻 on 2023/11/30.
//
#include "bits/stdc++.h"

using namespace std;


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
    unordered_set<int> del;
    vector<TreeNode *> ans;

    TreeNode * dfs(TreeNode *root) {
        if (root == nullptr) return nullptr;
        if (del.count(root->val)) {
            if (root->left != nullptr && !del.count(root->left->val)) ans.push_back(root->left);
            if (root->right != nullptr && !del.count(root->right->val)) ans.push_back(root->right);
        }
        root->left = dfs(root->left);
        root->right = dfs(root->right);
        return del.count(root->val) ? nullptr : root;

    }

    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete) {
        for (auto i: to_delete) del.insert(i);
        if(dfs(root)!= nullptr) ans.push_back(root);
        return ans;
    }
};

int main() {


}