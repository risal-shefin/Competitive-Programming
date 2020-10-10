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

vector <ll> ara[100009];
bool alr[100009];
ll cnt[1000009], now[100009];

int main()

{
    ms(cnt, 0);
    ll n, ase = 0;
    sl(n);
    for1(i, n) {
        ll m;
        sl(m);

        ll mn = inf, mx = -1;
        for1(j, m) {
            ll inp;
            sl(inp);
            ara[i].pb(inp);

            if(mn < inp && !alr[i]) {
                alr[i] = 1;
                ase++;
            }

            mn = min(mn, inp);
            mx = max(mx, inp);
        }

        now[i] = mn;
        if(!alr[i])
            cnt[mx]++;
    }

    ull ans = ase * n;

    cnt[1000001] = 0;
    for(ll i = 1000000; i >= 0; i--)
        cnt[i] += cnt[i+1];

    for1(i, n) {
        if(alr[i])
            continue;

        ans += ase;
        ans += cnt[ now[i]+1 ];
    }

    cout << ans << endl;

    return 0;
}