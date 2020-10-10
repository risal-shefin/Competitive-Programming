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

inline ll solve(ll siz, ll cnt, ll w)
{
    ll mn = min(siz/w, cnt);
    return mn;
}

int main()
{
    ll t;
    cin >> t;
    while(t--) {

        ll p, f;
        sl(p), sl(f);

        ll cnts, cntw;
        sl(cnts), sl(cntw);

        ll s, w;
        sl(s), sl(w);

        if(s > w) {
            swap(s, w);
            swap(cnts, cntw);
        }

        ll ans = 0;

        for(ll i = 0; i <= cnts; i++) {

            if(i*s <= p) {

                ll np = p, nf = f, cnt1 = cnts, cnt2 = cntw, w1 = s, w2 = w, ret = 0;
                np -= (i*w1), ret += i;

                ll take = solve(np, cnt2, w2);
                np -= (take*w2), ret += take, cnt2 -= take;

                take = solve(nf, cnt1-i, w1);
                nf -= (take*w1), ret += take;

                take = solve(nf, cnt2, w2);
                nf -= (take*w2), ret += take;

                ans = max(ans, ret);
            }
            else if(i*s <= f) {

                ll np = p, nf = f, cnt1 = cnts, cnt2 = cntw, w1 = s, w2 = w, ret = 0;
                nf -= (i*w1), ret += i;

                ll take = solve(nf, cnt2, w2);
                nf -= (take*w2), ret += take, cnt2 -= take;

                take = solve(np, cnt1-i, w1);
                np -= (take*w1), ret += take;

                take = solve(np, cnt2, w2);
                np -= (take*w2), ret += take;

                ans = max(ans, ret);
            }
        }

        pf("%lld\n", ans);
    }

    return 0;
}