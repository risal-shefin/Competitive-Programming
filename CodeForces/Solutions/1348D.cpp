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

vector <ll> ans;

int main()
{
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        sl(n);

        ll need = n-1, ase = 1, sum = 0;
        while(sum <= need) {

            ll rest = need - sum;
            if(rest <= ase * 2) {
                ll extra = rest - ase;
                ans.pb(extra);
                break;
            }

            ll lo = 1, hi = ase, incr = 0;
            while(lo <= hi) {
                ll mid = lo+hi >> 1;

                ll cnt = ase + mid;
                if(cnt + cnt <= rest) {
                    incr = mid;
                    lo = mid + 1;
                }
                else
                    hi = mid - 1;
            }

            ase += incr;
            sum += ase;
            ans.pb(incr);
        }

        pf("%lld\n", (ll)ans.size());
        for(ll i = 0; i < ans.size(); i++) {
            if(i != 0) pf(" ");
            pf("%lld", ans[i]);
        }
        pn;

        ans.clear();
    }

    return 0;
}