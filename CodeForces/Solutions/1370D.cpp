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
ll ara[sz], dp[sz], n, k, h;

bool solve(ll mx)
{
    ll l = 1, r = n;
    if(k % 2 == 0) r = n-1;

    ll cnt = 0;
    for(ll i = l; i <= r; i++) {
        if(ara[i] > mx)
            continue;

        cnt++, i++;
    }

    ll need = k / 2;
    if(k & 1) need++;

    return cnt >= need;
}

bool solve2(ll mx)
{
    ll l = 2, r = n;
    if(k & 1) r = n-1;

    ll cnt = 0;
    for(ll i = l; i <= r; i++) {
        if(ara[i] > mx)
            continue;

        cnt++, i++;
    }

    ll need = k / 2;

    return cnt >= need;
}

int main()
{
    cin >> n >> k;
    for1(i, n) sl(ara[i]);

    ll lo = 1, hi = 1e9 + 10, ans = inf;
    while(lo <= hi) {
        ll mid = lo+hi >> 1;

        if(solve(mid)) {
            ans = mid;
            hi = mid-1;
        }
        else
            lo = mid+1;
    }

    lo = 1, hi = 1e9 + 10;
    while(lo <= hi) {
        ll mid = lo+hi >> 1;

        if(solve2(mid)) {
            ans = min(ans, mid);
            hi = mid-1;
        }
        else
            lo = mid+1;
    }

    cout << ans << endl;

    return 0;
}