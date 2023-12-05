#include<bits/stdc++.h>
using namespace std;


long long dividePlayers(vector<int>& skill) {
	long long sum = 0;
	int ss[1005];
	memset(ss, 0, sizeof(ss));
	for (auto i : skill) {
		sum+=i;
		ss[i]++;
	}
	long long temp = 2 * sum / skill.size();
	cout << "temp:" << temp << endl;
	if(sum % temp != 0) return -1;
	long long ans = 0; 
	for(int i = 0; i < 1005; i++) {
		if(ss[i] && ss[i] == ss[temp - i]) {
//			cout << "i:" << i << " ss[i]:" << ss[i] << "  ss[temp - i]:" << ss[temp - i] << endl;
			if(i == (temp - i)) ans+=(ss[i]/2*(i * (temp - i)));
			else ans+=(ss[i]*(i * (temp - i)));
			ss[temp - i] = 0;
			ss[i] = 0;
		}
		else if(ss[i] && ss[i] != ss[temp - i]) return -1;
	}
	return ans;
}

int main() {
	vector<int> skill={3,4};
	cout << dividePlayers(skill);


}