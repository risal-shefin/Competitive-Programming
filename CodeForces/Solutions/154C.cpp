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

const ll sz = 1e6 + 10;

const ll MAX_N = 1e6+10, mod = 2e9+63, base1 = 1e9+21, base2 = 1e9+181;
ll s[MAX_N];  // 1-indexed
ll pw1[MAX_N], pw2[MAX_N], slen;

void pw_calc() {
    pw1[0] = pw2[0] = 1;
    for(int i = 1; i < MAX_N; i++) {
        pw1[i] = (pw1[i-1] * base1) % mod;
        pw2[i] = (pw2[i-1] * base2) % mod;
    }
}

struct Hash {
    ll h1[MAX_N], h2[MAX_N];

    void init() {
        h1[0] = h2[0] = 0;
        for(int i = 1; i <= slen; i++) {
            h1[i] = (h1[i-1] * base1 + s[i]) % mod;
            h2[i] = (h2[i-1] * base2 + s[i]) % mod;
        }
    }

    inline ll hashVal(int l, int r) {
        ll hsh1 = (h1[r] - h1[l-1] * pw1[r-l+1]) % mod;
        if(hsh1 < 0) hsh1 += mod;
        ll hsh2 = (h2[r] - h2[l-1] * pw2[r-l+1]) % mod;
        if(hsh2 < 0) hsh2 += mod;
        return (hsh1 << 32) | hsh2;
    }
} fw;

/* call pw_calc() for calculating powers less than MAX_N
 * slen = strlen(s+1);   --> string length
 * fw.init() will calculate the double hashes
 * fw.hashVal(l,r) will return [l,,r] merged double hash value
*/

ll frnd[sz], nonFrnd[sz];
vector <int> g[sz], g2[sz];

int main()
{
    ll n, m;
    cin >> n >> m;

    for1(i, m) {
        ll u, v;
        sl(u), sl(v);

        g[u].pb(v);
        g[v].pb(u);
    }

    for1(i, n) {
        g2[i] = g[i];

        g[i].pb(i);

        sort(all(g[i]));
        sort(all(g2[i]));
    }

    ll ans = 0, idx = 0;

    for1(i, n) {

        slen = g[i].size(), idx = 0;
        for(int &f : g[i]) s[++idx] = f;

        fw.init();
        ll friendHash = (fw.h1[slen] << 32) | fw.h2[slen];

        frnd[i] = friendHash;

        slen = g2[i].size(), idx = 0;
        for(int &f : g2[i]) s[++idx] = f;

        fw.init();
        friendHash = (fw.h1[slen] << 32) | fw.h2[slen];

        nonFrnd[i] = friendHash;
    }

    sort(frnd+1, frnd+n+1);
    sort(nonFrnd+1, nonFrnd+n+1);

    for1(i, n) {

        ll start = i, stop;

        for(ll j = i; j <= n; j++) {

            if(frnd[j] != frnd[i])
                break;
            stop = j;
        }

        ll tot = stop-start+1;
        ans += (tot * (tot-1)) / 2;

        i = stop;
    }

    for1(i, n) {

        ll start = i, stop;

        for(ll j = i; j <= n; j++) {

            if(nonFrnd[j] != nonFrnd[i])
                break;
            stop = j;
        }

        ll tot = stop-start+1;
        ans += (tot * (tot-1)) / 2;

        i = stop;
    }

    cout << ans << EL;

    return 0;
}