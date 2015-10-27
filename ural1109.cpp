#include <iostream>
#include <algorithm>
#include <cstring>
#include <iomanip>
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
    int m, n, k;
    bool a[1010][1010];
    bool flag[1010];
    int b[1010];
    int p = 0;
public:
    void M()
    {
        In();
        Sv();
        Out();
    }
    void In()
    {
        cin >> m >> n >> k;
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        while (k -- > 0)
        {
            int x, y;
            cin >> x >> y;
            a[x][y] = 1;
        }
    }
    void Sv()
    {
        for (int i = 1; i <= m; i ++)
        {
            memset(flag, 0, sizeof(flag));
            if (find(i) == true)
                p ++;
        }
    }
    bool find(int x)
    {
        for (int i = 1; i <= n; i ++)
        {
            //cout << x << " " << i << endl;
            if (a[x][i] == 1 && flag[i] == 0)
            {
                flag[i] = 1;
                if (b[i] == 0 || find(b[i]))
                {
                    b[i] = x;
                    return true;
                }
            }
        }
        return false;
    }
    void Out()
    {
        cout << m+n-p << endl;
    }
};

int main()
{
    cl c;
    c.M();
}



















