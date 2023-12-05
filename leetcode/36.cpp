#include<bits/stdc++.h>
using namespace std;


bool isValidSudoku(vector<vector<char>>& board) {
	int map[9][10][3];
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			char c = board[i][j];
			if(c != '.') {
				int cc = c - '0';
				if(!map[i][cc][0])
					map[i][cc][0]++;
				else return false;
				if(!map[j][cc][1])
					map[j][cc][1]++;
				else return false;
				if(!map[(i / 3) * 3 +(j / 3)][cc][2])
					map[(i / 3) * 3 +(j / 3)][cc][2]++;
				else return false;
			}

		}
	}
	return true;

}

int main () {






}