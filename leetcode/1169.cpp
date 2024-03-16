//
// Created by 徐浩闻 on 2024/3/15.
//
#include "bits/stdc++.h"

using namespace std;

struct Node {
    string name;
    string city;
    string time;
    string cash;

    string to_string() const{
        return name + "," + time + "," + cash + "," + city;
    }
};

class Solution {
public:
    vector<string> ans;

    void push_node(Node n) {
        string ss = "";
        ss = n.to_string();
        ans.emplace_back(ss);
    }

    vector<string> invalidTransactions(vector<string> &transactions) {

        map<string, vector<Node>> mmp;
        for (const auto &transaction: transactions) {
            istringstream ss(transaction);
            string property;
            vector<string> properties;

            while (getline(ss, property, ',')) {
                properties.push_back(property);
            }

            Node tmp;
            if (properties.size() == 4) {
                tmp.name = properties[0];
                tmp.time = properties[1];
                tmp.cash = properties[2];
                tmp.city = properties[3];
                mmp[tmp.name].emplace_back(tmp);
            }
        }
        for (const auto &[name, n]: mmp) {
            for (int i = 0; i < n.size(); i++) {
//                cout << n[i].to_string() << endl;
                if (stoi(n[i].cash) > 1000) {
                    push_node(n[i]);
                    continue;
                }
                for (int j = 0; j < n.size(); j++) {
                    if (i == j || n[i].city == n[j].city) continue;
                    if (abs(stoi(n[i].time) - stoi(n[j].time)) <= 60) {
                        push_node(n[i]);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<string> nn = {"alice,20,800,mtv", "alice,50,100,beijing"};
    Solution s;
    vector<string> ans = s.invalidTransactions(nn);
    cout << s.ans.size()<< endl;
}