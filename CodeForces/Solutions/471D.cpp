/* Hint: Let, the hash of [L,R] segment of bear is = bhash,
 * the hash of elephant is = ehash.
 * We have to either increase or decrease bhash depending on
 * the value of bear[L] and elephant[1] and compare it with ehash.

 * For example: let, base = 10 and bhash = 364.
 * If bear[L]-elephant[1] = 2, the new bhash will be = 364+222 = 586.
 * If elephant[1]-bear[L] = 1, the new bhash will be = 364-111 = 253.

 * More hint: We can write: 222 = 2*10^2+2*10^1+2*10^0.
 * So, these types of numbers follow the characteristics of geometric series.
*/

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

const ll MAX_N = 2e5 + 10, mod = 2e9+63, base1 = 1e9+21, base2 = 1e9+181;
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

    inline ll hashOne(int l, int r) {
        ll hsh1 = (h1[r] - h1[l-1] * pw1[r-l+1]) % mod;
        if(hsh1 < 0) hsh1 += mod;
        return hsh1;
    }

    inline ll hashTwo(int l, int r) {
        ll hsh2 = (h2[r] - h2[l-1] * pw2[r-l+1]) % mod;
        if(hsh2 < 0) hsh2 += mod;
        return hsh2;
    }
} fw1, fw2;

/* call pw_calc() for calculating powers less than MAX_N
 * slen = strlen(s+1);   --> string length
 * fw.init() will calculate the double hashes
 * fw.hashVal(l,r) will return [l,,r] merged double hash value
 * fw.hashOne(l, r) will return [l,,r] base1 hash
 * fw.hashTwo(l, r) will return [l,,r] base2 hash
*/

#define x first
#define y second
pll extendedEuclid(ll a, ll b)   // returns x, y for ax + by = gcd(a,b)
{
    if(b == 0) return pll(1, 0);
    else
    {
        pii d = extendedEuclid(b, a % b);
        return pll(d.y, d.x - d.y * (a / b));
    }
}

ll modularInverse(ll a, ll n)
{
    pll ret = extendedEuclid(a, n);
    return ((ret.x % n) + n) % n;
}

ll bear[MAX_N], el[MAX_N];

int main()
{
    pw_calc();

    ll n, w;
    cin >> n >> w;
    for1(i, n) {
        sl(bear[i]);
        s[i] = bear[i];
    }
    slen = n;
    fw1.init();

    for1(i, w) {
        sl(el[i]);
        s[i] = el[i];
    }
    slen = w;
    fw2.init();
    ll elHash = fw2.hashVal(1, w);

    ll inv1 = modularInverse(base1-1, mod);
    ll inv2 = modularInverse(base2-1, mod);

    ll p1 = pw1[w] - 1;
    if(p1 < 0) p1 += mod;
    ll p2 = pw2[w] - 1;
    if(p2 < 0) p2 += mod;

    ll geom1 = (p1 * inv1) % mod;
    ll geom2 = (p2 * inv2) % mod;

    ll ans = 0;
    for(ll i = 1; i+w-1 <= n; i++) {
        ll r = i+w-1;

        ll h1 = fw1.hashOne(i, r), h2 = fw1.hashTwo(i, r);
        ll diff = abs(bear[i] - el[1]);
        ll factor1 = (diff*geom1) % mod, factor2 = (diff*geom2) % mod;

        if(bear[i] >= el[1]) {
            h1 = (h1 - factor1) % mod;
            if(h1 < 0) h1 += mod;
            h2 = (h2 - factor2) % mod;
            if(h2 < 0) h2 += mod;
        }
        else {
            h1 = (h1 + factor1) % mod;
            h2 = (h2 + factor2) % mod;
        }

        ll hsh = (h1 << 32) | h2;
        if(hsh == elHash) ans++;
    }

    cout << ans << endl;

    return 0;
}