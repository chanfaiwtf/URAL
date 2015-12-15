#include <iostream>
#include <algorithm>
#include <cstring>
#include <fstream>
#include <vector>
#include <cstdio>
#include <string>
#include <cmath>
#include <stack>
#include <map>
#include <set>
#define clr(a, v) memset(a, v, sizeof a)
#define maxn 30
#define maxint 999999999

using namespace std;

const long long a[56] = {0,1,1,2,4,6,9,14,21,31,46,68,100,147,216,317,465,682,1000,1466,2149,3150,4617,6767,9918,14536,21304,31223,45760,67065,98289,144050,211116,309406,453457,664574,973981,1427439,2092014,3065996,4493436,6585451,9651448,14144885,20730337,30381786,44526672,65257010,95638797,140165470,205422481,301061279,441226750,646649232,947710512,1388937263};

class CLASS
{
private:
    int n;
public:
    CLASS(int N)
    {
        n = N;
    }
    void INPUT()
    {
    }
    void SOLVE()
    {
    }
    void OUTPUT()
    {
        cout << a[n] << endl;
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
        CLASS cl(n);
        cl.MAIN();
}












