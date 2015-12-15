#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <string>
#include <cmath>
#include <map>
#include <set>
#define maxn 6010
#define maxint 999999999

using namespace std;

class CLASS
{
private:
    int n, r;
    int f[maxn][2];
    bool b[maxn];
    vector<int> a[maxn];
public:
    CLASS()
    {
        r = 0;
        memset(f, 0, sizeof f);
        memset(b, 0, sizeof b);
    }
    void INPUT()
    {
        cin >> n;
        for (int i = 1; i <= n; i ++)
            cin >> f[i][1];
        int x, y;
        cin >> x >> y;
        r = y;
        while (x != 0 || y != 0)
        {
            if (r == x) r = y;
            b[x] = true;
            a[x].push_back(y);
            a[y].push_back(x);
            cin >> x >> y;
        }
    }
    void SOLVE()
    {
        for (int i = 1; i <= n; i ++)
            if (b[i] == false)
            {
                r = i;
                break;
            }
        memset(b, 0, sizeof b);
        dfs(r);
    }
    void dfs(int r)
    {
        b[r] = true;
        f[r][0] = 0;
        for (int i = 0; i < a[r].size(); i ++)
        {
            int child = a[r][i];
            if (b[child] == false)
            {
                dfs(child);
                f[r][0] += max(f[child][1], f[child][0]);
                f[r][1] += f[child][0];
            }
        }
    }
    void OUTPUT()
    {
        cout << max(f[r][0], f[r][1]) << endl;
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












