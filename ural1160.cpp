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

struct UNIT
{
    int x, y, z;
};

bool cmp(UNIT a, UNIT b)
{
    return a.z < b.z;
}

class cl
{
private:
    int n, m;
    vector<int> p;
    vector<bool> b;
    vector<UNIT> a;
    int ans = 0, num = 0;
public:
    void M()
    {
        In();
        Sv();
        Out();
    }
    void In()
    {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; i ++)
        {
            UNIT tmp;
            scanf("%d%d%d", &tmp.x, &tmp.y, &tmp.z);
            a.push_back(tmp);
        }
    }
    int find(int x)
    {
        if (p[x] != x)
            p[x] = find(p[x]);
        return p[x];
    }
    void Sv()
    {
        sort(a.begin(), a.end(), cmp);
        b.resize(m+3, false);
        p.resize(n+3);
        for (int i = 1; i <= n; i ++)
            p[i] = i;
        for (int i = 0; i < a.size(); i ++)
        {
            int x = find(a[i].x);
            int y = find(a[i].y);
            if (x != y)
            {
                p[x] = y;
                ans = max(ans, a[i].z);
                num ++;
                b[i] = true;
            }
        }
    }
    void Out()
    {
        //for (int i = 0; i < a.size(); i ++)
            //cout << a[i].z << endl;
        cout << ans << endl << num << endl;;
        for (int i = 0; i < m; i ++)
        {
            if (b[i] == true)
                cout << a[i].x << " " << a[i].y << endl;
        }
    }
};

int main()
{
    cl c;
    c.M();
}









































