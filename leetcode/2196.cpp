//
// Created by 徐浩闻 on 2024/2/7.
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
    TreeNode *createBinaryTree(vector<vector<int>> &descriptions) {
//        sort(descriptions.begin(), descriptions.end(),
//             [](const vector<int> &d1, const vector<int> &d2) { return d1[0] < d2[0]; });
        unordered_map<int, pair<TreeNode *, int>> mp;
        for (auto &d: descriptions) {
            if (mp.count(d[0]) == 0) {
                mp[d[0]] = {new TreeNode(d[0], nullptr, nullptr), 0};

            }
            auto node = mp[d[0]].first;
            if (mp.count(d[1]) == 0)
                mp[d[1]] = {new TreeNode(d[1], nullptr, nullptr), 0};
            auto child = mp[d[1]].first;
            mp[d[1]].second++;
            if (d[2] == 1) node->left = child;
            if (d[2] == 0) node->right = child;
        }
        for (auto &item: mp)if (item.second.second == 0) return item.second.first;
        return nullptr;
    }
};

int main() {


}