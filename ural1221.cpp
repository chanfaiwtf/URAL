#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <string>
#include <cmath>
#include <map>
#define MaxN 30 //3500
#define MaxM 3000 // 13000

using namespace std;

class CLASS
{
private:
    int n, ans;
    int a[110][110];
    vector<pair<int, int> > v;
public:
    CLASS(int N)
    {
        n = N;
        memset(a, 0, sizeof a);
        v.clear();
        ans = 0;
    }
    void INPUT()
    {
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < n; j ++)
            {
                cin >> a[i][j];
                if (a[i][j] == 1) continue;
                if (a[i][j] == 0 && (i == 0 || i == n-1 || j == 0 || j == n-1)) continue;
                v.push_back(make_pair(i, j));
            }
    }
    int cal(int x, int y)
    {
        int ans = 0;
        bool flag = true;
        
        for (int r = 1; ; r ++)
        {
            if (x-r<0 || x+r>=n || y-r<0 || y+r>=n) break;
            for (int i = 0; i <= r; i ++)
            {
                for (int j = y-r; j < y-(r-i); j ++)
                    if (a[x+i][j]!=1 || a[x-i][j]!=1)
                    {
                        flag = false;
                        break;
                    }
                if (flag == false) break;
                for (int j = y-(r-i); j <= y+(r-i); j ++)
                    if (a[x+i][j]!=0 || a[x-i][j]!=0)
                    {
                        flag = false;
                        break;
                    }
                if (flag == false) break;
                for (int j = y+(r-i)+1; j <= y+r; j ++)
                    if (a[x+i][j]!=1 || a[x-i][j]!=1)
                    {
                        flag = false;
                        break;
                    }
                if (flag == false) break;
            }
            if (flag == true)
                ans = r;
            flag = true;
        }
        
        return ans;
    }
    void SOLVE()
    {
        for (int i = 0; i < v.size(); i ++)
        {
            int tmp = cal(v[i].first, v[i].second);
            //cerr << v[i].first << "." << v[i].second << "." << tmp << endl;
            ans = max(ans, tmp);
        }
    }
    void OUTPUT()
    {
        if (ans == 0)
            cout << "No solution" << endl;
        else cout << ans*2+1 << endl;
    }
    void MAIN()
    {
        INPUT();
        SOLVE();
        OUTPUT();
    }
};

int main()
{
    int n;
    cin >> n;
    while (n != 0)
    {
        CLASS cl(n);
        cl.MAIN();
        cin >> n;
    }
}














