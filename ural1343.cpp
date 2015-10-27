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
    int n;
    long long d;
public:
    CLASS();
    void MAIN();
    void INPUT();
    void SOLVE();
    void OUTPUT();
};

CLASS::CLASS()
{
}

void CLASS::INPUT()
{
    cin >> n;
}

bool check(long long n)
{
    for (long long i = 2; i*i <= n; i ++)
        if (n % i == 0)
            return false;
    return true;
}

void CLASS::SOLVE()
{
    if (n == 0)
    {
        cout << "000000000002" << endl;
        return;
    }
    cin >> d;
    for (int i = n; i < 12; i ++)
        d = d * 10;
    if (d < 2)
    {
        cout << "000000000002" << endl;
        return;
    }
    
    if (check(d) == true)
    {
        cout << d << endl;
        return;
    }
    for (int i = 1; i <= 1000; i ++)
    {
        long long e = d+i;
        if (check(e) == true)
        {
            cout << e << endl;
            break;
        }
    }
}

void CLASS::OUTPUT()
{
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














