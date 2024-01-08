//1 zhangpangle
#include "bits/stdc++.h"
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    cout << a - b;
}


//2 moshu
#include "bits/stdc++.h"

using namespace std;

int main() {
    int n, sum = 0;
    cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        int tmp;
        scanf("%d", &tmp);
        a[i] = tmp;
    }
    for (int i = 1; i <= n; ++i) {
        int p1, p2, tmp;
        scanf("%d %d", &p1, &p2);
        tmp = a[p1] + a[p2];
        sum += (tmp < a[i] ? tmp : a[i]);
    }
    cout << sum << endl;
    return 0;
}

//3 shuzu
#include "bits/stdc++.h"
using namespace std;
int main() {
    int n;
    int nums[100010];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int res = 0;
    for (int i = 1; i < n; i++) {
        if (nums[i - 1] <= nums[i] && nums[i] <= nums[i + 1]) {
            nums[i] = nums[i + 1] + 1;
            res++;
        }
    }
    cout << res << endl;
}