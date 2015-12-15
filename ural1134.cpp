#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <string>
#include <cmath>
#include <map>
#include <set>
#define clr(a, v) memset(a, v, sizeof a)
#define maxn 1010
#define maxint 999999999

using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b)
{
    return a.second > b.second;
}

int CASE = 0;

class CLASS
{
private:
    int n, m;
    int a[1010];
    bool b[1010];
    bool ans;
public:
    CLASS(int N)
    {
        n = N;
        ans = true;
        clr(a, 0);
        clr(b, 0);
    }
    void INPUT()
    {
        cin >> m;
        for (int i = 0; i < m; i ++)
            cin >> a[i];
        sort(a, a+m);
    }
    void SOLVE()
    {
        for (int i = 0; i < m; i ++)
        {
            int tmp = a[i];
            if (tmp<0 || tmp>n)
            {
                ans = false;
                break;
            }
            if (tmp == n)
            {
                if (b[n-1] == 0)
                {
                    b[n-1] = 1;
                    continue;
                }
                else
                {
                    ans = false;
                    break;
                }
            }
            if (tmp == 0)
            {
                if (b[0] == 0)
                {
                    b[0] = 1;
                    continue;
                }
                else
                {
                    ans = false;
                    break;
                }
            }
            if (b[tmp-1] == 0)
            {
                b[tmp-1] = 1;
            }
            else if (b[tmp] == 0)
            {
                b[tmp] = 1;
            }
            else
            {
                ans = false;
                break;
            }
        }
    }
    void OUTPUT()
    {
        //for (int i = 0; i < m; i ++)
        //    cout << a[i] << " ";
        //cout << endl;
        if (ans == true) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    void MAIN()
    {
        INPUT();
        SOLVE();
        OUTPUT();
    }
};

int main()
{
    int n;
    cin >> n;
        CLASS cl(n);
        cl.MAIN();
}












