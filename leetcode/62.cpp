class Solution {
public:
    int getUglyNumber(int n) {
        vector <int> f(1,1);
        int ans = 0, t = 0, i = 0, j = 0, k = 0;
        while(--n) {
            t = min(f[i]*2, min(f[j]*3, f[k]*5));
            if(f[i]*2 == t) i++;
            if(f[j]*3 == t) j++;
            if(f[k]*5 == t) k++;
            f.push_back(t);
        }
        return f.back();
        
    }
};