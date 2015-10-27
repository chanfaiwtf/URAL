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
    vector<int> a, ans;
public:
    void In()
    {
        a.resize(10, 0);
        for (int i = 1; i <= 7; i ++)
            cin >> a[i];
    }
    void Sv()
    {
        if (check(a) == true)
        {
            ans = a;
            return;
        }
        for (int i = 1; i <= 7; i ++)
        {
            ans = a;
            if (ans[i] == 0) ans[i] = 1;
            else ans[i] = 0;
            if (check(ans) == true)
            {
                return;
            }
        }
        ans = a;
    }
    bool check(vector<int> a)
    {
        if ((a[1]+a[2]+a[4]+a[7])%2 != 0)
            return false;
        if ((a[1]+a[3]+a[4]+a[6])%2 != 0)
            return false;
        if ((a[2]+a[3]+a[4]+a[5])%2 != 0)
            return false;
        return true;
    }
    void Out()
    {
        for (int i = 1; i <= 7; i ++)
            cout << ans[i] << " ";
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



















