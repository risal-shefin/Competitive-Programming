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
#define fastio std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const ll sz = 2e5 + 10, mod = 998244353;

#define x first
#define y second

pll extendedEuclid(ll a, ll b)   // returns x, y for ax + by = gcd(a,b)
{
    if(b == 0) return pll(1, 0);
    else
    {
        pll d = extendedEuclid(b, a % b);
        return pll(d.y, d.x - d.y * (a / b));
    }
}

ll modularInverse(ll a, ll n)
{
    pll ret = extendedEuclid(a, n);
    return ((ret.x % n) + n) % n;
}

ll fact[sz];

inline ll nCr(ll n, ll r)
{
    return (fact[n] * modularInverse( (fact[r] * fact[n-r]) % mod, mod) ) % mod;
}

// rCr + (r+1)Cr + ....+ nCr
inline ll hockeyStick(ll n, ll r)
{
    return nCr(n+1, r+1);
}

int main()
{
    fact[0] = 1;
    for1(i, sz) fact[i] = (fact[i-1] * i) % mod;

    ll n, m;
    cin >> n >> m;

    ll way = hockeyStick(m-1, n-2) % mod, ans = 0;
    for(ll i = 2; i < n; i++) {
        ll have = n-2, lft = i-1;

        ll leftComb = nCr(have, lft);
        ll fixComb = lft;

        ll tot = (fixComb * leftComb) % mod;

        ans = (ans + (tot * way) % mod) % mod;
    }

    cout << ans << endl;

    return 0;
}