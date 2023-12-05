#include<bits/stdc++.h>
using namespace std;
const int N = 100003;
int p[N], size[N], d[N];
//p[]存储每个点的祖宗节点, size[]只有祖宗节点的有意义, 表示祖宗节点所在结合中的点的数量
//d[x]存储x到p[x]的距离 
 
//返回x的祖宗节点
int find(int x) {
	if(p[x] != x) {
		int u = find(p[x]);
		d[x] += d[p[x]];
		p[x] = u;
		
	}
	return p[x];
}


int main() {
	int n;
	//初始化 
	for (int i = 1; i <= n; i++) {
		p[i] = i;
		size[i] = 1;
		d[i] = 0; 
	}
	
	//合并a和b所在的集合
	size[find(b)] += size[find(a)];
	p[find(a)] = find[b];
	d[find(a)] = distance;//具体问题具体分析 
	
	 


}
