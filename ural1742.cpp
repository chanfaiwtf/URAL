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
    struct UNIT
    {
        int num;
        int deg;
        int tar;
        int vst;
        UNIT()
        {
            num = 0;
            deg = 0;
            tar = 0;
            vst = 0;
        }
    };
    int n, m, l;
    vector<UNIT> a;
    int minn = 0, maxn = 0;
public:
    void M()
    {
        In();
        Sv();
        Out();
    }
    void In()
    {
        cin >> n;
        a.resize(n+2);
        for (int i = 1; i <= n; i ++)
        {
            cin >> a[i].tar;
            a[a[i].tar].deg ++;
        }
    }
    void Sv()
    {
        l = 1;
        for (int i = 1; i <= n; i ++)
            if (a[i].deg == 0)
            {
                m = ++l;
                minn ++;
                maxn = maxn + dfs(i);
            }
        for (int i = 1; i <= n; i ++)
            if (a[i].vst == 0)
            {
                maxn ++;
                minn ++;
                int tmp = i;
                while (a[tmp].vst == 0)
                {
                    a[tmp].vst = 1;
                    tmp = a[tmp].tar;
                }
            }
    }
    int dfs(int x)
    {
        if (a[x].vst != 0)
        {
            if (a[x].vst >= m)
                return a[x].vst-m+1;
            else return l-m;
        }
        a[x].vst = l++;
        return dfs(a[x].tar);
    }
    void Out()
    {
        cout << minn << " " << maxn << endl;
    }
};

int main()
{
    cl c;
    c.M();
}



















