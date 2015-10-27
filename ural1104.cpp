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

int a[1000010];
char s[1000010];

class CLASS
{
private:
    bool flag;
    int maxc, len, ans;
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
    maxc = 0;
    scanf("%s", s);
    len = strlen(s);
    for (int i = 0; i < len; i ++)
    {
        if ('0' <= s[i] && s[i] <='9')
            a[i] = s[i] - '0';
        else a[i] = s[i] - 'A' + 10;
        if (a[i] > maxc) maxc = a[i];
    }
    maxc ++;
    if (maxc == 1) maxc ++;
}

void CLASS::SOLVE()
{
    flag = false;
    int r = 0;
    for (int i = maxc; i <= 36; i ++)
    {
        r = 0;
        for (int j = 0; j < len; j ++)
        {
            r = r*i + a[j];
            r = r % (i-1);
        }
        if (r == 0)
        {
            ans = i;
            flag = true;
            break;
        }
    }
    if (flag == true)
        cout << ans << endl;
    else cout << "No solution." << endl;
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














