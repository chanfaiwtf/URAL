#include <iostream>
#include <queue>

using namespace std;

class cl
{
private:
    int n, k, m;
    vector<int> a[10010];
    vector<pair<int, int> > br;
    bool b[10010] = {0};
    bool flag;
    int l, ans = 0;
public:
    void M()
    {
        In();
        bfs();
        Out();
    }
    void In()
    {
        cin >> n >> k >> m;
        for (int i = 0; i < k; i ++)
        {
            int x, y;
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        for (int i = 0; i < m; i ++)
        {
            int x, y;
            cin >> x >> y;
            br.push_back(make_pair(x, y));
        }
    }
    void bfs()
    {
        flag = true;
        l = 1;
        while (flag == true)
        {
            queue<int> q;
            q.push(l);
            b[l] = 1;
            while (!q.empty())
            {
                int tmp;
                tmp = q.front();
                for (int i = 0; i < a[tmp].size(); i ++)
                    if (b[a[tmp][i]] == 0)
                    {
                        q.push(a[tmp][i]);
                        b[a[tmp][i]] = 1;
                    }
                q.pop();
            }
            flag = false;
            for (int i = 1; i <= n; i ++)
                if (b[i] == 0)
                {
                    l = i;
                    ans ++;
                    flag = true;
                    break;
                }
        }
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