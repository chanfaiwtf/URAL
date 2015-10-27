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
    vector<long long> v;
public:
    CLASS();
    void MAIN();
    void READ();
    void SOLVE();
    void OUTPUT();
    bool check(long long n);
};

CLASS::CLASS()
{
    v.clear();
}

void CLASS::READ()
{
}

void CLASS::SOLVE()
{
    v.push_back(2);
    long long k = 3;
    while (v.size() < 15000)
    {
        if (check(k) == true)
            v.push_back(k);
        k += 2;
    }
}

bool CLASS::check(long long n)
{
    for (int i = 0; i < v.size() && v[i] <= sqrt(n); i ++)
    {
        if (n % v[i] == 0)
            return false;
    }
    return true;
}

void CLASS::OUTPUT()
{
    //cout << v.size() << endl;
    cin >> n;
    for (int i = 0; i < n; i ++)
    {
        int k;
        cin >> k;
        cout << v[k-1] << endl;
    }
}

void CLASS::MAIN()
{
    READ();
    SOLVE();
    OUTPUT();
}

int main()
{
    CLASS cla;
    cla.MAIN();
}



















