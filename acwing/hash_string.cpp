#include<iostream>
using namespace std;
const int N = 100003;
int h[N], e[N], ne[N], idx;

//���ϣ�����һ����
void insert(int x) {
	int k = (x % N + N) % N;
	e[idx] = x;
	ne[idx] = h[k];
	h[k] = idx ++;
	//������ 
} 

//�ڹ�ϣ���в�ѯĳ�����Ƿ����
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
