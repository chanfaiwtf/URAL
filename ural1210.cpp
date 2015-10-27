#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <set>

using namespace std;

struct UNIX
{
    pair<int, int> x, y;
    int v;
};

class cl
{
private:
    int n;
    int a[33][33];
    vector<UNIX> v;
    int f[33][33];
    int ans;
public:
    void M()
    {
        In();
        Sv();
        sv();
        Out();
    }
    void In()
    {
        for (int i = 0; i < 33; i ++)
            for (int j = 0; j < 33; j ++)
                f[i][j] = 99999999;
        f[0][1] = 0;
        cin >> n;
        for (int i = 1; i <= n; i ++)
        {
            int m;
            cin >> m;
            for (int j = 1; j <= m; j ++)
            {
                int xin, yin;
                cin >> xin;
                while (xin != 0)
                {
                    cin >> yin;
                    UNIX u;
                    u.x = make_pair(i-1, xin);
                    u.y = make_pair(i, j);
                    u.v = yin;
                    v.push_back(u);
                    
                    f[i][j] = min(f[i][j], f[i-1][xin] + yin);
                    
                    cin >> xin;
                }
            }
            char ch;
            if (i != n) cin >> ch;
        }
    }
    void Sv()
    {
        ans = 99999999;
        for (int i = 1; i < 33; i ++)
        {
            ans = min(ans, f[n][i]);
        }
    }
    void sv()
    {
    }
    void Out()
    {
        //for (int i = 0; i < v.size(); i ++)
        //{
        //    cout << "(" << v[i].x.first << "," << v[i].x.second << ")" << endl;
        //    cout << "(" << v[i].y.first << "," << v[i].y.second << ")" << endl;
        //    cout << v[i].v << endl;
        //}
        //cout << endl;
        
        cout << ans << endl;
    }
};

int main()
{
    cl c;
    c.M();
}




















