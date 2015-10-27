#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

struct UNIT
{
    int num;
    set<int> v;
    int deg;
    bool flag;
    UNIT()
    {
        flag = true;
        deg = 0;
        v.clear();
    }
};

bool cmp(UNIT a, UNIT b)
{
    return a.deg < b.deg;
}

class cl
{
private:
    int n;
    int nn;
    string st[20][5];
    int a[20][5];
    map<string, int> m;
    set<string> s;
    int ans = 0;
    UNIT vv[20];
    int v[20];
public:
    bool FIND(int x, int y)
    {
        if (vv[x].v.count(y) != 0)
            return true;
        return false;
    }
    void M()
    {
        In();
        Sv();
        Out();
    }
    void In()
    {
        cin >> n;
        int t = 0;
        for (int i = 0; i < n; i ++)
        {
            vv[i].num = i;
            for (int j = 0; j < 3; j ++)
            {
                string st;
                cin >> st;
                if (s.count(st) == 0)
                {
                    s.insert(st);
                    m[st] = t;
                    t ++;
                }
                a[i][j] = m[st];
                
                for (int k = 0; k < i; k ++)
                {
                    for (int l = 0; l < 3; l ++)
                    {
                        if (a[i][j] == a[k][l] && FIND(i, k)==false)
                        {
                            vv[i].v.insert(k);
                            vv[i].deg ++;
                            vv[k].v.insert(i);
                            vv[k].deg ++;
                        }
                    }
                }
            }
        }
    }
    void Sv()
    {
        nn = n;
        while (true)
        {
            sort(vv, vv+n, cmp);
            if (n == 0 || vv[0].deg == 999) break;
            vv[0].flag = false;
            vv[0].deg = 999;
            ans ++;
            for (set<int>::iterator it = vv[0].v.begin(); it != vv[0].v.end(); it ++)
            {
                for (int i = 0; i < n; i ++)
                {
                    if (vv[i].num == *it)
                    {
                        vv[i].deg = 999;
                    }
                }
            }
        }
    }
    void Out()
    {
        /*
        for (int i = 0; i < n; i ++)
        {
            for (int j = 0; j < 3; j ++)
                cout << a[i][j] << " ";
            cout << endl;
        }
        for (int i = 0; i < n; i ++)
        {
            cout << vv[i].num << ": " << endl;
            for (set<int>::iterator it = vv[i].v.begin(); it != vv[i].v.end(); it ++)
                cout << *it << " ";
            cout << endl << vv[i].deg << endl;
        }
        */
        cout << ans << endl;
    }
};

int main()
{
    cl c;
    c.M();
}



















