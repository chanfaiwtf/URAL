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
    string s, ans;
    stack<char> q;
public:
    void In()
    {
        while (cin >> s)
        {
            for (int i = 0; i < s.size(); i ++)
            {
                if (q.empty())
                {
                    q.push(s[i]);
                    continue;
                }
                if (q.top() == s[i])
                {
                    q.pop();
                    continue;
                }
                q.push(s[i]);
            }
            while (!q.empty())
            {
                ans += q.top();
                q.pop();
            }
            for (int i = ans.size()-1; i >= 0; i --)
                cout << ans[i];
            cout << endl;
        }
    }
    void Sv()
    {
    }
    void Out()
    {
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


















