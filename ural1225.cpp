#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

class CLASS
{
private:
    int n;
    long long f[50];
public:
    void INPUT()
    {
        cin >> n;
        memset(f, 0, sizeof f);
    }
    void SOLVE()
    {
        f[1] = 2;
        f[2] = 2;
        for (int i = 3; i <= n; i ++)
            f[i] = f[i-1] + f[i-2];
    }
    void OUTPUT()
    {
        cout << f[n] << endl;
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














