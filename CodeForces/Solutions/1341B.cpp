#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

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
#define inf (1LL << 62)
#define loop(i, start, stop, inc) for(ll i = start; i <= stop; i += inc)
#define for1(i, stop) for(ll i = 1; i <= stop; i++)
#define for0(i, stop) for(ll i = 0; i < stop; i++)
#define rep1(i, start) for(ll i = start; i >= 1; i--)
#define rep0(i, start) for(ll i = (start-1); i >= 0; i--)
#define ms(n, i) memset(n, i, sizeof(n))
#define casep(n) printf("Case %lld:", ++n)
#define pn printf("\n")
#define pf printf
#define EL '\n'
#define fastio std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const ll sz = 2e5;
ll ara[sz], csum[sz];

int main()
{
    ll t;
    cin >> t;
    while(t--) {
        ll n, k;
        sl(n), sl(k);

        for1(i, n) sl(ara[i]);

        for(ll i = 2; i < n; i++) {
            if(ara[i] > ara[i-1] && ara[i] > ara[i+1])
                csum[i] = 1;
        }

        for1(i, n) csum[i] += csum[i-1];

        ll mx = 0, lft = 1;
        for1(i, n) {
            ll rgt = i + k - 1;
            if(rgt > n) break;

            ll p = csum[rgt-1] - csum[i];
            if(p+1 > mx) {
                mx = p+1;
                lft = i;
            }
        }

        pf("%lld %lld\n", mx, lft);

        for1(i, n) csum[i] = 0;
    }

    return 0;
}