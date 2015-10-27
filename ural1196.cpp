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
    int n, m, ans;
    set<int> s;
public:
    CLASS();
    void MAIN();
    void READ();
    void SOLVE();
    void OUTPUT();
};

CLASS::CLASS()
{
    ans = 0;
    s.clear();
}

void CLASS::READ()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i ++)
    {
        int k;
        scanf("%d", &k);
        s.insert(k);
    }
}

void CLASS::SOLVE()
{
    scanf("%d", &m);
    for (int i = 0; i < m; i ++)
    {
        int k;
        scanf("%d", &k);
        if (s.count(k) != 0)
            ans ++;
    }
    cout << ans << endl;
}

void CLASS::OUTPUT()
{
    
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



















