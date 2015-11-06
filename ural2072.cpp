#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

class CLASS
{
private:
    int n;
    struct NODE
    {
        int v;
        int l, r;
        long long lf, rf;
        NODE()
        {
            v = l = r = 0;
            lf = rf = 1e15;
        }
        bool operator < (const NODE & N) const
        {
            return v < N.v;
        }
    };
    vector<NODE> v;
    map<int, int> m;
public:
    CLASS()
    {
    }
    void INPUT()
    {
        cin >> n;
        for (int i = 0; i < n; i ++)
        {
            int k;
            cin >> k;
            if (m.find(k) == m.end())
            {
                NODE tmp;
                tmp.v = k;
                tmp.l = tmp.r = i;
                v.push_back(tmp);
                m[k] = v.size()-1;
            }
            else
            {
                v[m[k]].r = i;
            }
        }
        sort(v.begin(), v.end());
    }
    void SOLVE()
    {
        v[0].lf = v[0].r + (v[0].r-v[0].l);
        v[0].rf = v[0].r;
        for (int i = 1; i < v.size(); i ++)
        {
            if (v[i].r < v[i-1].l)
            {
                v[i].lf = min(v[i].lf, v[i-1].lf + (v[i-1].l-v[i].l));
                v[i].rf = min(v[i].rf, v[i-1].lf + (v[i-1].l-v[i].l) + (v[i].r-v[i].l));
            }
            else if (v[i-1].l < v[i].l)
            {
                v[i].lf = min(v[i].lf, v[i-1].lf + (v[i].r-v[i-1].l) + (v[i].r-v[i].l));
                v[i].rf = min(v[i].rf, v[i-1].lf + (v[i].r-v[i-1].l));
            }
            else
            {
                v[i].lf = min(v[i].lf, v[i-1].lf + (v[i].r-v[i-1].l) + (v[i].r-v[i].l));
                v[i].rf = min(v[i].rf, v[i-1].lf + (v[i-1].l-v[i].l) + (v[i].r-v[i].l));
            }
            
            if (v[i].r < v[i-1].r)
            {
                v[i].lf = min(v[i].lf, v[i-1].rf + (v[i-1].r-v[i].l));
                v[i].rf = min(v[i].rf, v[i-1].rf + (v[i-1].r-v[i].l) + (v[i].r-v[i].l));
            }
            else if (v[i-1].r < v[i].l)
            {
                v[i].lf = min(v[i].lf, v[i-1].rf + (v[i].r-v[i-1].r) + (v[i].r-v[i].l));
                v[i].rf = min(v[i].rf, v[i-1].rf + (v[i].r-v[i-1].r));
            }
            else
            {
                v[i].lf = min(v[i].lf, v[i-1].rf + (v[i].r-v[i-1].r) + (v[i].r-v[i].l));
                v[i].rf = min(v[i].rf, v[i-1].rf + (v[i-1].r-v[i].l) + (v[i].r-v[i].l));
            }
        }
    }
    void OUTPUT()
    {
        //for (int i = 0; i < v.size(); i ++) cout << v[i].v << " " << v[i].l << " " << v[i].r << " " << v[i].lf << " " << v[i].rf << endl;
        
        cout << min(v[v.size()-1].lf, v[v.size()-1].rf)+n << endl;
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














