// Number of paths between (u/g, v/g)
// through 1 where g = gcd(u, v)

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

const ll mod = 998244353;
vector <pll> prime;
vector <ll> dv;
unordered_map <ll, ll> pos;
ll way[200009];

void primeFactor(ll n2)
{
    for(ll i = 2; i * i <= n2; i++) {
        if(n2 % i == 0) {
            ll cnt = 0;
            while(n2 % i == 0)
                n2 /= i, cnt++;

            prime.pb(mp(i, cnt));
        }
    }
    if(n2 > 1) prime.pb(mp(n2, 1));
}

void makeDivisor()
{
    dv.pb(1);
    for(pll &pf : prime) {
        ll sz = dv.size(), now = pf.first, cnt = 1;

        while(cnt <= pf.second) {
            for(ll i = 0; i < sz; i++)
                dv.pb(dv[i] * now);

            cnt++, now *= pf.first;
        }
    }
}

ll wayFrom1(ll idx)
{
    if(dv[idx] == 1)
        return 1;
    ll &ret = way[idx];
    if(ret != -1)
        return ret;

    ll rt = 0, now = dv[idx];
    for(pll &pf : prime) {
        if(now % pf.first == 0) {
            rt += wayFrom1(pos[ now / pf.first ]);

            if(rt >= mod) rt -= mod;
        }
    }

    return ret = rt;
}

int main()
{
    ll n;
    cin >> n;

    primeFactor(n);
    makeDivisor();

    sort(dv.begin(), dv.end());
    for(ll i = 0; i < dv.size(); i++)
        pos[ dv[i] ] = i;

    ms(way, -1);
    for(ll i = 0; i < dv.size(); i++)
        way[i] = wayFrom1(i);

    ll q, u, v, g, gu, gv;
    cin >> q;
    while(q--) {
        sl(u), sl(v);
        ll g = __gcd(u, v);
        gu = u / g, gv = v / g;

        pf("%lld\n", (way[ pos[gu] ] * way[ pos[gv] ]) % mod);
    }

    return 0;
}