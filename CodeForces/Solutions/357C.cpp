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

const ll sz = 3e5 + 10;
set <int> lst;
vector <int> rmv;
ll lose[sz];

int main()
{
    ll n, m;
    cin >> n >> m;
    for1(i, n) rmv.pb(i);
    lst.insert(all(rmv));
    rmv.clear();

    for1(i, m) {
        ll l, r, x;
        sl(l), sl(r), sl(x);

        for(auto it = lst.lower_bound(l); it != lst.end() && *it <= r; ++it) {
            if(*it != x) {
                lose[*it] = x;
                rmv.pb(*it);
            }
        }
        for(int &kn : rmv) lst.erase(kn);
        rmv.clear();
    }

    for1(i, n) {
        if(i != 1) pf(" ");
        pf("%lld", lose[i]);
    }
    pn;

    return 0;
}