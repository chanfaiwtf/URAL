#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>

using namespace std;

class cl
{
private:
    int n, k;
    set<int> s;
    int a[110][110];
    bool b[110];
    int ans = 0;
public:
    void M()
    {
        In();
        Sv();
        Out();
    }
    void In()
    {
        cin >> n >> k;
        if (n == k)
        {
            cout << 0 << endl;
            exit(0);
        }
        for (int i = 0; i < k; i ++)
        {
            int t;
            cin >> t;
            s.insert(t);
        }
        for (int i = 0; i <= n; i ++)
            for (int j = 0; j <= n; j ++)
                a[i][j] = 99999999;
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= n; j ++)
            {
                //cout << i << " " << j << endl;
                int t;
                cin >> t;
                if (j >= i) continue;
                if (s.count(i) != 0 && s.count(j) != 0) continue;
                if (s.count(i) != 0 )
                {
                    if (t <= a[0][j])
                    {
                        a[0][j] = t;
                        a[j][0] = t;
                        //for (int ii = 0; ii <= n; ii ++)
                        //{
                        //    for (int jj = 0; jj <= n; jj ++)
                        //        cout << a[ii][jj] << " ";
                        //    cout << endl;
                        //}
                    }
                    continue;
                }
                if (s.count(j) != 0)
                {
                    if (t <= a[0][i])
                    {
                        a[0][i] = t;
                        a[i][0] = t;
                        //for (int ii = 0; ii <= n; ii ++)
                        //{
                        //    for (int jj = 0; jj <= n; jj ++)
                        //        cout << a[ii][jj] << " ";
                        //    cout << endl;
                        //}
                    }
                    continue;
                }
                a[i][j] = t;
                a[j][i] = t;
            }
    }
    void Sv()
    {
        for (int i = 1; i <= n; i ++)
            b[i] = true;
        b[0] = false;
        vector<int> v;
        v.push_back(0);
        while (v.size() != n-k+1)
        {
            int x = 0, y = 0;
            int m = 99999999;
            for (int i = 0; i < v.size(); i ++)
            {
                for (int j = 0; j <= n; j ++)
                {
                    if (a[v[i]][j] < m && b[j] == true)
                    {
                        x = v[i];
                        y = j;
                        m = a[v[i]][j];
                    }
                }
            }
            b[x] = false;
            b[y] = false;
            ans += m;
            v.push_back(y);
        }
    }
    void sv()
    {
    }
    void Out()
    {
        cout << ans << endl;
    }
};

int main()
{
    cl c;
    c.M();
}








































