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
    int n, m;
    struct UNIT
    {
        int gr;
        int num;
        set<int> s;
        bool b;
        UNIT()
        {
            gr = 0;
            num = 0;
            s.clear();
            b = true;
        }
    };
    UNIT a[550];
    int e = 0, ans = 0;
    int v[550];
public:
    void In()
    {
        cin >> m >> n;
        for (int i = 1; i <= m; i ++)
            for (int j = 0; j < n; j ++)
            {
                int k;
                cin >> k;
                if (k != i)
                {
                    a[i].s.insert(k);
                    e ++;
                    //cout << k << endl;
                }
            }
    }
    void Sv()
    {
        queue<int> q;
        int k = 1;
        bool flag = true;
        while (flag == true)
        {
            q.push(k);
            a[k].gr = k;
            a[k].b = false;
            while (!q.empty())
            {
                int tmp = q.front();
                //cout << tmp << endl;
                for (set<int>::iterator it = a[tmp].s.begin(); it != a[tmp].s.end(); it ++)
                {
                    if (a[*it].b == true)
                    {
                        //cout << *it << " ";
                        q.push(*it);
                        a[*it].gr = a[k].gr;
                        a[*it].b = false;
                    }
                }
                //cout << endl;
                q.pop();
            }
            flag = false;
            for (int i = 1; i <= m; i ++)
                if (a[i].b == true)
                {
                    flag = true;
                    k = i;
                    break;
                }
        }
        
        for (int i = 1; i <= m; i ++)
            v[i] = 0;
        for (int i = 1; i <= m; i ++)
            v[a[i].gr] ++;
        ans = e-1;
        for (int i = 1; i <= m; i ++)
            if (v[i] != 1 && v[i] != 0)
                ans ++;
        if (ans < 0) ans = 0;
    }
    void Out()
    {
        cout << ans << endl;
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



















