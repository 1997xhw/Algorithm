//
// Created by 徐浩闻 on 2024/1/29.
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
    int minimumOperations(TreeNode *root) {
        queue<TreeNode *> qu;
        qu.push(root);
        int ans = 0;
        while (!qu.empty()) {
            queue<TreeNode *> qu2;
            qu2.swap(qu);
            map<int, int> mp;
            int ff = 0;
            while (!qu2.empty()) {
                auto tmp = qu2.front();
                mp[tmp->val] = ff++;
                if (tmp->left != nullptr) qu.push(tmp->left);
                if (tmp->right != nullptr) qu.push(tmp->right);
                qu2.pop();
            }
            int n = mp.size();
            ans += n;
            vector<bool> vis(n, false);
            vector<int> b;
            vector<int> values;
            values.reserve(mp.size());
            for (const auto &pair: mp) {
                values.push_back(pair.second);
            }
            for (auto &va: values) {
                int tmp = va;
                if (vis[tmp]) continue;
                while (!vis[tmp]) {
                    vis[tmp] = true;
                    tmp = values[tmp];
                }
                ans--;
            }
//            for (auto &item: mp) {
//                auto tmp = item.second;
//                if (vis[tmp]) continue;
//                while (!vis[tmp]) {
//                    vis[tmp] = true;
//                    auto it = next(mp.begin(), tmp);
//                    tmp = it->second;
//                }
//                ans -= 1;
//            }

        }
        return ans;
    }
};

int main() {


}