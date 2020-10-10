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

const ll sz = 1e3 + 10;
vector <ll> sub[sz], lst;
bool forbid[sz];

inline void ask()
{
    cout << "? " << lst.size();
    for(ll &idx: lst) cout << " " << idx;
    cout << endl;
    lst.clear();
}

int main()
{
    fastio;
    ll t;
    cin >> t;
    while(t--) {
        ll n, k, tot, inp, mx;
        cin >> n >> k;
        for1(i, k) {
            cin >> tot;

            for1(j, tot) {
                cin >> inp;
                sub[i].pb(inp);
            }
        }

        for1(i, n) lst.pb(i);
        ask();
        cin >> mx;

        ll lo = 1, hi = k, ret = -1, mx2 = -1;
        while(lo <= hi) {
            ll mid = (lo+hi) >> 1;

            for1(i, mid) {
                for(ll &idx : sub[i]) lst.pb(idx);
            }
            ask();
            cin >> inp;

            if(inp == mx) {
                ret = mid;
                hi = mid-1;
            }
            else
                lo = mid+1;
        }

        if(ret != -1) {
            for(ll &idx : sub[ret]) forbid[idx] = 1;
            for1(i, n) if(!forbid[i]) lst.pb(i);
            ask();
            cin >> mx2;
        }

        cout << "!";
        for1(i, k) {
            if(i != ret)
                cout << " " << mx;
            else
                cout << " " << mx2;
        }
        cout << endl;

        string got; cin>>got;
        if(got == "Incorrect") exit(0);

        for1(i, k) sub[i].clear();
        ms(forbid, 0);
    }

    return 0;
}