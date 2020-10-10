// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define dd double
#define ld long double
#define sl(n) scanf("%lld", &n)
#define si(n) scanf("%d", &n)
#define sd(n) scanf("%lf", &n)
#define pll pair <ll, ll>
#define pii pair <int, int>
#define mp make_pair
#define pb push_back
#define all(v) v.begin(), v.end()
#define inf (1LL << 62)
#define loop(i, start, stop, inc) for(ll i = start; i <= stop; i += inc)
#define for1(i, stop) for(ll i = 1; i <= stop; ++i)
#define for0(i, stop) for(ll i = 0; i < stop; ++i)
#define rep1(i, start) for(ll i = start; i >= 1; --i)
#define rep0(i, start) for(ll i = (start-1); i >= 0; --i)
#define ms(n, i) memset(n, i, sizeof(n))
#define casep(n) printf("Case %lld:", ++n)
#define pn printf("\n")
#define pf printf
#define EL '\n'
#define fastio std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const ll sz = 1e5 + 10, mod = 1e9 + 7;
ll ans[sz], sum[sz];

int main()
{
    ll q, k;
    cin >> q >> k;

    if(k == 1) {
        ans[0] = 1;
        for(ll i = 1; i < sz; i++)
            ans[i] = (ans[i-1] * 2) % mod;
    }
    else {
        for(ll i = 1; i < k; i++) ans[i] = 1;
        ans[k] = 2;
        for(ll i = k+1; i < sz; i++) ans[i] = (ans[i-1] + ans[i-k]) % mod;
    }

    for(ll i = 1; i < sz ; i++) sum[i] = (sum[i-1] + ans[i]) % mod;

    while(q--) {
        ll a, b;
        sl(a), sl(b);

        ll res = (sum[b] - sum[a-1]) % mod;
        if(res < 0) res += mod;

        pf("%lld\n", res);
    }

    return 0;
}