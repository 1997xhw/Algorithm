#include <iostream>
#include <algorithm>

using namespace std;

const int N = 50000;//N = sqrt(2e9)
bool st[N];
int primes[N],cnt = 0;//����ɸ
int S,res[N],len;

void get_primes(int n)
{
    for(int i = 2;i <= n;i++)
    {
        if(!st[i]) primes[cnt++] = i;
        for(int j = 0;primes[j]*i <= n;j++)
        {
            st[primes[j]*i] = true;
            if(i % primes[j] == 0) break;
        }
    }
}

int is_prime(int n)
{
    if(n < N) return !st[n];//û�б�ɸ��˵����������������true
    for(int i = 0;primes[i] <= n / primes[i];i++)
    {
        if(n % primes[i] == 0) return false;
    }
    return true;
}

void dfs(int last,int product,int S)//last��ʾ��һ���õ��������±���ʲô,product��ǰ��ߴ���Ľ��,S��ʾÿ�δ����ʣ�����
{
    if(S == 1)
    {
        res[len++] = product;
        return ;
    }
    //����20 = 2^2 * 5
    //N = P1^a1 * P2^a2 * ... * Pn^an
    //S = (1+p1+p1^2+...+p1^a1)(1+p2+p2^2+...+p2^a2)...(1+pn+pn^2+...+pn^an)
    //42 = (1 + 2 + 2^2)*(1 + 5),����2^2��5�ͷֱ�����ߴ���p1^2*p2^1
    if(S-1 > ((last < 0) ? 0 : primes[last]) && is_prime(S-1))
    {
        res[len++] = product * (S-1);
    }
    for(int i = last+1;primes[i] <= S / primes[i];i++)
    {
        int p = primes[i];
        for(int j = 1+p,t = p;j <= S;t *= p,j += t)
        {
            if(S % j == 0)
            {
                dfs(i,product*t,S/j);
            }
        }
    }
}

int main()
{
    get_primes(N-1);
    while(cin>>S)
    {
        len = 0;
        dfs(-1,1,S);

        sort(res,res+len);

        cout << len << endl;
        if (len)
        {
            sort(res, res + len);
            for (int i = 0; i < len; i ++ ) cout << res[i] << ' ';
            cout << endl;
        }
    }
    return 0;
}

