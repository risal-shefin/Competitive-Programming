// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T>  using orderedSet =
	tree<T, null_type, less<T>,   /// greater<T> for sorting decreasingly
	rb_tree_tag, tree_order_statistics_node_update>;


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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

const ll sz = 1e6 + 10;
ll ara[sz];
unordered_map <int, int, custom_hash> cnt, precnt;
orderedSet <pii> lst;

int main()
{
    ll n;
    cin >> n;
    for1(i, n) sl(ara[i]);

    rep1(i, n) {
        ++cnt[ ara[i] ];
        lst.insert(mp(cnt[ ara[i] ], i));
    }

    ll ans = 0;
    for1(i, n) {
        lst.erase(mp(cnt[ ara[i] ], i));
        --cnt[ ara[i] ];

        ++precnt[ ara[i] ];
        ans += lst.order_of_key(mp(precnt[ ara[i] ], 0));
    }

    cout << ans << endl;

    return 0;
}