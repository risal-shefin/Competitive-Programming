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
ll ara[sz], cnt[32];

int main()
{
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        sl(n);

        for1(i, n) sl(ara[i]);

        for1(i, n) {
            for0(b, 32)
                cnt[b] += ((ara[i] >> b) & 1);
        }

        ll state = 0;

        for(ll b = 31; b >= 0; b--) {
            if(cnt[b] % 2 == 0)
                continue;

            ll h = cnt[b] / 2;

            if(h & 1) {
                if(n % 2 == 0) state = 1;
                else state = -1;

                break;
            }
            else {
                state = 1;
                break;
            }
        }

        if(state == 0) pf("DRAW\n");
        else if(state == 1) pf("WIN\n");
        else pf("LOSE\n");

        ms(cnt, 0);
    }

    return 0;
}