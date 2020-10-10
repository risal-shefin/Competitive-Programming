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
#define for1(i, stop) for(ll i = 1; i <= stop; i++)
#define for0(i, stop) for(ll i = 0; i < stop; i++)
#define rep1(i, start) for(ll i = start; i >= 1; i--)
#define rep0(i, start) for(ll i = (start-1); i >= 0; i--)
#define ms(n, i) memset(n, i, sizeof(n))
#define casep(n) printf("Case %lld:", ++n)
#define pn printf("\n")
#define EL '\n'
#define fastio std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const ll MAX = 1e9, last = 1e18;
const ll MAX4 = (ll)1e9 / (2*2), lim4 = cbrtl(MAX4);
vector <ll> p, lst, factor[16], pf;
bool mark[lim4 + 10];

ll makeNum(ll p1, ll p2)
{
    ll m1 = 1, m2 = 1;
    while(m1 * p1 <= MAX) m1 *= p1;
    while(m2 * p2 <= MAX) m2 *= p2;

    return m1 * m2;
}

ll factorCount(ll &val, ll p1)
{
    ll cnt = 0;
    while(val % p1 == 0) {
        val /= p1;
        cnt++;
    }
    return cnt;
}

void genQueryList() {
    ll mul = 1;
    for(ll &prime : p) {
        if(mul > last / prime) {
            lst.pb(mul);
            mul = prime;
        }
        else
            mul *= prime;

        factor[lst.size()].pb(prime);
    }
    if(mul > 1) lst.pb(mul);
}

inline ll ask(ll num) {
    cout << "? " << num << endl;
    ll g; cin >> g;
    return g;
}

int main()
{
    fastio;
    for(ll i = 2; i <= lim4; i++) {
        if(mark[i] == 0) {
            for(ll j = i*i; j <= lim4; j += i)
                mark[j] = 1;

            p.pb(i);
        }
    }

    genQueryList();

    ll t;
    cin >> t;
    while(t--) {
        ll ans = 1;

        for(ll i = 0; i < lst.size(); i++) {
            ll g = ask(lst[i]);

            for(ll &f : factor[i])
                if(g % f == 0) pf.pb(f);
        }

        for(ll i = 0; i < pf.size(); i += 2) {
            ll p1 = pf[i], p2 = pf[i];
            if(i+1 < pf.size()) p2 = pf[i+1];

            ll num = makeNum(p1, p2);
            ll g = ask(num);

            ll cnt = factorCount(g, p1);
            ans *= (cnt + 1);

            cnt = factorCount(g, p2);
            ans *= (cnt + 1);
        }

        ans = max(ans + 7, 2 * ans);
        cout << "! " << ans << endl;

        pf.clear();
    }

    return 0;
}