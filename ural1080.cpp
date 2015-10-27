#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

class cl
{
private:
    int n, m;
    struct UNIT
    {
        int num;
        vector<int> v;
        bool flag;
        int color;
        UNIT()
        {
            num = 0;
            v.clear();
            flag = true;
            color = -1;
        }
    };
    UNIT a[110];
    bool ans;
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
        {
            int read;
            cin >> read;
            while (read != 0)
            {
                a[i].v.push_back(read);
                a[read].v.push_back(i);
                cin >> read;
            }
        }
    }
    void Sv()
    {
        queue<int> q;
        m = 1;
        bool b = true;
        ans = true;
        while (b == true)
        {
            q.push(m);
            a[m].flag = false;
            a[m].color = 0;
            while (!q.empty())
            {
                int tmp;
                tmp = q.front();
                for (int i = 0; i < a[tmp].v.size(); i ++)
                {
                    if (a[a[tmp].v[i]].flag == true)
                    {
                        a[a[tmp].v[i]].color = a[tmp].color + 1;
                        q.push(a[tmp].v[i]);
                        a[a[tmp].v[i]].flag = false;
                    }
                    else
                    {
                        if (a[a[tmp].v[i]].color%2 == a[tmp].color%2)
                            ans = false;
                    }
                    if (ans == false) break;
                }
                if (ans == false) break;
                q.pop();
            }
            if (ans == false) break;
            b = false;
            for (int i = 1; i <= n; i ++)
                if (a[i].flag == true)
                {
                    m = i;
                    b = true;
                    break;
                }
        }
    }
    void Out()
    {
        if (ans == false) cout << -1;
        else
        for (int i = 1; i <= n; i ++)
            if (a[i].color % 2 == 0)
                cout << 0;
            else cout << 1;
        cout << endl;
    }
};

int main()
{
    cl c;
    c.M();
}



















