#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct UNIT
{
    int num;
    int deg;
    bool boo;
    vector<int> son;
};

class tp
{
private:
    int n, m;
    vector<UNIT> v;
    queue<int> q;
    bool ans;
public:
    void M()
    {
        Initial();
        In();
        Tp();
        Out();
    }
    void Initial()
    {
        cin >> n >> m;
        UNIT tmp;
        for (int i = 0; i <= n; i ++)
        {
            tmp.num = i;
            tmp.deg = 0;
            tmp.boo = true;
            tmp.son.clear();
            v.push_back(tmp);
        }
    }
    void In()
    {
        for (int i = 1; i <= m; i ++)
        {
            int x, y;
            cin >> x >> y;
            v[x].son.push_back(y);
            v[y].deg ++;
        }
    }
    void Tp()
    {
        ans = true;
        for (int i = 1; i <= n; i ++)
        {
            int fr;
            cin >> fr;
            if (v[fr].deg != 0)
            {
                ans = false;
                break;
            }
            for (int i = 0; i < v[fr].son.size(); i ++)
                v[v[fr].son[i]].deg --;
        }
    }
    void Out()
    {
        if (ans == true) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
};

int main()
{
    tp t;
    t.M();
}



















