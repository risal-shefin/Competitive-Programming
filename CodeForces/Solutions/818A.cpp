#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()


{
    ll n, k;
    cin >> n >> k;
    ll tmp = n / 2;
    ll dpl = tmp / (k + 1);
    ll crt = dpl * k;
    cout << dpl << ' ' << crt << ' ' << (n - dpl - crt) << endl;

    return 0;
}