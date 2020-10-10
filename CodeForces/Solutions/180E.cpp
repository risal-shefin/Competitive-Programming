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

const ll sz = 2e5 + 10;
ll ara[sz];

vector <ll> pos[sz], pre[sz];

int main()
{
    ll n, m, k, ans = 0;
    cin >> n >> m >> k;

    for1(i, n) {
        sl(ara[i]);

        ll num = ara[i];

        if(pre[num].empty()) pre[num].pb(0);
        else pre[num].pb(pre[num].back() + i-pos[num].back() - 1);

        pos[num].pb(i);

        ll lo = 0, hi = pre[num].size() - 1, start;
        while(lo <= hi) {
            ll mid = lo+hi >> 1;

            ll cst = pre[num].back() - pre[num][mid];

            if(cst <= k) {
                start = mid;
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }

        ans = max(ans, pre[num].size() - start);
    }

    cout << ans << EL;

    return 0;
}