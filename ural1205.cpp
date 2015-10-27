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
    double A, B;
    int n;
    double a[220][2];
    double v[220][220];
    double f[220];
    int p[220];
    vector<int> w;
public:
    void M()
    {
        In();
        Sv();
        Out();
    }
    void In()
    {
        cin >> A >> B;
        cin >> n;
        for (int i = 1; i <= n; i ++)
            cin >> a[i][0] >> a[i][1];
        for (int i = 0; i <= n+1; i ++)
        {
            f[i] = 99999999;
            for (int j = 0; j <= n+1; j ++)
                v[i][j] = 99999999;
        }
        int x, y;
        cin >> x >> y;
        while (x != 0 && y != 0)
        {
            double tmp;
            tmp = sqrt((a[x][0]-a[y][0]) * (a[x][0]-a[y][0]) + (a[x][1]-a[y][1]) * (a[x][1]-a[y][1])) / B;
            v[x][y] = tmp;
            v[y][x] = tmp;
            cin >> x >> y;
        }
        cin >> a[0][0] >> a[0][1];
        cin >> a[n+1][0] >> a[n+1][1];
        for (int i = 1; i <= n; i ++)
        {
            double tmp1, tmp2;
            tmp1 = sqrt((a[0][0]-a[i][0]) * (a[0][0]-a[i][0]) + (a[0][1]-a[i][1]) * (a[0][1]-a[i][1])) / A;
            tmp2 = sqrt((a[n+1][0]-a[i][0]) * (a[n+1][0]-a[i][0]) + (a[n+1][1]-a[i][1]) * (a[n+1][1]-a[i][1])) / A;
            v[0][i] = tmp1;
            v[i][0] = tmp1;
            v[n+1][i] = tmp2;
            v[i][n+1] = tmp2;
        }
        if (v[0][n+1] == 99999999)
        {
            double tmp;
            tmp = sqrt((a[0][0]-a[n+1][0]) * (a[0][0]-a[n+1][0]) + (a[0][1]-a[n+1][1]) * (a[0][1]-a[n+1][1])) / A;
            v[0][n+1] = tmp;
            v[n+1][0] = tmp;
        }
        for (int i = 1; i <= n; i ++)
        {
            for (int j = 1; j <= n; j ++)
            {
                if (i == j) continue;
                if (v[i][j] == 99999999)
                {
                    double tmp;
                    tmp = sqrt((a[i][0]-a[j][0]) * (a[i][0]-a[j][0]) + (a[i][1]-a[j][1]) * (a[i][1]-a[j][1])) / A;
                    v[i][j] = tmp;
                    v[j][i] = tmp;
                }
            }
        }
    }
    void Sv()
    {
        queue<int> q;
        bool b[220];
        for (int i = 0; i <= n+1; i ++)
        {
            f[i] = v[0][i];
            if (f[i] < 99999999)
                p[i] = 0;
            else p[i] = -1;
            b[i] = false;
        }
        f[0] = 0;
        b[0] = true;
        int now = 0;
        double m;
        for (int i = 1; i <= n+1; i ++)
        {
            m = 99999999;
            for (int j = 0; j <= n+1; j ++)
            {
                if (!b[j] && f[j]<m)
                {
                    now = j;
                    m = f[j];
                }
            }
            b[now] = true;
            f[now] = m;
            for (int j = 0; j <= n+1; j ++)
                if (!b[j] && (f[now]+v[now][j] < f[j]))
                {
                    f[j] = f[now] + v[now][j];
                    p[j] = now;
                }
        }
    }
    void Out()
    {
        cout << setprecision(7) << fixed << f[n+1] << endl;
        int k = n+1;
        while (k != 0)
        {
            w.push_back(k);
            k = p[k];
        }
        cout << w.size()-1 << " ";
        for (int i = w.size()-1; i > 0; i --)
            cout << w[i] << " ";
        cout << endl;
    }
};

int main()
{
    cl c;
    c.M();
}



















