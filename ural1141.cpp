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
    int e, n, c;
    int p, q, m;
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
    cin >> e >> n >> c;
    for (int i = 2; i*i <= n; i ++)
        if (n%i == 0)
        {
            p = i;
            q = n/i;
            break;
        }
}

void CLASS::SOLVE()
{
    int x;
    for (int i = 0; i <= 32000; i ++)
        if ((e*i-1)%((p-1)*(q-1)) == 0)
            x = i;
    m = 1;
    for (int i = 1; i <= x; i ++)
        m = m * c % n;
    cout << m << endl;
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
    int t;
    cin >> t;
    while (t -- > 0) {
        CLASS cla;
        cla.MAIN();
    }
}














