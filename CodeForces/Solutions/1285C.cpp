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

deque <ll> p;
pll ans = mp(inf, inf);
ll n, mn = inf;

void solve(ll pos, ll mul)
{
    if(pos >= p.size()) {
        ll dv2 = n / mul;
        ll mx = max(mul, dv2);
        if(mx < mn) {
            ans = mp(mul, dv2);
            mn = mx;
        }
        return;
    }

    solve(pos + 1, mul);
    solve(pos + 1, mul * p[pos]);
}

int main()

{
    sl(n);

    ll x = n;
    for(ll i = 2; i * i <= x; i++) {
        if(x % i == 0) {
            ll cnt = 0, m = 1;
            while(x % i == 0) {
                x /= i;
                cnt++;
                m *= i;
            }

            p.push_back(m);
        }
    }
    if(x > 1)
        p.push_back(x);

    solve(0, 1);

    cout << ans.first << " " << ans.second << endl;

    return 0;
}