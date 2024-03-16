//
// Created by 徐浩闻 on 2024/3/14.
//
#include "bits/stdc++.h"

using namespace std;

const vector<pair<int, int>> dis = {{1,  0},
                                    {1,  -1},
                                    {0,  -1},
                                    {-1, -1},
                                    {-1, 0},
                                    {-1, 1},
                                    {0,  1},
                                    {1,  1}};

class Solution {
public:
    int m, n;

    bool check_pos_f(int rMove, int cMove, int i) {
        return rMove + dis[i].first >= 0 && rMove + dis[i].first < m && cMove + dis[i].second >= 0 &&
               cMove + dis[i].second < n;
    }

    bool checkMove(vector<vector<char>> &board, int rMove, int cMove, char color) {
        m = board.size();
        n = board[0].size();
        board[rMove][cMove] = color;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        char ai;
        if (color == 'W') ai = 'B'; else ai = 'W';
        for (int i = 0; i < 8; i++) {
            auto tmp = make_pair(rMove, cMove);
            if (check_pos_f(rMove, cMove, i) && board[rMove + dis[i].first][cMove + dis[i].second] == color) continue;
            auto tp = make_pair(rMove, cMove);
            while (check_pos_f(tp.first, tp.second, i)) {

                if (board[tp.first + dis[i].first][tp.second + dis[i].second] == color) {
//                    if ((check_pos_f(tp.first + dis[i].first, tp.second + dis[i].second, i) &&
//                             board[tp.first + 2 * dis[i].first][tp.second + 2 * dis[i].second] == color))
//                        break;
                    return true;
//                    if ((check_pos_f(tp.first + dis[i].first, tp.second + dis[i].second, i) &&
//                         board[tp.first + 2 * dis[i].first][tp.second + 2 * dis[i].second] != color) ||
//                        !check_pos_f(tp.first + dis[i].first, tp.second + dis[i].second, i)) {
//                        if (abs(tmp.first - tp.first) > 2 || abs(tmp.second - tp.second) > 2){
//                            cout << tp.first + dis[i].first << " " << tp.second + dis[i].second << endl;
//                            return true;
//                        }
//                    }
                } else if (board[tp.first + dis[i].first][tp.second + dis[i].second] == '.') break;
                tp.first = tp.first + dis[i].first;
                tp.second = tp.second + dis[i].second;
            }

        }
        return false;
    }
};

int main() {


}