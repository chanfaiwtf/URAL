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
    int a, b, n;
    int p1, p2, p3, p4;
    long long ans;
public:
    void In()
    {
        cin >> a >> b >> n;
    }
    void Sv()
    {
        ans = 0;
        for (int i = 0; i < n; i = i+a)
        {
            p1 = i/b;
            bool flag = true;
            for (int j = i+1; j < i+a; j ++)
            {
                if (j >= n) break;
                p2 = j/b;
                if (p1 == p2) continue;
                if (flag == true)
                {
                    p3 = p2;
                    p4 = j-i;
                    flag = false;
                }
                if (p2 != p3)
                {
                    p3 = p2;
                    p4 = j-i;
                }
                ans += p4;
            }
        }
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



















