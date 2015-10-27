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
    int n, ans = 0;
    bool a[20][20];
    const int d[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    int x, y;
    string s;
public:
    void M()
    {
        In();
        Out();
    }
    void In()
    {
        memset(a, 0, sizeof(a));
        getline(cin, s);
        if (s.find(" ") == std::string::npos)
        {
            n = tonum(s);
            for (int i = 0; i < n; i ++)
            {
                int xx, yy;
                cin >> xx >> yy;
                a[xx][yy] = 1;
                if (i == 0)
                {
                    x = xx;
                    y = yy;
                }
            }
            Sv1();
        }
        else Sv2();
    }
    void Sv2()
    {
        x = inum(s).first;
        y = inum(s).second;
        queue<pair<int, int> > q;
        q.push(make_pair(x, y));
        while (true)
        {
            x = q.front().first;
            y = q.front().second;
            a[x][y] = 1;
            ans ++;
            cin >> s;
            if (s == ".") break;
            for (int i = 0; i < s.size(); i ++)
            {
                if (s[i] == ',') break;
                else if (s[i] == 'R')
                    q.push(make_pair(x+1, y));
                else if (s[i] == 'T')
                    q.push(make_pair(x, y+1));
                else if (s[i] == 'L')
                    q.push(make_pair(x-1, y));
                else if (s[i] == 'B')
                    q.push(make_pair(x, y-1));
            }
            q.pop();
        }
        cout << ans << endl;
        for (int i = 0; i <= 10; i ++)
            for (int j = 0; j <= 10; j ++)
                if (a[i][j] == 1)
                    cout << i << " " << j << endl;
    }
    pair<int, int> inum(string s)
    {
        pair<int, int> ans;
        int x = 0, y = 0;
        int i = 0, j = 0;
        for (i = 0; i <= s.size(); i ++)
        {
            if (s[i] == ' ')
            {
                j = i;
                break;
            }
            x = x * 10 + s[i] - '0';
        }
        for (i = j+1; i < s.size(); i ++)
            y = y * 10 + s[i] - '0';
        ans.first = x;
        ans.second = y;
        return ans;
    }
    int tonum(string s)
    {
        int ans = 0;
        for (int i = 0; i < s.size(); i ++)
            ans = ans * 10 + s[i] - '0';
        return ans;
    }
    void Sv1()
    {
        cout << x << " " << y << endl;
        int m = 0;
        bool b[20][20];
        memset(b, 0, sizeof(b));
        queue<pair<int, int> > q;
        q.push(make_pair(x, y));
        b[x][y] = 1;
        while (!q.empty())
        {
            pair<int, int> tmp;
            tmp = q.front();
            int u, v;
            u = tmp.first;
            v = tmp.second;
            for (int i = 0; i < 4; i ++)
            {
                if (a[u+d[i][0]][v+d[i][1]] == 1 && b[u+d[i][0]][v+d[i][1]] == 0)
                {
                    //cout << u+d[i][0] << "." << v+d[i][1] << endl;
                    q.push(make_pair(u+d[i][0], v+d[i][1]));
                    b[u+d[i][0]][v+d[i][1]] = 1;
                    m ++;
                    if (i == 0) cout << "R";
                    else if (i == 1) cout << "T";
                    else if (i == 2) cout << "L";
                    else if (i == 3) cout << "B";
                }
            }
            if (q.size() == 1) cout << "." << endl;
            else cout << "," << endl;
            q.pop();
        }
    }
    void Out()
    {
    }
};

int main()
{
    cl c;
    c.M();
}



















