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

const ll sz = 1e5 + 10;
ll ara[sz], pre[sz];
set <ll> lst;

int main()
{
    ll t;
    cin >> t;

    while(t--) {
        ll n, k, z;
        sl(n), sl(k), sl(z);

        for1(i, n) sl(ara[i]), pre[i] = pre[i-1] + ara[i];

        k++;
        ll ans = 0;
        for(ll i = 1; i <= n && i <= k; i++) {

            if(i == 1) {
                lst.insert(ara[i] + ara[i+1]);
                continue;
            }

            ll rest = k - i;
            if(rest & 1) {
                lst.insert(ara[i] + ara[i+1]);
                continue;
            }

            ll need = rest / 2;
            if(need > z) {
                lst.insert(ara[i] + ara[i+1]);
                continue;
            }

            ll mx = *lst.rbegin();
            ans = max(ans, need*mx + pre[i]);

            lst.insert(ara[i] + ara[i+1]);
        }
        lst.clear();

        k--;
        for(ll i = 1; i <= n && i <= k; i++) {

            if(i == 1) {
                lst.insert(ara[i] + ara[i+1]);
                continue;
            }

            ll rest = k - i;
            if(rest & 1) {
                lst.insert(ara[i] + ara[i+1]);
                continue;
            }

            ll need = rest / 2;
            if(need >= z) {
                lst.insert(ara[i] + ara[i+1]);
                continue;
            }

            ll mx = *lst.rbegin();
            ans = max(ans, need*mx + pre[i] + ara[i-1]);

            lst.insert(ara[i] + ara[i+1]);
        }
        lst.clear();

        pf("%lld\n", ans);
    }

    return 0;
}