//
// Created by 徐浩闻 on 2023/12/5.
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
    int max_deep = -1;
    TreeNode *ans;

    int getTreeDeep(int deep, TreeNode *T) {
        if (T == nullptr) {
            max_deep = max(max_deep, deep);
            return deep;
        }
        int l_max_deep = getTreeDeep(deep + 1, T->left);
        int r_max_deep = getTreeDeep(deep + 1, T->right);
        if (l_max_deep == r_max_deep && l_max_deep == max_deep) ans = T;
        return max(l_max_deep, r_max_deep);
    }

    TreeNode *subtreeWithAllDeepest(TreeNode *root) {
        getTreeDeep(0, root);
        return ans;

    }
};

int main() {


}