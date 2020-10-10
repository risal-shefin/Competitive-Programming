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

vector <ll> p;

ll ase = 0, tM, tlast, ta;

void solve(ll pos, ll mul, ll take, ll rng)
{
    if(pos >= p.size()) {
        if(take == 0)
            return;

        if(take & 1)
            ase += (rng / mul);
        else
            ase -= (rng / mul);

        return;
    }

    solve(pos + 1, mul, take, rng);
    solve(pos + 1, mul * p[pos], take+1, rng);
}

int main()

{
    ll t;
    sl(t);
    while(t--) {
        ll a, m;
        sl(a), sl(m);

        ll g = __gcd(a, m);

        ll last = a + m - 1;
        tM = m / g, tlast = last / g, ta = a / g;

        ll tmp = tM;
        for(ll i = 2; i * i <= tmp; i++) {
            if(tmp % i == 0) {
                while(tmp % i == 0)
                    tmp /= i;

                p.pb(i);
            }
        }
        if(tmp > 1)
            p.pb(tmp);

        ase = 0;
        solve(0, 1, 0, tlast);

        ll rgt = tlast - ase;

        ase = 0;
        solve(0, 1, 0, ta);
        ll lft = ta - ase;

        pf("%lld\n", rgt - lft + 1);

        p.clear();
    }

    return 0;
}