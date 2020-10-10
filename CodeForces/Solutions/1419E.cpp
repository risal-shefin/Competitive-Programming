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
#define inf (1LL << 61)
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

const ll dsz = 2e3 + 10;
ll dv[dsz], take[dsz], pfac[dsz], ans[dsz], idx, idf;

void make_div(ll num)
{
    idx = 0;

    for(ll i = 2; i * i <= num; i++) {
        if(num % i != 0)
            continue;

        dv[++idx] = num / i;
        if(num / i != i) dv[++idx] = i;
    }
    dv[++idx] = num;
}

void make_pf(ll num)
{
    idf = 0;

    for(ll i = 2; i * i <= num; i++) {
        if(num % i != 0)
            continue;

        while(num % i == 0) num /= i;

        pfac[++idf] = i;
    }
    if(num > 1) pfac[++idf] = num;
}

int main()
{
    ll t;
    cin >> t;

    while(t--) {

        ll n, chk = 0; sl(n);

        make_div(n);
        make_pf(n);

        ll ida = 0, res = 0;
        ms(take, 0);

        if(idf == 2) {
            ll val = -1;

            for1(i, idf)
                if(n % (pfac[i] * pfac[i]) == 0) val = pfac[i] * pfac[i];

            if(val == -1) goto done;

            pfac[++idf] = val, chk = 1;
            for1(j, idx) if(dv[j] == val) take[j] = 1;
        }
        done:

        for1(i, idf) {

            ll nxt = i+1;
            if(nxt > idf) nxt = 1;

            if(i == nxt) break;
            if(chk && nxt == 1) break;

            for1(j, idx) if(dv[j] == pfac[i] * pfac[nxt]) take[j] = 1;
        }

        for1(i, idf) {

            ans[++ida] = pfac[i];

            for1(j, idx) {

                if(dv[j] == pfac[i]) take[j] = 1;

                if(take[j]) continue;

                if(dv[j] % pfac[i] == 0)
                    ans[++ida] = dv[j], take[j] = 1;
            }

            ll nxt = i+1, fnd = -1;
            if(nxt > idf) nxt = 1;

            if(i <= 2 && nxt == 1) {
                if(i == 2) res = 1;
                break;
            }
            if(chk && nxt == 1) break;

            ans[++ida] = pfac[i] * pfac[nxt];
        }

        for1(i, ida) {
            if(i != 1) pf(" ");
            pf("%lld", ans[i]);
        }
        pf("\n%lld\n", res);
    }

    return 0;
}