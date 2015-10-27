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
    int n, s;
    struct UNIT
    {
        int num;
        vector<pair<int, int> > v;
        set<int> s;
        bool c;
        UNIT()
        {
            num = 0;
            v.clear();
            s.clear();
            c = true;
        }
    };
    vector<UNIT> a;
    bool ans;
    int maxlen;
public:
    void In()
    {
        int m;
        cin >> m >> n >> s;
        a.resize(m+5);
        ans = false;
        while (n -- > 0)
        {
            int p, q, r;
            cin >> p >> q >> r;
            if (a[p].s.count(q) != 0)
                ans = true;
            a[p].s.insert(q);
            a[q].s.insert(p);
            a[p].v.push_back(make_pair(q, r));
            a[q].v.push_back(make_pair(p, r));
        }
        n = m;
    }
    void Sv()
    {
        if (ans == true) return;
        
        //cout << "." << endl;
        
        bool flag = true;
        int m = 1;
        set<pair<int,int> > cir;
        while (flag == true)
        {
            queue<int> q;
            q.push(m);
            a[m].c = false;
            while (!q.empty())
            {
                int tmp = q.front();
                for (set<int>::iterator it = a[tmp].s.begin(); it != a[tmp].s.end(); it ++)
                {
                    if ((cir.count(make_pair(tmp, *it)) == 0 || cir.count(make_pair(*it, tmp)) == 0) && a[*it].c == false)
                    {
                        //cout << ".." << endl;
                        ans = true;
                        break;
                    }
                    if (a[*it].c == true)
                    {
                        q.push(*it);
                        a[*it].c = false;
                        cir.insert(make_pair(tmp, *it));
                        cir.insert(make_pair(*it, tmp));
                    }
                    
                }
                q.pop();
                if (ans == true) break;
            }
            if (ans == true) break;
            flag = false;
            for (int i = 1; i <= n; i ++)
                if (a[i].c == true)
                {
                    m = i;
                    flag = true;
                    break;
                }
        }
        if (ans == true) return;
        maxlen = -1;
        for (int i = 1; i <= n; i ++)
        {
            //cout << i << ": " << bfs(i) << endl;
            maxlen = max(maxlen, bfs(i));
        }
        if (maxlen >= s) ans = true;
    }
    
    int bfs(int x)
    {
        int ans = -1;
        vector<int> v;
        vector<bool> b;
        v.resize(n+5, -1);
        b.resize(n+5, true);
        queue<int> q;
        q.push(x);
        b[x] = false;
        v[x] = 0;
        while (!q.empty())
        {
            int tmp = q.front();
            for (int i = 0; i < a[tmp].v.size(); i ++)
            {
                if (b[a[tmp].v[i].first] == true)
                {
                    q.push(a[tmp].v[i].first);
                    b[a[tmp].v[i].first] = false;
                    v[a[tmp].v[i].first] = v[tmp] + a[tmp].v[i].second;
                    ans = max(ans, v[a[tmp].v[i].first]);
                }
            }
            q.pop();
        }
        return ans;
    }
    
    void Out()
    {
        if (ans == true) cout << "YES" << endl;
        else cout << "NO" << endl;
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



















