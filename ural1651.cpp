#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class cl
{
private:
    int n;
    struct UNIT
    {
        int id = 0;
        vector<int> v;
    };
    vector<UNIT> a;
    vector<int> d;
    vector<int> p;
    vector<int> mp;
public:
    void In()
    {
        cin >> n;
        a.resize(100002);
        d.resize(100002, 0);
        mp.resize(100002, -1);
        for (int i = 1; i <= n; i ++)
        {
            cin >> a[i].id;
            if (mp[a[i].id] != -1 && a[mp[a[i].id]].v.size() == 0)
                a[mp[a[i].id]].v.push_back(i);
            mp[a[i].id] = i;
            d[i] = i;
        }
        /*
        for (int i = 1; i <= n; i ++)
        {
            cout << i << ":" << endl << a[i].id << endl;
            for (int j = 0; j < a[i].v.size(); j ++)
                cout << a[i].v[j] << " ";
            cout << endl;
        }
        */
    }
    void Sv()
    {
        queue<int> q;
        vector<bool> b;
        b.resize(100002, true);
        p.resize(100002, -1);
        
        q.push(1);
        b[1] = false;
        while (!q.empty())
        {
            int tmp = q.front();
            q.pop();
            b[tmp] = true;
            if (d[tmp]+1 <= d[tmp+1])
            {
                d[tmp+1] = d[tmp]+1;
                p[tmp+1] = tmp;
                if (b[tmp+1] == true)
                {
                    q.push(tmp+1);
                    b[tmp+1] = false;
                }
            }
            for (int i = 0; i < a[tmp].v.size(); i ++)
            {
                if (d[tmp]+1 <= d[a[tmp].v[i]])
                {
                    d[a[tmp].v[i]] = d[tmp];
                    p[a[tmp].v[i]] = tmp;
                    if (b[a[tmp].v[i]] == true)
                    {
                        q.push(a[tmp].v[i]);
                        b[a[tmp].v[i]] = false;
                    }
                }
            }
        }
    }
    void Out()
    {
        int t = n;
        vector<int> ans;
        while (p[t] != -1)
        {
            ans.push_back(t);
            t = p[t];
        }
        ans.push_back(1);
        cout << a[1].id << " ";
        for (int i = ans.size()-2; i >= 0; i --)
        {
            if (a[ans[i]].id != a[ans[i+1]].id)
                cout << a[ans[i]].id << " ";
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




















