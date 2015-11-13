#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <cmath>
#include <map>
#define MaxN 500

using namespace std;

class CLASS
{
private:
    int n;
    long long f[MaxN+10][MaxN+10];
public:
    CLASS()
    {
        memset(f, 0, sizeof f);
    }
    void INPUT()
    {
        cin >> n;
    }
    void SOLVE()
    {
        for (int i = 1; i <= n; i ++)
            f[i][i] = 1;
        for (int i = 2; i <= n; i ++)
            for (int j = i-1; j >= 1; j --)
                f[j][i] = f[j+1][i] + f[j+1][i-j];
    }
    void OUTPUT()
    {
        cout << f[1][n]-1 << endl;
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














