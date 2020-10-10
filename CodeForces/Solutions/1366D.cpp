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

const ll MAXN = 1e7 + 5;
int mxp[MAXN], cnt[MAXN];
bool check[MAXN];

const ll sz = 5e5 + 10;
ll ans1[sz], ans2[sz];

int main()
{
    for(int i = 2; i < MAXN; ++i) {
        if(!check[i]) {
            for(int j = i; j < MAXN; j += i) {
                check[j] = 1;

                mxp[j] = max(mxp[j], i);
                cnt[j]++;
            }
        }
    }

    ll n, inp;
    cin >> n;
    for1(i, n) {
        sl(inp);
        if(cnt[inp] <= 1) ans1[i] = ans2[i] = -1;
        else {
            ll d1 = inp;
            while(d1 % mxp[inp] == 0) d1 /= mxp[inp];
            ans1[i] = d1, ans2[i] = mxp[inp];
        }
    }

    for1(i, n) {
        if(i != 1) pf(" ");
        pf("%lld", ans1[i]);
    }
    pn;
    for1(i, n) {
        if(i != 1) pf(" ");
        pf("%lld", ans2[i]);
    }
    pn;

    return 0;
}