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

const ll MAX_N = 1e6+10, mod = 2e9+63, base1 = 1e9+21, base2 = 1e9+181;
char s[MAX_N];  // 1-indexed
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

ll subPre;

inline ll preExist(ll &l, ll &r)
{
    ll pre = fw.hashVal(1, r-l+1), hsh = fw.hashVal(l, r);
    return pre == hsh;
}

int main()
{
    scanf("%s", s+1);
    slen = strlen(s+1);

    pw_calc();
    fw.init();

    for(ll i = 2; i < slen; i++) {
        ll lo = i, hi = slen-1;
        while(lo <= hi) {
            ll mid = (lo+hi) >> 1;

            if(preExist(i, mid)) {
                subPre = max(subPre, mid-i+1);
                lo = mid + 1;
            }
            else
                hi = mid - 1;
        }
    }

    ll start = -1;
    for1(i, slen) {
        ll len = slen-i+1;
        if(len > subPre)
            continue;

        ll pre = fw.hashVal(1, len), suf = fw.hashVal(i, slen);
        if(pre == suf) {
            start = i;
            break;
        }
    }

    if(start == -1) pf("Just a legend");
    else
        for(ll i = start; i <= slen; i++) pf("%c", s[i]);

    pn;

    return 0;
}