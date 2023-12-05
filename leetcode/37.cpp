#include<bits/stdc++.h>
using namespace std;
int map[9][10][3];

bool isValid(int row, int col, char val, vector<vector<char>>& board) {
	if(map[row][val - '0'][0]) return false;
	if(map[col][val - '0'][1]) return false;
	if(map[(row / 3) * 3 +(col / 3)][val - '0'][2]) return false;
	return true;
}

bool solve(vector<vector<char>>& board) {
	for(int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[0].size(); j++) {
			if(board[i][j] != '.') continue;
			for(char k = '1'; k <= '9'; k++) {
				if(isValid(i, j, k, board)) {
					board[i][j] = k;
					map[i][k - '0'][0]++;
					map[j][k - '0'][1]++;
					map[(i / 3) * 3 +(j / 3)][k - '0'][2]++;
					if(solve(board)) return true;
					board[i][j] = '.';
					map[i][k - '0'][0]--;
					map[j][k - '0'][1]--;
					map[(i / 3) * 3 +(j / 3)][k - '0'][2]--;
				}
			}
			return false;
		}
	}
	return true;
}

void solveSudoku(vector<vector<char>>& board) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			char c = board[i][j];
			if(c != '.') {
				int cc = c - '0';
				if(!map[i][cc][0])
					map[i][cc][0]++;
				if(!map[j][cc][1])
					map[j][cc][1]++;
				if(!map[(i / 3) * 3 +(j / 3)][cc][2])
					map[(i / 3) * 3 +(j / 3)][cc][2]++;
			}
		}
	}
	solve(board);

}
int main() {




}