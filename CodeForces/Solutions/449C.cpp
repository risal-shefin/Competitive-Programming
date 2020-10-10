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

const ll sz = 1e5 + 10;
vector <ll> mult[sz];
bool check[sz], take[sz];
vector <pii> ans;

int main()
{
    ll n;
    sl(n);

    for(ll i = 2; i*i <= n; i++) {

        if(!check[i]) {
            for(ll j = i*i; j <= n; j += i)
                check[j] = 1;
        }
    }

    for(ll i = n; i >= 2; i--) {

        if(check[i]) continue;

        for(ll j = i; j <= n; j += i) {

            if(!take[j]) {
                mult[i].pb(j);
                take[j] = 1;
            }
        }

        if(mult[i].size() <= 1) continue;

        while(mult[i].size() > 3) {

            pii p;
            p.first = mult[i].back(), mult[i].pop_back();
            p.second = mult[i].back(), mult[i].pop_back();

            ans.pb(p);
        }

        if(mult[i].size() == 2) ans.pb(mp(mult[i][0], mult[i][1]));
        else {
            ans.pb(mp(mult[i][0], mult[i][2]));
            take[ mult[i][1] ] = 0;
        }
    }

    cout << ans.size() << EL;
    for(pii &p : ans)
        pf("%d %d\n", p.first, p.second);

    return 0;
}