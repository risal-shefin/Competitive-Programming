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

ll h, c, t, ans;
ld diff;

inline ld solve(ll k)
{
    ll htake = (k+1) / 2, ctake = (k-1) / 2;
    return (ld)(htake * h + ctake * c) / k;
}

inline void update_ans(ld d, ll k)
{
    if(d < diff)
    {
        diff = d;
        ans = k;
    }
    else if(d == diff)
        ans = min(ans, k);
}

int main()
{
    ll test;
    cin >> test;
    while(test--) {
        ans = 2;
        sl(h), sl(c), sl(t);

        ld nowt = (ld)(h+c) / 2;
        diff = abs(t - nowt);

        ll lo = 1, hi = 1 + 1e12;
        while(lo + 1 < hi) {
            ll mid = (lo+hi) / 2;
            if(mid % 2 == 0) mid--;

            ld tval1 = solve(mid), tval2 = solve(mid+2);
            ld d1 = abs(t-tval1), d2 = abs(t-tval2);

            if(d1 <= d2) {
                hi = mid;
                update_ans(d1, mid);
            }
            else {
                lo = mid+2;
                update_ans(d2, mid+2);
            }
        }

        pf("%lld\n", ans);
    }

    return 0;
}