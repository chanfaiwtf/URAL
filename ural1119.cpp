#include <iostream>
#include <iomanip>
#include <cstring>
#include <set>

using namespace std;

const double gh2 = 141.42135623731;

set<pair<int, int> > s;
int n, m;
int k;
double a[1010][1010];

int main()
{
    cin >> n >> m;
    cin >> k;
    pair<int, int> tmp;
    while (k -- > 0)
    {
        int i, j;
        cin >> i >> j;
        tmp.first = i;
        tmp.second = j;
        s.insert(tmp);
    }
    
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= n; i ++)
        a[i][0] = a[i-1][0] + 100;
    for (int i = 1; i <= m; i ++)
        a[0][i] = a[0][i-1] + 100;
    
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= m; j ++)
        {
            a[i][j] = min(a[i][j-1], a[i-1][j]) + 100;
            tmp.first = i;
            tmp.second = j;
            if (s.count(tmp) != 0)
                a[i][j] = min(a[i][j], a[i-1][j-1]+gh2);
        }
    }
    
    cout << setprecision(0) << fixed << a[n][m] << endl;
}




















