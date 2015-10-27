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
    int n, p, q;
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

void CLASS::SOLVE()
{
    p = 1;
    for (int i = 2; i*i <= n; i ++)
        if (n % i == 0)
        {
            p = i;
            q = n/i;
            break;
        }
    // p < q
    //cout << p << " " << q << endl;
    
    cout << "0 1 ";
    for (int i = 1; i*q+1 <= n; i ++)
    {
        if ((i*q-1)%p == 0)
            cout << i*q << " ";
        if ((i*q+1)%p == 0)
            cout << i*q+1 << " ";
    }
    cout << endl;
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














