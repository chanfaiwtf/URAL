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
    struct UNIT
    {
        set<int> p;
        set<int> s;
        int num;
        int rt;
        bool b1, b2;
        UNIT()
        {
            p.clear();
            s.clear();
            num = 0;
            rt = 0;
            b1 = true;
            b2 = true;
        }
    };
    int n;
    UNIT a[1010];
    set<int> f[1010];
public:
    void M()
    {
        In();
        Sv();
        Out();
    }
    void In()
    {
        cin >> n;
        for (int i = 1; i <= n; i ++)
            a[i].num = i;
        while (true)
        {
            string s, t;
            cin >> s;
            if (s == "BLOOD") break;
            cin >> t;
            int x, y;
            x = tonum(s);
            y = tonum(t);
            a[x].p.insert(y);
            a[y].s.insert(x);
        }
    }
    int tonum(string s)
    {
        int ans = 0;
        for (int i = 0; i < s.size(); i ++)
            ans = ans * 10 + s[i] - '0';
        return ans;
    }
    void Sv()
    {
        int m;
        while (cin >> m)
        {
            CHAN1(m);
            CHAN2(m);
        }
    }
    void CHAN1(int x)
    {
        a[x].b1 = false;
        if (a[x].p.size() != 0)
            for (set<int>::iterator it = a[x].p.begin(); it != a[x].p.end(); it ++)
                if (a[*it].b1 == true)
                    CHAN1(*it);
    }
    void CHAN2(int x)
    {
        a[x].b2 = false;
        if (a[x].s.size() != 0)
            for (set<int>::iterator it = a[x].s.begin(); it != a[x].s.end(); it ++)
                if (a[*it].b2 == true)
                    CHAN2(*it);
    }
    void Out()
    {
        bool b = true;
        for (int i = 1; i <= n; i ++)
            if (a[i].b1 == true && a[i].b2 == true)
            {
                b = false;
                cout << i << " ";
            }
        if (b == true) cout << 0;
        cout << endl;
    }
};

int main()
{
    cl c;
    c.M();
}



















