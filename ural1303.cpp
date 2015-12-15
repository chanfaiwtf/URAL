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
    if (a.l != b.l) return a.l < b.l;
    else return a.r < b.r;
}

class CLASS
{
private:
    int n, m, maxin, ans;
    vector<NODE> v, w, r;
    vector<int> f, l;
public:
    CLASS()
    {
        m = 0;
        ans = 0;
    }
    void INPUT()
    {
        cin >> m;
        int l=-1, r=-1;
        while (l!=0 || r!=0)
        {
            cin >> l >> r;
            //if (r<=0) continue;
            NODE tmp(l, r);
            v.push_back(tmp);
        }
        n = v.size()-1;
    }
    void SOLVE()
    {
        
        sort(v.begin(), v.end()-1, cmp);
        
        //for (int i = 0; i < v.size(); i ++) cout << v[i].l << " " << v[i].r << endl; cout << endl;
        
        for (int i = 0; i < n; i ++)
        {
            if (v[i].r <= 0) continue;
            if (i == n-1)
            {
                if (w.size() == 0)
                    w.push_back(v[i]);
                else if (w[w.size()-1].r < v[i].r)
                    w.push_back(v[i]);
                continue;
            }
            if (v[i].l != v[i+1].l)
            {
                if (w.size() == 0)
                    w.push_back(v[i]);
                else if (w[w.size()-1].r < v[i].r)
                    w.push_back(v[i]);
            }
        }
        
        //for (int i = 0; i < w.size(); i ++) cout << w[i].l << " " << w[i].r << endl;
        
        NODE tmp(m+1, m+1);
        w.push_back(tmp);
        int now = 0;
        for (int i = 0; i < w.size()-1; i ++)
        {
            if (w[i].l <= now && w[i+1].l > now)
            {
                r.push_back(w[i]);
                now = w[i].r;
                if (now >= m)
                {
                    cout << r.size() << endl;
                    for (int j = 0; j < r.size(); j ++)
                        cout << r[j].l << " " << r[j].r << endl;
                    return;
                }
            }
        }
        cout << "No solution" << endl;
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
    CLASS cl;
    cl.MAIN();
}












