#include <iostream>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <map>

using namespace std;

class cl
{
private:
    int n;
    set<int> s;
    int m[1000001];
    bool ans;
    string t;
public:
    void In()
    {
        cin >> n;
        s.clear();
        memset(m, 0, sizeof(m));
    }
    void Sv()
    {
        if (n == 1)
        {
            t = "1";
            ans = true;
            return;
        }
        int k = 0, fr = 0;
        queue<int> q;
        q.push(0);
        m[0] = -1;
        ans = false;
        while (!q.empty())
        {
            fr = q.front();
            //cout << fr << " ";
            int x;
            x = (fr*10+1)%n;
            if (x == 0)
            {
                k = fr;
                ans = true;
                break;
            }
            if (s.count(x) == 0)
            {
                m[x] = fr;
                q.push(x);
                s.insert(x);
            }
            
            x = (fr*10+2)%n;
            if (x == 0)
            {
                k = fr;
                ans = true;
                break;
            }
            if (s.count(x) == 0)
            {
                m[x] = fr;
                q.push(x);
                s.insert(x);
            }
            q.pop();
        }
        if (ans == false) return;
        
        //cout << fr << endl;
        t = "";
        int x = k;
        if ((x*10+1)%n == 0)
            t += "1";
        if ((x*10+2)%n == 0)
            t += "2";
        while (m[x] != -1)
        {
            int y = m[x];
            //cout << y << endl;
            if ((y*10+1) % n == x)
                t += "1";
            if ((y*10+2) % n == x)
                t += "2";
            x = y;
        }
        reverse(t.begin(), t.end());
    }
    void Out()
    {
        if (ans == false || t.size() > 30) cout << "Impossible" << endl;
        else cout << t << endl;
    }
    void M()
    {
        In();
        Sv();
        Out();
    }
};

int main()
{
    cl c;
    c.M();
    
}




















