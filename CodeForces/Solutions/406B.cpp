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

const ll sz = 5e5 + 10, MAX_N = 1e6;
ll X[sz];
bool take[MAX_N+10];
vector <ll> Y;

int main()
{
    ll n;
    cin >> n;

    for1(i, n) {
        sl(X[i]);
        take[ X[i] ] = 1;
    }

    ll cnt = 0;
    for1(i, n) {
        ll sym = MAX_N-X[i] + 1;   // X[i]-1 = MAX_N-sym

        if(!take[sym]) {
            Y.pb(sym);
            take[sym] = 1;
        }
        else
            cnt++;  // (X[i]-1) + (sym-1) = MAX_N-1
    }

    for(ll i = 1, y = 1; i <= cnt; y++) {
        ll y2 = (MAX_N-y+1);    // (MAX_N-y) + (MAX_N-y2) = MAX_N-1

        if(!take[y] && !take[y2]) {
            Y.pb(y), Y.pb(y2);
            take[y] = take[y2] = 1;

            i += 2;
        }
    }

    sort(all(Y));
    cout << Y.size() << EL;

    for(ll &y : Y) pf("%lld ", y);
    pn;

    return 0;
}