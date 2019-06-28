#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 100000007
ll fastPow(ll x, ll n, ll MOD)
{
    ll ret = 1;
    while (n)
    {
        if (n & 1) ret = (ret * x) % MOD;
        x = (x * x) % MOD;
        n >>= 1;
    }
    return ret % MOD;
}
unordered_map <ll, ll> lhs;
int main()
{
    ll t, cs = 0;
    cin >> t;
    while(t--) {
        ll a, y;
        scanf("%lld %lld", &a, &y);
        ll n = sqrt(mod);
          for(ll i = 1; i <= n; i++) {
            lhs[ fastPow(a, i * n, mod) ] = i;
        }
          ll k = 1e18;
        for(ll j = 0; j < n; j++) {
            ll rhs = (fastPow(a, j, mod) * y) % mod;
            if(lhs.find(rhs) != lhs.end())
                k = min(k, lhs[rhs] * n - j);
        }
          printf("Case %lld: %lld\n", ++cs, k);
        lhs.clear();
    }
      return 0;
}
 
