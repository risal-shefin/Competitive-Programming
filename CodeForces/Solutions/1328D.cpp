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

const ll sz = 2e5 + 10;
ll ara[sz], col[sz], n;

ll solve(ll pos, ll prv, ll msk)
{
    if(pos > n) {
        return __builtin_popcount(msk);
    }

    ll mn = inf;
    for(ll i = 0; i < 3; i++) {
        if(ara[pos-1] != ara[pos] && prv == i)
            continue;
        if(pos == n) {
            if(ara[pos] != ara[1] && i == 1)
                continue;
        }

        ll nmsk = msk | (1<<i);
        mn = solve(pos + 1, i, nmsk);
        col[pos] = i;

        break;
    }

    return mn;
}

int main()
{
    ll t;
    cin >> t;
    while(t--) {
        sl(n);

        for1(i, n) {
            sl(ara[i]);
        }

        col[1] = 1;
        ll ans = solve(2, 1, 2);

        for1(i, n) {
            if(ans == 2) {
                if(col[i] == 0) col[i] = 2;
            }
            if(ans == 3)
                if(col[i] == 0) col[i] = 3;
        }

        pf("%lld\n", ans);
        for1(i, n) {
            if(i != 1) pf(" ");
            pf("%lld", col[i]);
        }
        pn;
    }

    return 0;
}