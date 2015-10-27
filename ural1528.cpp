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
    long long n, p;
    long long ans;
public:
    void In()
    {
        cin >> n >> p;
        while (n != 0  && p != 0)
        {
            ans = 1;
            for (int i = 2; i <= n; i ++)
            {
                ans = ans * i;
                ans = ans % p;
            }
            cout << ans << endl;
            cin >> n >> p;
        }
    }
    void Sv()
    {
    }
    void Out()
    {
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


















