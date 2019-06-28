#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define inf 1e18
#define eps 1e-9
int main()
{
    ll x, y;
    cin >> x >> y;
    double lf = (double)x;
    double rg = (double)y;
    lf = log(x);
    rg = log(y);
    double right  = rg * x;;
    double left = lf * y;
    //cout << left << "  " << right << endl;
    if( (left - right) > eps)
        cout << ">" << endl;
    else if( (right - left) > eps)
        cout << "<" << endl;
    else
        cout << "=" << endl;
    return 0;
}
