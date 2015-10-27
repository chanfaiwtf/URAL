#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct UNIT
{
    int num;
    int level;
    vector<int> v;
    UNIT()
    {
        num = 0;
        level = -1;
        v.clear();
    }
};

int n, m;
UNIT a[101];
queue<int> q;
bool b[101];
bool flag;
bool ans;
vector<int> s;

int main()
{
    cin >> n;
    ans = true;
    for (int i = 1; i <= n; i ++)
    {
        a[i].num = i;
        int read;
        cin >> read;
        if (read == 0)
            ans = false;
        while (read != 0)
        {
            a[i].v.push_back(read);
            cin >> read;
        }
    }
    
    for (int i = 1; i <= n; i ++)
        b[i] = true;

    m = 1;
    flag = false;
    
    while (flag == false && ans == true)
    {
        //cout << m << " ";
        b[m] = false;
        a[m].level = 0;
        q.push(m);
        while (!q.empty())
        {
            int tmp;
            tmp = q.front();
            for (int i = 0; i < a[tmp].v.size(); i ++)
            {
                int j;
                j = a[tmp].v[i];
                if (b[j] == true)
                {
                    //cout << j << " ";
                    a[j].level = a[tmp].level + 1;
                    q.push(j);
                    b[j] = false;
                }
            }
            q.pop();
        }
        //cout << endl << "." << endl;
        flag = true;
        for (int i = 1; i <= n; i ++)
            if (a[i].level == -1)
            {
                m = i;
                flag = false;
                break;
            }
    }
    
    if (ans == false)
        cout << "0" << endl;
    else
    {
        s.clear();
        for (int i = 1; i <= n; i ++)
            if (a[i].level % 2 == 0)
                s.push_back(i);
    
        cout << s.size() << endl;
        for (int i = 0; i < s.size(); i ++)
            cout << s[i] << " ";
        cout << endl;
    }
}