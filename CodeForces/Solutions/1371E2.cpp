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

const ll sz = 1e5 + 10;
ll ara[sz], n, p;;

bool isValid(ll now)
{
    ll ptr = 1;
    for1(i, n) {
        while(ptr <= n && ara[ptr] <= now) ptr++;

        if(ptr - i >= p) return 0;
        now++;
    }
    return 1;
}

int main()
{
    cin >> n >> p;

    for1(i, n) sl(ara[i]);

    sort(ara+1, ara+n+1);

    ll start = 1, now = start;
    for1(i, n) {
        if(now < ara[i]) {
            ll diff = ara[i] - now;
            now += diff, start += diff;
        }
        now++;
    }

    ll lo = start, hi = 1e9, stop = -1;
    while(lo <= hi) {
        ll mid = lo+hi >> 1;

        if(isValid(mid)) {
            stop = mid;
            lo = mid + 1;
        }
        else
            hi = mid - 1;
    }

    cout << max(0LL, stop-start+1) << EL;
    loop(i, start, stop, 1) {
        if(i != start) pf(" ");
        pf("%lld", i);
    }
    if(stop != -1) pn;

    return 0;
}