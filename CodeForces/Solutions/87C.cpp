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
#define inf (1LL << 61)
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
vector <pii> g[sz];
ll grundy[sz], pre[sz];

ll findMex(set <int> &lst)
{
    ll mex = 0;
    auto it = lst.begin();
    while(it != lst.end() && *it == mex) ++it, ++mex;

    return mex;
}

int main()
{
    for1(i, sz-1) {

        ll sum = i;

        for(ll j = i+1; j < sz; j++) {

            sum += j;
            if(sum >= sz)
                break;

            g[sum].pb(mp(i, j));
        }
    }

    grundy[1] = grundy[2] = pre[1] = pre[2] = 0;

    for(ll i = 3; i < sz; i++) {

        set <int> lst;

        for(pii &p : g[i]) {

            ll l = p.first, r = p.second;

            ll Xor = pre[r] ^ pre[l-1];

            lst.insert(Xor);
        }

        grundy[i] = findMex(lst);

        pre[i] = grundy[i] ^ pre[i-1];
    }

    ll n; sl(n);

    ll k = inf;

    for(pii &p : g[n]) {

        ll l = p.first, r = p.second;

        ll Xor = pre[r] ^ pre[l-1];

        if(Xor == 0) k = min(k, r-l+1);
    }

    if(k == inf) cout << -1 << EL;
    else    cout << k << EL;

    return 0;
}