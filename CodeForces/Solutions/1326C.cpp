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

const ll sz = 2e5 + 10, mod = 998244353;

ll pos[sz], ara[sz], now[sz], nibo[sz];

int main()
{
    ll n, k;
    cin >> n >> k;
    for1(i, n) {
        sl(ara[i]);
        pos[ ara[i] ] = i;
    }

    sort(ara+1, ara+n+1, greater<ll>());
    ll sum = 0;
    for1(i, k) {
        now[i] = pos[ ara[i] ];
        sum += ara[i];
    }

    if(k == 1) {
        cout << sum << " " << 1 << endl;
        return 0;
    }

    sort(now+1, now+k+1);

    ll mul = 1;
    for(ll i = 1; i < k; i++) {
        ll diff = now[i+1] - now[i];
        mul = (mul * diff) % mod;
    }

    cout << sum << " " << mul << endl;

    return 0;
}