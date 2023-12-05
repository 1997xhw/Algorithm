#include<iostream>
using namespace std;
const int N = 100003;
int h[N], e[N], ne[N], idx;

//向哈希表插入一个数
void insert(int x) {
	int k = (x % N + N) % N;
	e[idx] = x;
	ne[idx] = h[k];
	h[k] = idx ++;
	//拉链法 
} 

//在哈希表中查询某个数是否存在
bool find(int x) {
	int k = (x % N + N) % N;
	for (int i = h[k]; i != -1; i = ne[i]) {
		if (e[i] == x)
			return true;
	}
	return false;
} 

int main () {
	
} 
