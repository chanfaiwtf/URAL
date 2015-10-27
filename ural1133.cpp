#include <iostream>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <string>
#include <vector>
#include <cstdio>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <map>

using namespace std;

class CLASS
{
private:
    long long f[2020];
    long long a, b, n, aa, fa, bb, fb, nn, ans;
public:
    CLASS();
    void MAIN();
    void READ();
    void SOLVE();
    void OUTPUT();
};

CLASS::CLASS()
{
    memset(f, 0, sizeof f);
}

void CLASS::READ()
{
    cin >> aa >> fa >> bb >> fb >> nn;
    // a < b
}

void CLASS::SOLVE()
{
    if (aa > bb)
    {
        long long cc;
        cc = aa; aa = bb; bb = cc;
        cc = fa; fa = fb; fb = cc;
    }
    a = aa + 1000;
    b = bb + 1000;
    n = nn + 1000;
    
    long long l = -2000000000, r = 2000000000;
    while (l < r)
    {
        long long mid = (l+r) / 2;
        long long x, y, z = 0;
        x = fa; y = mid;
        for (long long i = a+2; i <= b; i ++)
        {
            z = x + y;
            x = y;
            y = z;
            if (abs(z) > 5000000000)
                break;
        }
        if (y == fb)
        {
            ans = mid;
            break;
        }
        else if (y > fb)
            r = mid;
        else if (y < fb)
            l = mid;
    }
    
    f[a] = fa;
    f[a+1] = ans;
    if (n > a+1)
    {
        for (long long i = a+2; i <= n; i ++)
            f[i] = f[i-1] + f[i-2];
    }
    else if (n < a)
    {
        for (long long i = a-1; i >= n; i --)
            f[i] = f[i+2] - f[i+1];
    }
}

void CLASS::OUTPUT()
{
    cout << f[n] << endl;
}

void CLASS::MAIN()
{
    READ();
    SOLVE();
    OUTPUT();
}

int main()
{
    CLASS cla;
    cla.MAIN();
}














