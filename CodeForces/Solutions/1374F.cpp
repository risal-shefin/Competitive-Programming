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

vector <int> ans;
const ll sz = 510;
ll ara[sz], n;
pii ara2[sz];

void solve()
{
    for(ll i = 1; i <= n-3; i++) {
        ll now = i, pos;

        for(ll j = i; j <= n; j++) {
            if(ara[j] == now) {
                pos = j;
                break;
            }
        }

        while(i <= pos-2) {
            ll start = pos-2;
            ara[pos] = ara[pos-1], ara[pos-1] = ara[start];
            ara[start] = now;

            ans.pb(start); pos = start;
        }

        if(i + 1 == pos) {
            ans.pb(i), ans.pb(i);
            ara[pos] = ara[pos+1], ara[pos+1] = ara[i];
            ara[i] = now;
        }
    }
}

void lastThree()
{
    ll start = n-2;
    for1(i, 3) {
        if(is_sorted(ara+start, ara+n+1))
            break;

        ans.pb(start);
        swap(ara[start+1], ara[n]);
        swap(ara[start], ara[start+1]);
    }
}

int main()
{
    ll t, cs = 0;
    cin >> t;
    while(t--) {
        sl(n);

        for1(i, n) {
            sl(ara[i]);
            ara2[i] = mp(ara[i], i);
        }
        sort(ara2+1, ara2+n+1);

        for1(i, n) ara[ ara2[i].second ] = i;

        solve();
        lastThree();

        if(!is_sorted(ara+1, ara+n+1)) {

            for1(i, n) ara[ ara2[i].second ] = i;

            for1(i, n-1) {
                if(ara2[i].first == ara2[i+1].first) {

                    swap(ara[ ara2[i].second ], ara[ ara2[i+1].second ]);
                    break;
                }
            }

            ans.clear();
            solve();
            lastThree();

            if(!is_sorted(ara+1, ara+n+1)) {
                pf("-1\n");
                ans.clear();
                continue;
            }
        }

        pf("%lld\n", (ll)ans.size());
        for(ll i = 0; i < ans.size(); i++) {
            if(i != 0) pf(" ");
            pf("%lld", ans[i]);
        }
        pn;

        //cout << "Case " << ++cs << endl;
        ans.clear();
    }

    return 0;
}