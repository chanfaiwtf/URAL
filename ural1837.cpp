#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int n, I;
string s[110][3];
map<string, int> st;
map<string, int>::iterator it;
int a[303][303];
int f[303];
bool b[303];
queue<int> q;

int main()
{
    cin >> n;
    I = -1;
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < 3; j ++)
        {
            cin >> s[i][j];
            it = st.find(s[i][j]);
            if (it == st.end())
            {
                st.insert(pair<string, int>(s[i][j], st.size()));
                if (s[i][j] == "Isenbaev")
                    I = st[s[i][j]];
            }
        }
    
    memset(a, 0, sizeof(a));
    for (int i = 0; i < n; i ++)
    {
        //cout << st[s[i][0]] << " " << st[s[i][1]] << " " << st[s[i][2]] << endl;
        a[st[s[i][0]]][st[s[i][1]]] = 1;
        a[st[s[i][1]]][st[s[i][2]]] = 1;
        a[st[s[i][2]]][st[s[i][0]]] = 1;
        a[st[s[i][1]]][st[s[i][0]]] = 1;
        a[st[s[i][2]]][st[s[i][1]]] = 1;
        a[st[s[i][0]]][st[s[i][2]]] = 1;
    }
    //cout << endl;
    n = st.size();
    
    //cout << n << endl;
    
    for (int i = 0; i < 303; i ++)
    {
        f[i] = 500;
        b[i] = true;
    }
    q.push(I);
    b[I] = false;
    f[I] = 0;
    while (!q.empty())
    {
        int tmp;
        tmp = q.front();
        //cout << tmp << " ";
        for (int i = 0; i < 300; i ++)
        {
            if (a[tmp][i] == 1)
            {
                //cout << i << " ";
                f[i] = min(f[i], f[tmp]+1);
                if (b[i] == true)
                {
                    q.push(i);
                    b[i] = false;
                }
            }
        }
        //cout << endl;
        q.pop();
    }
    
    it = st.begin();
    //it ++;
    for ( ; it != st.end(); it ++)
        if (f[it->second] == 500)
            cout << it->first << " undefined" << endl;
        else cout << it->first << " " << f[it->second] << endl;
}





