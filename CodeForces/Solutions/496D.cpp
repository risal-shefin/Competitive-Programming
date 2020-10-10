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
#define pf printf
#define EL '\n'
#define fastio std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const ll sz = 1e5 + 10;
ll ara[sz], pt[sz], gn[sz], bp, bg, n, inp;

vector <pii> ans;

ll findNextPt(ll idx, ll t)
{
    ll lo = idx, hi = n, ret = inf;
    while(lo <= hi) {
        ll mid = (lo+hi) >> 1;

        ll v = pt[mid] - pt[idx-1];
        if(v < t)
            lo = mid+1;
        else {
            ret = mid;
            hi = mid-1;
        }
    }
    return ret;
}

ll findNextGn(ll idx, ll t)
{
    ll lo = idx, hi = n, ret = inf;
    while(lo <= hi) {
        ll mid = (lo+hi) >> 1;

        ll v = gn[mid] - gn[idx-1];
        if(v < t)
            lo = mid+1;
        else {
            ret = mid;
            hi = mid-1;
        }
    }
    return ret;
}

int main()
{
    cin >> n;
    for1(i, n) {
        sl(inp);
        if(inp == 1) pt[i] = 1;
        else    gn[i] = 1;
    }

    for1(i, n) {
        pt[i] += pt[i-1];
        gn[i] += gn[i-1];
    }

    for1(i, n) {
        ll now = 1, pwin = 0, gwin = 0;
        while(now <= n) {
            ll np = findNextPt(now, i);
            ll ng = findNextGn(now, i);

            if(np < ng) pwin++;
            else gwin++;

            now = min(np, ng) + 1;
            if(now >= inf) {
                now = -1;
                break;
            }

            if(now == n+1) {
                if((np < ng && pwin <= gwin) || (ng < np && gwin <= pwin)) {
                    now = -1;
                    break;
                }
            }
        }

        if(now != -1) {
            ans.pb(mp(max(pwin, gwin), i));
        }
    }
    sort(all(ans));

    cout << ans.size() << EL;
    for(pii &p : ans)
        pf("%d %d\n", p.first, p.second);

    return 0;
}