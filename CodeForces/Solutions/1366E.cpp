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

const ll sz = 2e5 + 10, mod = 998244353;
ll n, m;
ll a[sz], b[sz], dp[sz], mn[sz], rgt[sz];

unordered_map <int, int, custom_hash> idx;

inline void imp()
{
    pf("0\n");
    exit(0);
}

int main()
{
    cin >> n >> m;
    for1(i, n) sl(a[i]);
    for1(i, m) sl(b[i]);

    if(n < m) imp();

    mn[n+1] = inf;
    rep1(i, n) {
        mn[i] = min(a[i], mn[i+1]);
        if(idx.find(a[i]) == idx.end())
            idx[ a[i] ] = i;
    }

    if(mn[1] != b[1]) imp();

    dp[1] = 1, rgt[1] = idx[b[1]];
    ll ptr = rgt[1];

    for(ll i = 2; i <= m; i++) {
        ll now = idx[b[i]];
        if(now <= rgt[i-1] || mn[now] != b[i]) imp();
        rgt[i] = now;

        for(; ptr <= now; ptr++) {
            if(mn[ptr] == b[i]) break;
        }
        ll lft = ptr;

        dp[i] = ((now-lft+1) * dp[i-1]) % mod;
    }

    cout << dp[m] << endl;

    return 0;
}