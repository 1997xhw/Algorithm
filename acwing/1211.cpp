#include<bits/stdc++.h>
using namespace std;

int n;
int ants[55];

//��ʼ״̬��
//ants[0]�ұߵ������������ߵ����ϻᱻ��Ⱦ �ᱻ��Ⱦ 
//ants[0]��ߵ����������ߵ�����   
//								ͬʱ��x[0]�����ұߴ��������ߵ����� ��ᱻ��Ⱦ 
int main () {
	memset(ants, 0, sizeof ants);
	cin >> n;
	for(int i = 0; i < n; i ++) {
		cin >> ants[i];
	}
	int left = 0, right = 0;
	int x = ants[0];
	for (int i = 1; i < n; i ++) {
		if(abs(x) < abs(ants[i]) && ants[i] < 0) right++;
		else if(abs(x) > abs(ants[i]) && ants[i] > 0) left++;
	} 
	if(x > 0){
		if(right > 0)
			cout << right + left + 1;
		else
			cout << 1;
	} 
	else if(x < 0) {
		if(left > 0)
			cout << right + left + 1;
		else
			cout << 1;
	}
	 
}
