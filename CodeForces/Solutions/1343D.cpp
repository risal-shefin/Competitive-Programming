#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;

#define ll int
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
#define EL '\n'
#define fastio std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const ll sz = 2e5 + 10, tot = 2*sz;
ll ara[sz], cnt[tot], cnt1[tot];

int main()
{
    ll t;
    cin >> t;
    while(t--) {
        ll n, k;
        si(n), si(k);

        for1(i, n) {
            si(ara[i]);
        }

        ll last = 2*k;
        for(ll i = 1, j = n; i <= n / 2; i++, j--) {
            ll sum = ara[i] + ara[j];

            cnt[sum]++;

            ll mn = min(ara[i], ara[j]);
            ll mx = max(ara[i], ara[j]);

            ll minSum = mn+1, maxSum = mx+k;
            cnt1[minSum]++, cnt1[maxSum+1]--;
        }

        for1(i, last) cnt1[i] += cnt1[i-1];

        ll h = n / 2, ans = 1e9;
        for(ll i = 2; i <= last; i++) {
            ll zero = cnt[i], one = cnt1[i];
            one -= zero;

            ll need = one + (h - (zero + one)) * 2;
            ans = min(ans, need);
        }

        pf("%d\n", ans);

        for1(i, last+1) cnt[i] = cnt1[i] = 0;
    }

    return 0;
}