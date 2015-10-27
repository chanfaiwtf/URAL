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

const int maxn = 1010;

class cl
{
private:
    int x, y;
    vector<int> p, e;
public:
    void In()
    {
        p.resize(1010);
        e.resize(1010, 0);
        for (int i = 0; i <= p.size(); i ++)
            p[i] = i;
        while (cin >> x >> y)
        {
            int s, t;
            s = find(x);
            t = find(y);
            if (s != t)
            {
                e[p[y]] += e[p[x]];
                p[p[x]] = p[y];
            }
            e[p[y]] ++;
        }
    }
    int find(int x)
    {
        if (x != p[x])
            p[x] = find(p[x]);
        return p[x];
    }
    void Sv()
    {
    }
    void Out()
    {
        bool ans = true;
        for (int i = 1; i <= 1000; i ++)
        {
            //if (p[i] != i) cout << i << " " << p[i] << endl;
            if (p[i] == i && e[i] % 2 == 1)
            {
                cout << 0 << endl;
                ans = false;
                break;
            }
        }
        if (ans == true)
            cout << 1 << endl;
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



















