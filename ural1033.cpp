#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

class cl
{
private:
    int n;
    int a[40][40];
    bool b[40][40];
    int ans;
    const int d[4][2] = {{0,1},{1,0},{0, -1},{-1, 0}};
public:
    void M()
    {
        In();
        Sv(1, 1);
        Sv(n, n);
        Out();
    }
    void In()
    {
        cin >> n;
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= n; j ++)
            {
                char ch;
                cin >> ch;
                if (ch == '.')
                    a[i][j] = 1;
                else a[i][j] = 0;
            }
    }
    void Sv(int x, int y)
    {
        if (b[x][y] == 0)
        {
            //cout << x << " " << y << " ";
            if (a[x][y] == 0)
            {
                ans ++;
                //cout << "wall " << ans << endl;
            }
            else
            {
                //cout << "goon" << endl;
                b[x][y] = 1;
                for (int i = 0; i < 4; i ++)
                {
                    Sv(x+d[i][0], y+d[i][1]);
                }
            }
        }
    }
    void Out()
    {
        cout << (ans-4)*9 << endl;
    }
};

int main()
{
    cl c;
    c.M();
}



















