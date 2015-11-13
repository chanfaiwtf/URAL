#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <string>
#include <cmath>
#include <map>
#define MaxN 30 //3500
#define MaxM 3000 // 13000

using namespace std;

class CLASS
{
private:
    int n, k;
    int a[550];
    int f[550][550];
public:
    CLASS()
    {
        memset(a, 0, sizeof a);
        memset(f, 0, sizeof f);
    }
    void INPUT()
    {
        cin >> n >> k;
        for (int i = 1; i <= n; i ++)
        {
            int t;
            cin >> t;
            a[i] = a[i-1] + t;
            f[0][i] = 999999999;
        }
    }
    int cal(int i, int j)
    {
        int ans;
        ans = abs((a[j]-a[i-1]) * ((j-a[j])-(i-1-a[i-1])));
        return ans;
    }
    void SOLVE()
    {
        for (int i = 1; i <= k; i ++)
        {
            for (int j = 1; j <= n; j ++)
            {
                int minn = 999999999;
                for (int l = 0; l <= j-1; l ++)
                    minn = min(minn, f[i-1][l]+cal(l+1, j));
                f[i][j] = minn;
            }
        }
    }
    void OUTPUT()
    {
        cout << f[k][n] << endl;
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














