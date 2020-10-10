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

const ll sz = 5e5 + 10;
ll ara[sz], cs[sz], segVal[sz], minVal[sz];

int main()
{
    ll n, fix;
    cin >> n;
    ll h = n / 2;
    if(n & 1) h++;

    for1(i, h) sl(ara[i]);
    cin >> fix;

    for(ll i = h+1; i <= n; i++) ara[i] = fix;

    ll k = n/2 + 1;
    for1(i, n) cs[i] = cs[i-1] + ara[i];
    for(ll i = 0; i <= n; i++) minVal[i] = inf;

    for(ll i = 1; i+k-1 <= n; i++) {
        segVal[i] = cs[i+k-1] - cs[i-1];
        minVal[i] = min(minVal[i-1], segVal[i]);
    }

    for(; k <= n; k++) {
        ll lastStart = n-k+1, extra = k - (n/2 + 1);
        minVal[lastStart] += extra * fix;
    }

    ll ans = -1;
    for(k = n/2+1; k <= n; k++) {
        ll lastStart = n-k+1;
        if(minVal[lastStart] > 0) {
            ans = k;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}