#include <iostream>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdio>
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
    int n, m;
    struct UNIT
    {
        int num;
        vector<pair<int, int> > v;
        UNIT()
        {
            num = 0;
            v.clear();
        }
    };
    vector<UNIT> a;
    int x, y, ans;
public:
    void In()
    {
        scanf("%d%d", &n, &m);
        a.resize(n+3);
        while (m -- > 0)
        {
            int xx, yy, z;
            scanf("%d%d%d", &xx, &yy, &z);
            a[xx].v.push_back(make_pair(yy, z));
        }
        scanf("%d%d", &x, &y);
    }
    void Sv()
    {
        queue<int> q;
        vector<int> d;
        vector<int> c; //统计入队次数
        vector<bool> b;
        d.resize(n+3, 0);
        c.resize(n+3, 0);
        b.resize(n+3, true);
        
        q.push(x);
        b[x] = false;
        c[x] = 1;
        while (!q.empty())
        {
            int tmp;
            tmp = q.front();
            q.pop();
            b[tmp] = true; //出队消除标记
            for (int i = 0; i < a[tmp].v.size(); i ++)
            {
                d[a[tmp].v[i].first] = max(d[a[tmp].v[i].first], d[tmp]+a[tmp].v[i].second);
                if (b[a[tmp].v[i].first] == true)
                {
                    b[a[tmp].v[i].first] = false;
                    c[a[tmp].v[i].first] ++;
                    q.push(a[tmp].v[i].first);
                    // if (c[y] > n) flag = false; 有负权
                }
            }
        }
        ans = d[y];
    }
    void Out()
    {
        if (ans == 0)
            cout << "No solution" << endl;
        else
            cout << ans << endl;
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



















