#include <bits/stdc++.h>
using namespace std;


bool check(int x){
	return true;
} 
int bsearch_l(int l,int r) {

	while(l < r) {
		int mid = l + r >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	return l;
}

int bsearch_r(int l, int r) {
	while(l < r) {
		int mid = l + r + 1 >> 1;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	return l;
}


int main() {


}
//mid - (H[i] - mid)
//mid + (mid - H[i])
