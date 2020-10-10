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
ll n, a, r, m;
ll h[sz];

ll solve(ll hgt)
{
    ll ad = 0, rmv = 0, ret = 0;
    for1(i, n) {
        if(h[i] < hgt) ad += (hgt - h[i]);
        else rmv += (h[i] - hgt);
    }

    if(a+r >= m) {
        ll mn = min(ad, rmv);
        ret += (mn * m);

        ad -= mn, rmv -= mn;
    }

    ret += (ad * a), ret += (rmv * r);
    return ret;
}

int main()
{
    ll mx = 0;
    cin >> n >> a >> r >> m;
    for1(i, n) {
        sl(h[i]);
        mx = max(mx, h[i]);
    }
    if(mx == 0) {
        cout << 0 << endl;
        return 0;
    }

    ll lo = 0, hi = mx, ans = inf;
    while(lo < hi) {
        ll mid = (lo+hi) >> 1;

        ll ans1 = solve(mid), ans2 = solve(mid+1);

        //cout << ans1 << " " << ans2 << " " << mid << endl;
        if(ans1 < ans2) {
            ans = min(ans, ans1);
            hi = mid;
        }
        else {
            ans = min(ans, ans2);
            lo = mid+1;
        }
    }

    cout << ans << endl;

    return 0;
}