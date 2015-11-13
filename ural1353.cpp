#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

class CLASS
{
private:
    int n;
    int f[10][100];
    long long ans;
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
        for (int i = 1; i <= 9; i ++)
            f[1][i] = 1;
        for (int i = 2; i <= 9; i ++)
            for (int j = 1; j <= 81; j ++)
            {
                f[i][j] = f[i-1][j];
                for (int k = 1; k <= 9 && j-k >= 0; k ++)
                    f[i][j] += f[i-1][j-k];
            }
    }
    void OUTPUT()
    {
        if (n == 1) cout << 10 << endl;
        else
        {
            ans = 0;
            for (int i = 1; i <= 9; i ++)
                ans += f[i][n];
            cout << ans << endl;
        }
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














