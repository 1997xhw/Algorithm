//
// Created by 徐浩闻 on 2023/11/25.
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
    int ans;

    int pseudoPalindromicPaths(TreeNode *root) {
        dfs(root, 0);
        return ans;
    }

    void dfs(TreeNode *root, int cnt) {
        if (!root->left && !root->right) {
            cnt ^= 1 << root->val;
            if (cnt == (cnt & -cnt)) ans++;
            return;
        }
        if (root->left) dfs(root->left, cnt ^ (1 << root->val));
        if (root->right) dfs(root->right, cnt ^ (1 << root->val));
    }
};

int main() {
    vector<int> tree = {2, 3, 1, 3, 1, 0, 1};
    cout << log(tree.size() + 1) / log(2) << endl;

}