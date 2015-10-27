#include <iostream>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <map>

using namespace std;

class cl
{
private:
    const double v1 = 50.0/36.0;
    const double v2 = 200.0/36.0;
    int n, m;
    double ans;
    //vector<int> a, b;
    bool s[10100], t[10100];
public:
    void In()
    {
        memset(s, false, sizeof(s));
        memset(t, false, sizeof(t));
        cin >> n;
        //a.resize(n+2,999999999);
        for (int i = 1; i <= n; i ++)
        {
            int aa;
            cin >> aa;
            for (int j = 0; j < 5; j ++)
                s[j+aa] = true;
        }
        cin >> m;
        //b.resize(n+2,999999999);
        for (int i = 1; i <= m; i ++)
        {
            int bb;
            cin >> bb;
            for (int j = 0; j < 5; j ++)
                t[j+bb] = true;
        }
    }
    void Sv()
    {
        int x = 0, y = 8;
        while (true)
        {
            if (check(s, x) == true && check(t, y) == true)
            {
                ans = x/v2;
                return;
            }
            x ++; y ++;
        }
    }
    bool check(bool a[], int x)
    {
        for (int i = 0; i < 8; i ++)
            if (a[x+i] == true)
                return false;
        return true;
    }
    void Out()
    {
        cout << fixed << setprecision(6) << ans << endl;
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



















