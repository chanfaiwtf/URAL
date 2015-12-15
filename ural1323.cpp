#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <string>
#include <cmath>
#include <map>
#include <set>
#define maxn 15
#define maxint 999999999

using namespace std;

class CLASS
{
private:
    int n, m, ans;
    string s[maxn], t;
    map<string, int> mp;
    bool a[maxn][maxn], b[maxn], if_ans;
    struct NODE
    {
        int fm, stp;
        NODE()
        {
            fm = stp = 0;
        }
    };
    NODE tmp[maxn], r[maxn];
    vector<int> q[maxn];
public:
    CLASS()
    {
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);
        ans = maxint;
    }
    void INPUT()
    {
        cin >> n >> m;
        int count = 0;
        while (m -- > 0)
        {
            string s1, s2;
            cin >> s1 >> s2;
            if (mp.find(s1) == mp.end())
            {
                s[count] = s1;
                mp[s1] = count ++;
            }
            if (mp.find(s2) == mp.end())
            {
                s[count] = s2;
                mp[s2] = count ++;
            }
            a[mp[s1]][mp[s2]] = a[mp[s2]][mp[s1]] = 1;
        }
    }
    void SOLVE()
    {
        if_ans = true;
        if (n == 1)
        {
            cout << 0 << endl;
            if_ans = false;
            return;
        }
        cin >> t;
        
        tmp[mp[t]].fm = -1;
        tmp[mp[t]].stp = 0;
        b[mp[t]] = true;
        q[0].push_back(mp[t]);
        dfs(0, 0, 1, 0);
    }
    void dfs(int i, int j, int num, int step)
    {
        if (num == n)
        {
            if (step < ans)
            {
                ans = step;
                for (int i = 0; i < n; i ++)
                {
                    r[i].fm = tmp[i].fm;
                    r[i].stp = tmp[i].stp;
                }
            }
            return;
        }
        int k = q[i][j];
        bool flag = 0;
        for (int kk = 0; kk < n; kk ++)
        {
            if (b[kk] == false && a[k][kk] == true)
            {
                flag = b[kk] = true;
                q[i+1].push_back(k);
                q[i+1].push_back(kk);
                tmp[kk].fm = k;
                tmp[kk].stp = i+1;
                if (j == q[i].size()-1)
                    dfs(i+1, 0, num+1, tmp[kk].stp);
                else
                    dfs(i, j+1, num+1, tmp[kk].stp);
                q[i+1].erase(q[i+1].end()-1);
                q[i+1].erase(q[i+1].end()-1);
                b[kk] = false;
            }
        }
        if (flag == false)
        {
            if (j == q[i].size()-1)
                dfs(i+1, 0, num, step);
            else
                dfs(i, j+1, num, step);
        }
    }
    void OUTPUT()
    {
        if (if_ans == false)
            return;
        cout << ans << endl;
        for (int i = 1; i <= ans; i ++)
        {
            int count = 0;
            for (int j = 0; j < n; j ++)
                if (r[j].stp == i)
                    count ++;
            cout << count << endl;
            for (int j = 0; j < n; j ++)
                if (r[j].stp == i)
                    cout << s[r[j].fm] << " " << s[j] << endl;
        }
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
        CLASS cl;
        cl.MAIN();
}












