#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <string>
#include <cmath>
#include <stack>
#include <map>
#include <set>
#define clr(a, v) memset(a, v, sizeof a)
#define maxn 30
#define maxint 999999999

using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b)
{
    return a.second > b.second;
}

class CLASS
{
private:
    int n, ans;
    int a[maxn];
    stack<int> s;
public:
    CLASS(int N)
    {
        n = N;
        ans = 0;
    }
    void INPUT()
    {
        for (int i = 0; i < n; i ++)
            cin >> a[i];
        sort(a, a+n);
    }
    void SOLVE()
    {
        s.push(a[0]);
        for (int i = 1; i < n; i ++)
        {
            if (s.empty())
            {
                s.push(a[i]);
                continue;
            }
            if (s.top()+1 == a[i])
            {
                s.pop();
                ans ++;
                continue;
            }
            s.push(a[i]);
        }
        cout << n-ans << endl;
    }
    void OUTPUT()
    {
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












