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

int f[910][8110];
int c[910][8110];

class CLASS
{
private:
    int s1, s2;
    vector<int> ans;
public:
    CLASS()
    {
    }
    void INPUT()
    {
        cin >> s1 >> s2;
        //cout << f[s1][s2] << endl;
    }
    void SOLVE()
    {
        if (s1 > 900 || s2 > 8100)
        {
            cout << "No solution" << endl;
            return;
        }
        int len = f[s1][s2];
        if (len > 100)
        {
            cout << "No solution" << endl;
            return;
        }
        while (ans.size() != len)
        {
            int k = c[s1][s2];
            ans.push_back(k);
            s1 = s1 - k;
            s2 = s2 - k*k;
        }
        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i ++)
            cout << ans[i];
        cout << endl;
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
    clr(f, maxint);
    clr(c, 0);
    f[0][0] = 0;
    for (int i = 1; i <= 900; i ++)
        for (int j = 1; j <= 8100; j ++)
            for (int k = 1; k <= 9; k ++)
            {
                if (k > i || k*k > j) break;
                if (f[i][j] > f[i-k][j-k*k]+1)
                {
                    f[i][j] = f[i-k][j-k*k]+1;
                    c[i][j] = k;
                }
            }
    
    int n;
    cin >> n;
    while (n -- > 0) {
        CLASS cl;
        cl.MAIN();
    }
}












