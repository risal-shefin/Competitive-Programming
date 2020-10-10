#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()

{
    freopen("lazy.in", "r", stdin);
    ll t, caseno = 0;
    cin >> t;
    while(t--) {
        ll n;
        scanf("%lld", &n);
        printf("Case %lld: %lld\n", ++caseno, n - 1);
    }

    return 0;
}