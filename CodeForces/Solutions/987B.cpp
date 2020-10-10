#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long
#define inf 1e18

long long bigmod(int b, int p)

{
    if(p == 0)
        return 1;

    else if(p & 1)
        return (b * bigmod(b, p - 1));

    else {
        long long r = bigmod(b, p / 2);
        return (r * r);
    }
}

int main()

{
    ll x, y;
    cin >> x >> y;
    ll left = bigmod(x, y);
    ll right = bigmod(y, x);
    if(left > right)
        cout << ">" << endl;
    else if(right > left)
        cout << "<" << endl;
    else
        cout << "=" << endl;
    return 0;
}