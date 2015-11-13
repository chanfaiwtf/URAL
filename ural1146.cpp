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
    int n, ans;
    int a[110][110];
    int b[110], f[110];
public:
    CLASS()
    {
        memset(a, 0, sizeof a);
        ans = -999999999;
    }
    void INPUT()
    {
        cin >> n;
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= n; j ++)
            {
                int k;
                cin >> k;
                a[i][j] = a[i][j-1]+k;
            }
    }
    void SOLVE()
    {
        for (int i = 0; i < n; i ++)
            for (int j = i+1; j <= n; j ++)
            {
                memset(f, 0, sizeof f);
                memset(b, 0, sizeof b);
                b[1] = f[1] = a[1][j]-a[1][i];
                if (i == 0 && j == i+1)
                    ans = b[1];
                for (int k = 2; k <= n; k ++)
                {
                    b[k] = a[k][j]-a[k][i];
                    f[k] = max(b[k], f[k-1]+b[k]);
                    ans = max(ans, f[k]);
                }
            }
    }
    void OUTPUT()
    {
        cout << ans << endl;
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














