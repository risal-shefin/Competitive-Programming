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

const ll sz = 55;
ll ara[sz];
ll cnt[7], cst[7];

int main()
{
    ll n;
    cin >> n;
    for1(i, n) sl(ara[i]);

    for1(i, 5) sl(cst[i]);

    ll pnt = 0, ok = 0;
    for1(i, n) {
        pnt += ara[i];

        do {
            ll mx = 0, idx = 0;
            ok = 0;

            for1(j, 5) {
                if(pnt < cst[j])
                    continue;

                if(cst[j] > mx) {
                    mx = cst[j];
                    idx = j;
                }
            }

            if(idx != 0) {
                cnt[idx] += (pnt / cst[idx]);
                pnt %= cst[idx], ok = 1;
            }

        } while(ok);
    }

    for1(i, 5) cout << cnt[i] << " ";
    cout << EL << pnt << EL;

    return 0;
}