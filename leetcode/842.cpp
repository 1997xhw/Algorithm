#include<bits/stdc++.h>
using namespace std;

//回溯+剪枝
//
//        使用回溯算法分割字符串，拆分成符合条件（斐波那契数列）的子串。
//其实回溯改变的只有前两个数字，因为当前两个数确定了，后面所有的数都将确定。
//两个数字相加，和的长度不会超过两个数中的最大长度+1。
//因为最少需要分割成3个子串，且两个数相加等于第三个数，所以一个子串最大长度不会超过(len - 1) / 2，且都是是int类型，不会超过10位。
//如果拆分时第一个数是‘0’，则只能有1位的长度。
//根据前面得到的“最大数字长度”，若字符串剩余字符大小小于最大数字的长度，则最后一个数字肯定不会由前面两个数相加得到。

string _num;
int n;
vector<vector<int>> list1;
bool dfs(int u);
bool check(vector<int>& a, vector<int>& b, vector<int> & c);
vector<int> splitIntoFibonacci(string num) {
	_num = num;
	n = _num.size();
	vector<int> ans;
	if(dfs(0)) {
		for(auto i : list1) {
			string tmp = "";
			for(auto j : i)
				tmp += ('0' + j);
			reverse(tmp.begin(), tmp.end());
            long long aa = 0;
            for(auto k : tmp){
                aa*=10;
                aa+=(k-'0');
            }
            if(aa > 2147483647) {
                vector<int> ff;
                return ff;
            }
            ans.push_back(aa);
		}
	}
	return ans;

}

bool dfs(int u) {
	int m = list1.size();
	if(u == n) return m >=3 ;
	int max = _num[u] == '0' ? u + 1 : n;
    if(_num[u]=='0' && list1.size() > 2) return false;
	vector<int> cur;
	for(int i = u; i < max; i++) {
        if((cur.size() >= (n - 1) / 2)   || cur.size() > 10 || (cur.size() > n-1-u)){
//            cout << (cur.size() > (n - 1) / 2) << " " << (cur.size() > n-1-u) << endl;
            return false;
        }
        cur.insert(cur.begin(), _num[i] - '0');
        if(m < 2 || check(list1[m - 2], list1[m - 1], cur)) {
			list1.push_back(cur);
			if(dfs(i + 1)) return true;
			list1.pop_back();
		}
	}
	return false;
}

bool check(vector<int>& a, vector<int>& b, vector<int> & c) {
	vector<int> ans;
	int t = 0;
	for (int i = 0; i < a.size() || i < b.size(); i++) {
		if(i < a.size()) t += a[i];
		if(i < b.size()) t += b[i];
		ans.push_back(t % 10);
		t /= 10;
	}
	if(t) ans.push_back(1);

	bool ok = (ans.size() == c.size());
	for(int i = 0; ok && i < ans.size(); i++)
		if(ans[i] != c[i]) ok = !ok;
	return ok;

}


int main() {
	vector<int> ans = splitIntoFibonacci("1101111");
	for(auto i : ans) {
		cout << i << endl;
	}
}