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
    vector<int> a;
    int n, ans;
public:
    void In()
    {
        cin >> n;
        a.resize(n+2);
        for (int i = 1; i <= n; i ++)
            cin >> a[i];
    }
    void Sv()
    {
        ans = 999999999;
        dfs(0, 0, 0);
    }
    void dfs(int x, int l, int r)
    {
        if (x == n)
        {
            ans = min(ans, abs(l-r));
            return;
        }
        dfs(x+1, l+a[x+1], r);
        dfs(x+1, l, r+a[x+1]);
    }
    void Out()
    {
        cout << ans << endl;
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



















