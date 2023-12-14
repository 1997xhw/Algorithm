//
// Created by 徐浩闻 on 2023/12/13.
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
    TreeNode *root;
    vector<int> pre;

    void insert(TreeNode *root, int ind) {
        if (root->val > ind) {
            if (!root->left)
                root->left = new TreeNode(ind, nullptr, nullptr);
            else
                insert(root->left, ind);
        } else {
            if (!root->right)
                root->right = new TreeNode(ind, nullptr, nullptr);
            else
                insert(root->right, ind);
        }
    }

    TreeNode *bstFromPreorder(vector<int> &preorder) {
        root = new TreeNode(preorder[0], nullptr, nullptr);
        for (int i = 1; i < preorder.size(); i++) {
            insert(root, preorder[i]);
        }
        return  root;
    }
};

int main() {
    vector<int> pre = {8, 5, 1, 7, 10, 12};
    Solution s;
    s.bstFromPreorder(pre);


}
