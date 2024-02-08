//
// Created by 徐浩闻 on 2024/2/7.
//
#include "bits/stdc++.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

using namespace std;

class Solution {
public:
    TreeNode *replaceValueInTree(TreeNode *root) {
        vector<int> sum;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            auto tmp = q.front();
            q.pop();
            if (tmp.second >= sum.size()) sum.resize(tmp.second + 1, 0);
            sum[tmp.second] += tmp.first->val;
            if (tmp.first->left != nullptr) q.push({tmp.first->left, tmp.second + 1});
            if (tmp.first->right != nullptr) q.push({tmp.first->right, tmp.second + 1});
        }
        root->val = 0;

        q.push({root, 0});
        while (!q.empty()) {
            auto tmp = q.front();
            q.pop();
            int cnt = 0;
            if (tmp.first->left != nullptr) cnt += tmp.first->left->val;
            if (tmp.first->right != nullptr) cnt += tmp.first->right->val;
            if (tmp.first->left != nullptr) {
                tmp.first->left->val = sum[tmp.second + 1] - cnt;
                q.push({tmp.first->left, tmp.second + 1});
            }
            if (tmp.first->right != nullptr) {
                tmp.first->right->val = sum[tmp.second + 1] - cnt;
                q.push({tmp.first->right, tmp.second + 1});
            }
        }
        return root;

    }
};

int main() {


}