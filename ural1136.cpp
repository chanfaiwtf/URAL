#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>

using namespace std;

struct UNIT
{
    int val, num;
    int ls, rs;
    int pr;
    bool bl;
    UNIT()
    {
        val = -1;
        num = -1;
        ls = -1;
        rs = -1;
        pr = -1;
        bl = true;
    }
};

class cl
{
private:
    int n, m;
    int root;
    UNIT u[3003];
    bool b[3003];
    vector<int> a;
    vector<int> ans;
public:
    void M()
    {
        In();
        m = 0;
        Sv(0, n-1);
        Out();
    }
    void In()
    {
        cin >> n;
        for (int i = 0; i < n; i ++)
        {
            int read;
            cin >> read;
            a.push_back(read);
            ans.push_back(0);
            u[i].val = read;
            u[i].num = i;
        }
        root = n-1;
    }
    void Sv(int x, int y)
    {
        if (x > y) return;
        ans[m++] = a[y];
        for (int i = x; i <= y-1; i ++)
            if (a[i] > a[y])
            {
                Sv(x, i-1);
                Sv(i, y-1);
                return;
            }
        Sv(x, y-1);
    }
    void Out()
    {
        for (int i = ans.size()-1; i >= 0; i --)
            cout << ans[i] << endl;
    }
};

int main()
{
    cl c;
    c.M();
}



















