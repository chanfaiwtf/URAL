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
    int n = 0, top;
    struct UNIT
    {
        int indeg;
        set<int> s;
        UNIT()
        {
            indeg = 0;
            s.clear();
        }
    };
    bool flag;
    UNIT a[10010];
    int ans[10010];
    queue<int> q;
public:
    void In()
    {
        int t;
        cin >> t;
        while (t -- > 0)
        {
            int m, x, y;
            cin >> m;
            cin >> x;
            while (m -- > 0)
            {
                cin >> y;
                n = max(n, max(x, y));
                a[y].s.insert(x);
                a[x].indeg ++;
                x = y;
            }
        }
        /*
        for (int i = 1; i <= n; i ++)
        {
            cout << i << ", " << a[i].indeg << ": ";
            for (set<int>::iterator it = a[i].s.begin(); it != a[i].s.end(); it ++)
                cout << *it << " ";
            cout << endl;
        }
        */
    }
    void Sv()
    {
        flag = true;
        for (int i = 1; i <= n; i ++)
            if (a[i].s.size() != a[i].indeg)
            {
                flag = false;
                break;
            }
        if (flag == false)
            return;

        int bridge;
        top = 0;
        ans[top++] = 1;
        while (top > 0)
        {
            bridge = 1;
            if (a[ans[top-1]].s.size() != 0) bridge = 0;
            if (bridge)
            {
                //cout << ans[--top] << " ";
                q.push(ans[--top]);
            }
            else
            {
                dfs(ans[--top]);
            }
        }
    }
    void dfs(int x)
    {
        ans[top++] = x;
        for (set<int>::iterator it = a[x].s.begin(); it != a[x].s.end(); )
        {
            int tmp = *it;
            it ++;
            a[x].s.erase(tmp);
            dfs(tmp);
            break;
        }
    }
    void Out()
    {
        if (flag == false) cout << 0 << endl;
        //cout << endl;
        cout << q.size()-1 << " ";
        while (!q.empty())
        {
            cout << q.front() << " ";
            q.pop();
        }
        cout << endl;
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



















