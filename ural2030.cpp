#pragma comment(linker, "/STACK:16777216")
#include <iostream>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <map>

using namespace std;

class cl
{
private:
    int n;
    struct UNIT
    {
        int num;
        long long val;
        vector<int> v;
        UNIT()
        {
            num = 0;
            val = 0;
            v.clear();
        }
    };
    vector<UNIT> a;
    vector<long long> v, w;
public:
    void In()
    {
        cin >> n;
        a.resize(n+1);
        for (int i = 1; i <= n; i ++)
        {
            cin >> a[i].val;
            a[i].val = a[i].val % 1000000007;
        }
        for (int i = 1; i <= n-1; i ++)
        {
            int x, y;
            cin >> x >> y;
            a[x].v.push_back(y);
            a[y].v.push_back(x);
        }
    }
    void dfs(int x, int y)
    {
        w[x] = y;
        for (int i = 0; i < a[x].v.size(); i ++)
        {
            int &z = a[x].v[i];
            if (z != x && z != y)
                dfs(z, x);
        }
    }
    void Sv()
    {
        v.resize(n+2, 0);
        w.resize(n+2, 0);
        dfs(1, 0);
        int t;
        cin >> t;
        while (t -- > 0)
        {
            int x, y;
            cin >> x >> y;
            int z = w[y];
            if (x == 1)
            {
                v[y] = (v[y] + a[y].val + v[z]) % 1000000007;
                a[z].val = (a[z].val + a[y].val + v[z]) % 1000000007;
            }
            else cout << (a[y].val + v[z]) % 1000000007 << endl;
        }
    }
    void Out()
    {
    }
    void M()
    {
        In();
        Sv();
        Out();
    }
};

int main()
{
    cl c;
    c.M();
    
}


















