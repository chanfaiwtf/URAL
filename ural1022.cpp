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
    int n;
    vector<UNIT> v;
    queue<int> q;
    vector<int> ans;
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
        cin >> n;
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
        for (int i = 1; i <= n; i ++)
        {
            int read;
            cin >> read;
            while (read != 0)
            {
                v[i].son.push_back(read);
                v[read].deg ++;
                cin >> read;
            }
        }
    }
    void Tp()
    {
        for (int i = 1; i <= n; i ++)
        {
            //cout << v[i].deg << endl;
            if (v[i].deg == 0)
            {
                q.push(i);
                v[i].boo = false;
            }
        }
        while (!q.empty())
        {
            int fr;
            fr = q.front();
            for (int i = 0; i < v[fr].son.size(); i ++)
                v[v[fr].son[i]].deg --;
            for (int i = 1; i <= n; i ++)
                if (v[i].deg == 0 && v[i].boo == true)
                {
                    q.push(i);
                    v[i].boo = false;
                }
            ans.push_back(fr);
            q.pop();
        }
    }
    void Out()
    {
        for (int i = 0; i < ans.size(); i ++)
            cout << ans[i] << " ";
        cout << endl;
    }
};

int main()
{
    tp t;
    t.M();
}



















