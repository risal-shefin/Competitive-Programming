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
ll reach[sz];

int main()
{
    int m, a, b;
    si(m), si(a), si(b);

    for0(i, sz) reach[i] = inf;
    ll last = 0, cur = 0;
    do {
        reach[cur] = last;

        if(cur >= b) cur -= b;
        else cur += a;

        last = max(last, cur);

    } while(cur != 0);

    ll ans = 0;
    for(ll i = 0; i <= last && i <= m; i++)
        ans += max(0LL, (m-reach[i]+1));

    if(m > last) {
        ll g = __gcd(a, b);
        ll gn = (m - last) / g;
        ll gsum = (gn * (gn+1)) / 2;

        ans+= (m*gn - (last*gn + g*gsum) + gn);     // Sum(m - (last+i*g) + 1) for all i -> (last+i*g <= m)
    }

    pf("%lld\n", ans);

    return 0;
}