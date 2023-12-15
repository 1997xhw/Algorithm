//
// Created by 徐浩闻 on 2023/12/15.
//
#include "bits/stdc++.h"

using namespace std;

class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> map;

    TimeMap() {

    }

    void set(string key, string value, int timestamp) {
        map[key].emplace_back(value, timestamp);
    }

    string get(string key, int timestamp) {
        if (map.find(key) == map.end() || map[key][0].second > timestamp) return "";
        else {
            vector<pair<string, int>> &mm = map[key];
            int l = 0, r = mm.size() - 1;
            	while(l < r) {
            		int mid = l + r + 1 >> 1;
            		if(timestamp > mm[mid].second) l = mid;
            		else r = mid - 1;
            	}
            	return mm[l].first;
        }
    }
};

int main() {


}