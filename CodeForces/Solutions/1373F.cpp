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

const ll sz = 1e6 + 10;
ll a[sz], cap[sz], n;

ll solve(ll bck)
{
    bool house = 1;
    ll sum = bck, last = cap[n] - bck;
    for(ll i = 1; i <= n;) {
        if(house) {
            sum -= a[i];
            sum = min(sum, 0LL);
        }
        else {
            sum += cap[i];
            if(sum < 0) return -1;
            i++;
        }

        if(house && i == n) break;
        house ^= 1;
    }

    sum += last;
    if(sum < 0) return -2;

    return 1;
}

int main()
{
    ll t;
    cin >> t;
    while(t--) {
        sl(n);

        for1(i, n) sl(a[i]);
        for1(i, n) sl(cap[i]);

        ll lo = 0, hi = min(a[1], cap[n]), ok = 0;

        while(lo <= hi) {
            ll mid = lo+hi >> 1;

            ll got = solve(mid);

            if(got == -1)
                lo = mid + 1;
            else if(got == -2)
                hi = mid - 1;
            else {
                ok = 1;
                //cout << mid << endl;
                break;
            }
        }

        if(ok) pf("YES\n");
        else pf("NO\n");
    }

    return 0;
}