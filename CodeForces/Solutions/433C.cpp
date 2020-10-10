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
vector <ll> adj[sz];
ll ara[sz];

inline ll solve(ll x, ll y)
{
    ll sum = 0;
    for(ll &pg : adj[x]) sum += abs(y - pg);
    return sum;
}

int main()
{
    ll n, m;
    cin >> n >> m;
    for1(i, m) sl(ara[i]);

    for1(i, m) {
        if(i+1 <= m && ara[i] != ara[i+1]) adj[ ara[i] ].pb(ara[i+1]);
        if(i-1 >= 1 && ara[i] != ara[i-1]) adj[ ara[i] ].pb(ara[i-1]);
    }

    ll ans = 0;
    for1(i, (m-1)) ans += abs(ara[i] - ara[i+1]);
    ll tot = ans;

    for1(i, n) {
        if(adj[i].size() == 0)
            continue;

        ll now = 0;
        for(ll &pg : adj[i]) now += abs(i - pg);

        ll lo = 1, hi = n, ret = inf;
        while(lo < hi) {
            ll mid = lo+hi >> 1;
            ll got1 = solve(i, mid), got2 = solve(i, mid+1);

            if(got1 < got2) {
                ret = min(ret, got1);
                hi = mid;
            }
            else {
                ret = min(ret, got2);
                lo = mid+1;
            }
        }
        ll got = solve(i, lo);
        if(got < ret) ret = got;

        ans = min(ans, tot - now + ret);
    }

    cout << ans << endl;

    return 0;
}