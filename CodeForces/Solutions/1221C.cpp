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
#define fastio std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

bool check(ll c, ll m, ll x, ll t)
{
    if(c < t || m < t) return 0;
    c -= t, m -= t;
    ll need = t-x;
    need -= c;
    need -= m;
    return need <= 0;
}

int main()
{
    ll q;
    cin >> q;
    while(q--) {
        ll c, m, x;
        sl(c), sl(m), sl(x);

        ll lo = 1, hi = 1e8, ans = 0;
        while(lo <= hi) {
            ll mid = (lo+hi) >> 1;

            if(check(c, m, x, mid)) {
                ans = mid;
                lo = mid + 1;
            }
            else
                hi = mid-1;
        }

        pf("%lld\n", ans);
    }

    return 0;
}