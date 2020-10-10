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

const ll sz = 105;
ll ara[sz], tmp[sz];
bool check[sz];
vector <int> ans;

int main()
{
    ll t;
    cin >> t;
    while(t--) {
        ms(check, 0);

        ll n, k;
        sl(n), sl(k);

        ll ase = 0;
        for1(i, n) {
            sl(ara[i]);
            tmp[i] = ara[i];

            if(!check[ ara[i] ]) {
                ase++;
                tmp[ase] = ara[i];
            }

            check[ ara[i] ] = 1;
        }

        //cout << ase << endl;
        if(k < ase) {
            pf("-1\n");
            continue;
        }

        sort(tmp+1, tmp+ase+1);

        for1(i, n) {
            ll ptr = 1;
            for1(j, k) {
                ans.pb(tmp[ptr]);
                ptr++;
                if(ptr > ase) ptr = 1;
            }
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