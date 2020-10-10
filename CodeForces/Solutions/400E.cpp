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

const ll sz = 1e5 + 10, mxb = 20;
ll ara[sz];
set <int> zlst[mxb], olst[mxb];

int main()
{
    ll n, m, ans = 0;
    cin >> n >> m;

    for1(i, n) sl(ara[i]);

    rep0(b, mxb) {

        zlst[b].insert(0), zlst[b].insert(n+1);
        olst[b].insert(0), olst[b].insert(n+1);

        for1(i, n) {

            bool one = (ara[i] >> b) & 1;
            if(!one) {
                zlst[b].insert(i);
                continue;
            }

            olst[b].insert(i);

            ll start = i, stop = i;

            for(ll j = start+1; j <= n; j++) {

                one = (ara[j] >> b) & 1;
                if(!one) break;

                stop = j;
                olst[b].insert(i);
            }

            ll step = stop - start+1, tot = (step * (step+1)) / 2;
            ans += tot * (1LL << b);

            i = stop;
        }
    }

    while(m--) {

        ll i, v;
        sl(i), sl(v);

        ll prv = ara[i];

        rep0(b, mxb) {

            bool b1 = (prv >> b) & 1, b2 = (v >> b) & 1;
            if(b1 == b2) continue;

            ll lft = *(--zlst[b].lower_bound(i)), rgt = *zlst[b].upper_bound(i);

            if(b1 == 0) {

                ll step = i-1 - lft, tot = (step * (step+1)) / 2;
                ans -= tot * (1LL << b);

                step = rgt - (i+1), tot = (step * (step+1)) / 2;
                ans -= tot * (1LL << b);

                step = rgt-lft - 1, tot = (step * (step+1)) / 2;
                ans += tot * (1LL << b);

                zlst[b].erase(i);
                olst[b].insert(i);
            }
            else {

                ll step = i-1 - lft, tot = (step * (step+1)) / 2;
                ans += tot * (1LL << b);

                step = rgt - (i+1), tot = (step * (step+1)) / 2;
                ans += tot * (1LL << b);

                step = rgt-lft - 1, tot = (step * (step+1)) / 2;
                ans -= tot * (1LL << b);

                olst[b].erase(i);
                zlst[b].insert(i);
            }
        }

        ara[i] = v;

        pf("%lld\n", ans);
    }

    return 0;
}