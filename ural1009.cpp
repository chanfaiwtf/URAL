#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

class CLASS
{
private:
    int n, k;
    int f[1010][2];
public:
    CLASS()
    {
        memset(f, 0, sizeof f);
    }
    void INPUT()
    {
        cin >> n >> k;
    }
    void SOLVE()
    {
        f[1][0] = 0;
        f[1][1] = k-1;
        for (int i = 2; i <= n; i ++)
        {
            f[i][0] = f[i-1][1];
            f[i][1] = f[i-1][0]*(k-1)+f[i-1][1]*(k-1);
        }
    }
    void OUTPUT()
    {
        cout << f[n][0]+f[n][1] << endl;
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














