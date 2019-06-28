#include <iostream>
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
#define ll long long
ll ara[100009];
bool cmp(ll a, ll b)
{
    return a > b;
}
int main()
{
    ll t, caseno = 0;
    cin >> t;
    while(t--) {
        ll k, c, n, sum = 0;
        scanf("%lld %lld %lld %lld", &k, &c, &n, &ara[0]);
                sum = ara[0];
        for(ll i = 1; i < n; i++) {
            ara[i] = (k * ara[i-1] + c) % 1000007;
                        sum += ara[i];
        }
                sort(ara, ara + n, cmp);
        ll tot = n - 1;
                ll ans = 0;
        for(ll i = 0; i < n - 1; i++) {
            //printf("%lld %lld\n", ara[i], sum);
            sum -= ara[i];
            ans += (ara[i] * tot - sum);
            tot--;
        }
                printf("Case %lld: %lld\n", ++caseno, ans);
    }
    return 0;
}
