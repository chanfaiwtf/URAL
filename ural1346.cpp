#include <iostream>
#include <algorithm>
#include <cstring>
#include <fstream>
#include <vector>
#include <cstdio>
#include <string>
#include <cmath>
#include <stack>
#include <map>
#include <set>
#define clr(a, v) memset(a, v, sizeof a)
#define maxn 30
#define maxint 0x3f3f3f3f

using namespace std;

class CLASS
{
private:
    int a, b;
    int v[100010], f[100010], g[100010];
public:
    CLASS()
    {
        clr(f, maxint);
        clr(g, maxint);
    }
    void INPUT()
    {
        cin >> a >> b;
        b = b-a;
        f[0] = g[0] = 1;
        for (int i = 0; i <= b; i ++)
        {
            cin >> v[i];
            if (i == 0) continue;
            if (v[i] < v[i-1])
                f[i] = min(f[i-1], g[i-1])+1;
            else
                f[i] = f[i-1];
            if (v[i] > v[i-1])
                g[i] = min(f[i-1], g[i-1])+1;
            else
                g[i] = g[i-1];
        }
        cout << min(f[b], g[b]) << endl;
    }
    void SOLVE()
    {
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
    //cin >> n;
    //while (n -- > 0) {
        CLASS cl;
        cl.MAIN();
    //}
}












