#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <string>
#include <cmath>
#include <map>
#include <set>
#define maxn 15
#define maxint 999999999

using namespace std;

struct NODE
{
    int l, r;
    NODE(int L = 0, int R = 0)
    {
        l = L;
        r = R;
    }
};

bool cmp(NODE a, NODE b)
{
    if (a.r != b.r) return a.r < b.r;
    else return a.l < b.l;
}

class CLASS
{
private:
    int n, m;
    vector<NODE> v;
    vector<int> f, l;
public:
    CLASS()
    {
        m = 0;
    }
    void INPUT()
    {
        cin >> n;
        for (int i = 0; i < n; i ++)
        {
            int l, r;
            cin >> l >> r;
            NODE tmp(l, r);
            v.push_back(tmp);
            m = max(m, r);
        }
        NODE tmp(0, 0);
        v.push_back(tmp);
    }
    void SOLVE()
    {
        sort(v.begin(), v.end()-1, cmp);
        f.resize(m, 0);
        l.resize(m, -1);
        for (int i = 0; i < n; i ++)
        {
            if (v[i].r != v[i+1].r)
                l[v[i].r] = v[i].l;
        }
        for (int i = 1; i <= m; i ++)
        {
            if (l[i] == -1)
                f[i] = f[i-1];
            else
                f[i] = max(f[i-1], f[l[i]-1]+1);
        }
    }
    void OUTPUT()
    {
        //for (int i = 0; i < v.size(); i ++) cout << v[i].l << " " << v[i].r << endl;
        cout << f[m] << endl;
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
        CLASS cl;
        cl.MAIN();
}














