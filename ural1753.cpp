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

class CLASS
{
private:
    double h, H, L, x;
    double sina, cosa, tana;
public:
    CLASS();
    void MAIN();
    void READ();
    void SOLVE();
    void OUTPUT();
};

CLASS::CLASS()
{
}

void CLASS::READ()
{
    cin >> h >> H >> L;
    H = H / 2;
}

void CLASS::SOLVE()
{
    if (H < h)
    {
        x = 0;
        return;
    }
    cosa = pow(h/H, 1.0/3);
    sina = sqrt(1.0-cosa*cosa);
    tana = sina/cosa;
    x = H*sina-h*tana;
}

void CLASS::OUTPUT()
{
    cout << fixed << setprecision(5) << x << endl;
}

void CLASS::MAIN()
{
    READ();
    SOLVE();
    OUTPUT();
}

int main()
{
    CLASS cla;
    cla.MAIN();
}



















