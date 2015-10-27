#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <set>

using namespace std;

class cl
{
private:
    int n;
    int D, A;
    long long dd, aa, ans;
    int a[110][110];
    int f[110][110];
    vector<int> v;
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
        cin >> n;
        cin >> D >> A;
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < n; j ++)
            {
                char c;
                cin >> c;
                a[i][j] = c-'0';
            }
    }
    void Sv()
    {
        bool e[110][110], flag = true, b[110];
        int m = 0;
        for (int i = 0; i < n; i ++)
        {
            b[i] = true;
            for (int j = 0; j < n; j ++)
            {
                f[i][j] = 0;
                e[i][j] = true;
            }
        }
        while (flag == true)
        {
            queue<int> q;
            q.push(m);
            b[m] = false;
            while (!q.empty())
            {
                int tmp;
                tmp = q.front();
                for (int i = 0; i < n; i ++)
                {
                    if (i == tmp) continue;
                    if (a[tmp][i] == 1)
                    {
                        if (b[i] == false && e[i][tmp] == true)
                        {
                            dd ++;
                            a[tmp][i] = 0;
                            a[i][tmp] = 0;
                            f[tmp][i] = 1;
                            f[i][tmp] = 1;
                        }
                        if (b[i] == true)
                        {
                            q.push(i);
                            b[i] = false;
                        }
                        e[i][tmp] = false;
                        e[tmp][i] = false;
                    }
                }
                q.pop();
            }
            flag = false;
            for (int i = 0; i < n; i ++)
                if (b[i] == true)
                {
                    flag = true;
                    m = i;
                    break;
                }
        }
    }
    void sv()
    {
        bool b[110], flag = true;
        for (int i = 0; i < n; i ++)
            b[i] = true;
        int m = 0;
        while (flag == true)
        {
            queue<int> q;
            q.push(m);
            b[m] = false;
            v.push_back(m);
            while (!q.empty())
            {
                int tmp;
                tmp = q.front();
                for (int i = 0; i < n; i ++)
                {
                    if (tmp == i) continue;
                    if (a[tmp][i] == 1)
                        if (b[i] == true)
                        {
                            q.push(i);
                            b[i] = false;
                        }
                }
                q.pop();
            }
            flag = false;
            for (int i = 0; i < n; i ++)
                if (b[i] == true)
                {
                    flag = true;
                    m = i;
                    aa ++;
                    break;
                }
        }
        if (aa != 0)
            for (int i = 1; i < v.size(); i ++)
            {
                f[v[0]][v[i]] = 2;
                f[v[i]][v[0]] = 2;
            }
    }
    void Out()
    {
        //cout << dd << endl;
        //cout << aa << endl;
        ans = dd * D + aa * A;
        cout << ans << endl;
        for (int i = 0; i < n; i ++)
        {
            for (int j = 0; j < n; j ++)
            {
                if (f[i][j] == 1) cout << "d";
                else if (f[i][j] == 2) cout << "a";
                else cout << f[i][j];
            }
            cout << endl;
        }
    }
};

int main()
{
    cl c;
    c.M();
}



















