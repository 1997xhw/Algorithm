//
// Created by 徐浩闻 on 2023/12/9.
//
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    struct infos {
        long long sum;
        string ids;
        int view;

        infos() {
        };
    };

    vector<vector<string>> mostPopularCreator(vector<string> &creators, vector<string> &ids, vector<int> &views) {
//        unordered_map<string, vector<pair<string, int>>> collections;
        unordered_map<string, infos> collections;
        for (int i = 0; i < creators.size(); i++) {
//            collections[creators[i]].emplace_back(ids[i], views[i]);
            string creator = creators[i], id = ids[i];
            int view = views[i];
            function<bool(infos)> cmp = [&](infos info) -> bool {
                if (info.view < view) return true;
                else if (info.view == view && info.ids > id) return true;
                else
                    return false;
            };
            if (collections.find(creator) == collections.end()) {
                collections[creator] = infos();
                collections[creator].sum = view;
                collections[creator].ids = id;
                collections[creator].view = view;
            } else {
                collections[creator].sum += view;
                if (cmp(collections[creator])) {
                    collections[creator].ids = id;
                    collections[creator].view = view;
                }
            }
        }
        // 将 map 的值复制到 vector 中
        vector<pair<string, infos>> sortedCollections;
        for (const auto &kv: collections) {
            sortedCollections.emplace_back(kv.first, kv.second);
        }

        // 对 vector 进行排序
        sort(sortedCollections.begin(), sortedCollections.end(),
             [](const pair<string, infos> &a, const pair<string, infos> &b) {
                 return a.second.sum > b.second.sum;
             });

        vector<vector<string>> ann;
        ann.emplace_back(vector<string>());
        ann[0].emplace_back(sortedCollections[0].first);
        ann[0].emplace_back(sortedCollections[0].second.ids);
        long long sum = sortedCollections[0].second.sum;
        for(int i = 1; i < sortedCollections.size(); i++) {
            if(sortedCollections[i].second.sum== sum) {
                // 每次您想添加一个新对时，添加一个新的 vector<string>
                ann.emplace_back(vector<string>());
                ann[i].emplace_back(sortedCollections[i].first);
                ann[i].emplace_back(sortedCollections[i].second.ids);

            }else break;
        }
        return ann;
    }
};

int main() {
    vector<string> cr = {"alice","bob","alice","chris"};
    vector<string> id = {"one","two","three","four"};
    vector<int> view = {5,10,5,4};
    Solution s;
    s.mostPopularCreator(cr, id, view);

}