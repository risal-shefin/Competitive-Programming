#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()

{
    ll n, m, a, b;
    cin >> n >> m >> a >> b;

    if(n % m == 0) {
        printf("0\n");
        return 0;
    }

    if(n < m) {
        ll ca = (m - n) * a;
        ll cb = n * b;
        //cout << ca << "  " << cb << endl;
        cout << min(ca, cb) << endl;
        return 0;
    }

    ll mul = n / m;
    ll rem = n - (mul * m);

    ll cb = rem * b;

    ll rema = (mul + 1) * m - n;
    ll ca = rema * a;

    cout << min(ca, cb) << endl;

    return 0;
}