#include <iostream>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <string>
#include <vector>
#include <cstdio>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <map>

using namespace std;

class CLASS
{
private:
    int x, y;
    double ans;
    int num;
public:
    CLASS();
    void MAIN();
    void INPUT();
    void SOLVE();
    void OUTPUT();
    int trivial(int n);
};

CLASS::CLASS()
{
}

void CLASS::INPUT()
{
    cin >> x >> y;
}

void CLASS::SOLVE()
{
    ans = y;
    for (int i = y; i >= x; i --)
    {
        double k = trivial(i);
        k = k/i;
        if (k == 1.0/i)
        {
            ans = k;
            num = i;
            break;
        }
        if (ans > k)
        {
            ans = k;
            num = i;
        }
    }
}

int CLASS::trivial(int n)
{
    if (n == 1)
        return 0;
    int ret = 1;
    for (int i = 2; i*i <= n; i ++)
    {
        if (n % i == 0)
        {
            ret += i;
            if (i*i != n)
                ret += n/i;
        }
    }
    return ret;
}

void CLASS::OUTPUT()
{
    if (x == 1) cout << 1 << endl;
    else cout << num << endl;
}

void CLASS::MAIN()
{
    INPUT();
    SOLVE();
    OUTPUT();
}

int main()
{
    CLASS cla;
    cla.MAIN();
}














