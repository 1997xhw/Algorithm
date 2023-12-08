//
// Created by 徐浩闻 on 2023/12/7.
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
    vector<int> tlist;

    TreeNode *balanceBST(TreeNode *root) {
        dfs(root);
        return BuildBalanceTree(0, tlist.size() - 1);
    }

    TreeNode *BuildBalanceTree(int i, int j) {
        if (i > j) return nullptr;
        int mid = i + (j - i) / 2;
        TreeNode *root = new TreeNode(tlist[mid]);
        root->left = BuildBalanceTree(i, mid - 1);
        root->right = BuildBalanceTree(mid + 1, j);
        return root;
    }

    void dfs(TreeNode *root) {
        if (root == nullptr) return;
        dfs(root->left);
        tlist.emplace_back(root->val);
        dfs(root->right);
    }
};

int main() {


}