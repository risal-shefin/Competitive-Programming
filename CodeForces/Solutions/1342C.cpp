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

ll calc(ll a, ll b, ll r)
{
    ll cyc = max(a, b);
    ll lcm = (a*b) / __gcd(a,b);

    ll ase = r / lcm + 1;
    ll ret = ase * cyc;

    ll bad = 0;
    ll dv = r / lcm;
    ll start = dv * lcm;
    ll baki = (r - start + 1);
    ll pos = min(baki, cyc);
    bad = cyc - pos;

    return ret - bad;
}

int main()
{
    //cout << calc(4, 6, 36) << endl;
    ll t;
    cin >> t;
    while(t--) {
        ll a, b, q;
        sl(a), sl(b), sl(q);

        bool f = 0;
        while(q--) {
            ll l, r;
            sl(l), sl(r);

            ll rgt = calc(a, b, r);
            ll lft = calc(a, b, l-1);

            ll ans = (r - l + 1) - (rgt - lft);

            if(f) pf(" ");
            pf("%lld", ans);
            f = 1;
        }
        pn;
    }

    return 0;
}