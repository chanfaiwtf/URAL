#pragma comment(linker, "/STACK:16777216")
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
    int n, top, s;
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
    UNIT a[1010];
    int ans[40010];
    queue<int> q;
public:
    void In()
    {
        cin >> n >> s;
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= n; j ++)
            {
                int tmp;
                cin >> tmp;
                if (tmp == 1) continue;
                if (i == j) continue;
                a[i].s.insert(j);
                a[j].indeg ++;
            }
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
        ans[top++] = s;
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
        vector<int> v;
        while (!q.empty())
        {
            v.push_back(q.front());
            q.pop();
        }
        for (int i = v.size()-1; i > 0; i --)
            cout << v[i] << " " << v[i-1] << endl;
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



















