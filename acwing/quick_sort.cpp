# include <iostream>
using namespace std;

void quick_sort(int q[], int l, int r){
	if (l >= r) return;
	
	int i = l - 1, j = r + 1, x  = q[l + r >> 1];
	while(i < j){
		do i ++; while(q[i] < x);
		do j --; while(q[j] > x);
		if (i < j) swap(q[i], q[j]);

	} 
	quick_sort(q, l, j), quick_sort(q, j + 1, r);
}


int main(){
    int a[13] = {23, 4, 545, 6, 9, -3, 45, 56, 78, 23, 16, 36, 23};
    quick_sort(a, 0, 12);
    for(int i = 0; i < 13; i++){
    	printf("%d ", a[i]);
	}
    
    return 0;
}

