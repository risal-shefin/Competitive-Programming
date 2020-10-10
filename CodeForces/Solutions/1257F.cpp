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

const ll sz = 102, ad = 40;
ll n;
int ara[sz], cnt[sz], ans = -1;
int half = (1<<15) - 1, half2 = ~half;
unordered_map <ll, ll> hsh;

const ll MAX_N = 110, mod = 2e9+63, base1 = 1e9+21, base2 = 1e9+181;
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

inline int bitcount(int num) {
    int cnt = 0;
    while(num) num &= (num-1), cnt++;
    return cnt;
}

void solve1(int x, int pos)
{
    if(pos == 15) {
        for1(i, n) {
            int v = ara[i] & half;
            int xr = v ^ x;
            cnt[i] = bitcount(xr);
        }

        for(ll i = 1; i < n; i++) s[i] = (cnt[i] - cnt[i+1]) + ad;
        slen = n;
        fw.init();
        hsh[ fw.hashVal(1, n) ] = x;

        return;
    }

    solve1(x, pos+1);
    solve1(x | (1<<pos), pos+1);
}

void solve2(int x, int pos)
{
    if(ans != -1) return;

    if(pos == 30) {
        for1(i, n) {
            int v = ara[i] & half2;
            int xr = v ^ x;
            cnt[i] = bitcount(xr);
        }

        for(ll i = 1; i < n; i++) s[i] = (cnt[i+1] - cnt[i]) + ad;
        slen = n;
        fw.init();
        auto it = hsh.find(fw.hashVal(1, n));
        if(it != hsh.end()) {
            //cout << (it->second) << " " << i << " " << x << " " << (ll)s[1] << " " << (ll)s[2] << endl;
            ans = x | (it->second);
        }

        return;
    }

    solve2(x, pos+1);
    solve2(x | (1<<pos), pos+1);
}

int main()
{
    pw_calc();

    cin >> n;
    for1(i, n) si(ara[i]);

    solve1(0, 0);
    solve2(0, 15);

    cout << ans << endl;

    return 0;
}