//
// Created by 徐浩闻 on 2023/12/26.
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
    vector<vector<int>> closestNodes(TreeNode *root, vector<int> &queries) {
        vector<int> query;
        function<void(TreeNode *)> dfs = [&](TreeNode *root) {
            if (root == nullptr) return;
            dfs(root->left);
            query.push_back(root->val);
            dfs(root->right);
        };
        dfs(root);
        for (auto &item: query) {
            cout << item << " ";
        }
        cout << endl;

        vector<vector<int>> res;
        for (auto &q: queries) {
            int left = 0, right = query.size();
            while (left < right) {
                int mid = (left + right) >> 1;
                if (query[mid] < q + 1) left = mid + 1;
                else right = mid;
            }
            cout << query[left] << " ";
            int l1 = (left - 1 >= 0 ? left - 1 : -1);


            left = 0, right = query.size();
            while (left < right) {
                int mid = (left + right) >> 1;
                if (query[mid] < q) left = mid + 1;
                else right = mid;
            }
            int l2 = (left < query.size() ? left : -1);
            res.push_back({l1, l2});
        }
        return res;
    }
};

int main() {


}