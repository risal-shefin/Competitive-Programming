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

const ll sz = 3e5 + 10;

pll ara[sz], lim;
multiset <ll> lst;

int main()
{
    ll n;
    cin >> n;
    for1(i, n) {
        if(i == 1) {
            sl(lim.first), sl(lim.second);
            lim.second = lim.second - lim.first + 1;
        }
        else {
            sl(ara[i].first), sl(ara[i].second);
            ara[i].second = ara[i].second - ara[i].first + 1;
        }
    }
    sort(ara+2, ara+n+1, greater <pll> ());

    ll ans = inf, ptr = 2, chk = 1;
    while(chk) {
        for(; ptr <= n; ptr++) {
            if(ara[ptr].first <= lim.first)
                break;

            lst.insert(ara[ptr].second);
        }

        ans = min(ans, (ll)lst.size() + 1);
        chk = 0;

        if(lst.empty()) continue;

        ll f = *(lst.begin());
        if(f <= lim.first) {
            lim.first -= f;
            lst.erase(lst.find(f));
            chk = 1;
        }
    }

    cout << ans << endl;

    return 0;
}