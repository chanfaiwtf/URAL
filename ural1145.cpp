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

const int d[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};

class cl
{
private:
    int n, m, ans, maxd;
    bool a[1000][1000];
    vector<pair<int, int> > v;
public:
    void In()
    {
        cin >> n >> m;
        memset(a, false, sizeof(a));
        for (int i = 1; i <= m; i ++)
            for (int j = 1; j <= n; j ++)
            {
                char c;
                cin >> c;
                if (c == '.')
                    a[i][j] = true;
            }
        for (int i = 1; i <= m; i ++)
            for (int j = 1; j <= n; j ++)
            {
                if (a[i][j] == false)
                    continue;
                int tmp = 0;
                for (int k = 0; k < 4; k ++)
                    tmp += a[i+d[k][0]][j+d[k][1]];
                if (tmp == 1)
                    v.push_back(make_pair(i, j));
            }
        //for (int i = 0; i < v.size(); i ++)
        //    cout << v[i].first << " " << v[i].second << endl;
    }
    void Sv()
    {
        pair<int, int> s;
        s = bfs(v[0].first, v[0].second);
        s = bfs(s.first, s.second);
    }
    pair<int, int> bfs(int x, int y)
    {
        pair<int, int> ret;
        bool b[1000][1000];
        int p[1000][1000];
        maxd = -1;
        memset(b, 0, sizeof(b));
        memset(p, 0, sizeof(p));
        queue<pair<int, int> > q;
        q.push(make_pair(x, y));
        b[x][y] = 1;
        p[x][y] = 0;
        while (!q.empty())
        {
            pair<int, int> fr = q.front();
            for (int i = 0; i < 4; i ++)
            {
                if (a[fr.first+d[i][0]][fr.second+d[i][1]] == true && b[fr.first+d[i][0]][fr.second+d[i][1]] == 0)
                {
                    q.push(make_pair(fr.first+d[i][0], fr.second+d[i][1]));
                    b[fr.first+d[i][0]][fr.second+d[i][1]] = 1;
                    p[fr.first+d[i][0]][fr.second+d[i][1]] = p[fr.first][fr.second] + 1;
                    if (p[fr.first+d[i][0]][fr.second+d[i][1]] > maxd)
                    {
                        maxd = p[fr.first+d[i][0]][fr.second+d[i][1]];
                        ret.first = fr.first+d[i][0];
                        ret.second = fr.second+d[i][1];
                    }
                }
            }
            q.pop();
        }
        return ret;
    }
    void Out()
    {
        cout << maxd << endl;
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














