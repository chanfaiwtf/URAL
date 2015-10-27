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
    int n, m, ans;
    int a[1010], f[1010];
public:
    void In()
    {
        cin >> n;
        memset(a, 0, sizeof(a));
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= n; i ++)
        {
            cin >> a[i];
            if (i != 1 && i != 2)
            {
                f[i-1] = a[i-2] + a[i-1] + a[i];
            }
        }
    }
    void Sv()
    {
        m = -1;
        ans = 0;
        for (int i = 2; i <= n-1; i ++)
        {
            if (f[i] > m)
            {
                m = f[i];
                ans = i;
            }
        }
    }
    void Out()
    {
        cout << m << " " << ans << endl;
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


















