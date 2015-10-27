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
        cin >> n >> m;
        a.resize(2*n+2);
        for (int i = 0; i < m; i ++)
        {
            int xx, yy;
            cin >> xx >> yy;
            a[xx].v.push_back(make_pair(yy, 0));
            a[xx+n].v.push_back(make_pair(yy, 1));
            a[yy].v.push_back(make_pair(xx+n, 1));
            a[yy+n].v.push_back(make_pair(xx+n, 0));
        }
        cin >> x >> y;
    }
    int Sv(int x, int y)
    {
        vector<int> d;
        vector<bool> s;
        d.resize(2*n+2);
        s.resize(2*n+2);
        for (int i = 1; i <= 2*n; i ++)
        {
            d[i] = 99999999;
            s[i] = false;
        }
        for (int j = 0; j < a[x].v.size(); j ++)
            d[a[x].v[j].first] = a[x].v[j].second;
        d[x] = 0;
        s[x] = true;
        int m, now = 0;
        for (int i = 1; i < 2*n; i ++)
        {
            m = 99999999;
            for (int j = 1; j <= 2*n; j ++)
                if (!s[j] && d[j]<m)
                {
                    now = j;
                    m = d[j];
                }
            if (m == 99999999) continue;
            s[now] = true;
            d[now] = m;
            for (int j = 0; j < a[now].v.size(); j ++)
                if (!s[a[now].v[j].first] && (d[now]+a[now].v[j].second) < d[a[now].v[j].first])
                    d[a[now].v[j].first] = d[now]+a[now].v[j].second;
        }
        //for (int i = 1; i <= 2*n; i ++)
        //{
        //    cout << i << ": " << endl;
        //    for (int j = 0; j < a[i].v.size(); j ++)
        //        cout << "(" << a[i].v[j].first << "," << a[i].v[j].second << ")" << endl;
        //}
        //for (int i = 1; i <= 2*n; i ++)
        //    cout << d[i] << " ";
        //cout << endl;
        return min(d[y], d[y+n]);
    }
    void Out()
    {
        cout << ans << endl;
    }
    void M()
    {
        In();
        ans = min(Sv(x, y), Sv(x+n, y));
        //ans = Sv(x, y);
        Out();
    }
};

int main()
{
    cl c;
    c.M();
}



















