#include <iostream>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdio>
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
    int n;
    string s[220];
    int x[220], y[220], z[220];
    bool b[220][220];
public:
    void In()
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++)
        {
            cin >> s[i];
            scanf("%d%d%d", &x[i], &y[i], &z[i]);
        }
    }
    void Sv()
    {
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= n; j ++)
            {
                int u, v, w;
                if (x[i] >= x[j]) u = 1;
                else u = 0;
                if (y[i] >= y[j]) v = 1;
                else v = 0;
                if (z[i] >= z[j]) w = 1;
                else w = 0;
                if (u + v + w > 1)
                    b[i][j] = 1;
                else b[i][j] = 0;
            }
        for (int k = 1; k <= n; k ++)
            for (int i = 1; i <= n; i ++)
                for (int j = 1; j <= n; j++)
                {
                    b[i][j] = b[i][j] || b[i][k] & b[k][j];
                }
    }
    void Out()
    {
        for (int i = 1; i <= n; i ++)
        {
            bool flag = true;
            for (int j = 1; j <= n; j ++)
                if (b[i][j] == false)
                {
                    flag = false;
                    break;
                }
            if (flag == true)
                cout << s[i] << endl;
        }
    }
    void M()
    {
        In();
        Sv();
        Out();
    }
};

int main()
{
    cl c;
    c.M();
}














