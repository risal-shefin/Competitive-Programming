#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

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

ll a[2009], b[2009];

gp_hash_table <int, int, custom_hash> cnt, freq;
gp_hash_table <int, int, custom_hash> :: iterator it;

int main()

{
    ll n, m;
    cin >> n >> m;
    for1(i, n) {
        sl(a[i]);
        freq[a[i]]++;
    }
    for1(i, n)
        sl(b[i]);

    ll prv = -1;
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    for1(i, n) {

        if(prv == a[i])
            continue;

        ll f = freq[ a[i] ];
        prv = a[i];

        for(ll j = 1; j + f - 1 <= n; ) {
            ll diff = b[j] - a[i];
            if(diff < 0)
                diff += m;

            if(b[j] == b[j+f-1]) {
                cnt[diff] += f;
                j = j + f;
            }
            else
                j++;
        }
    }

    ll ans = inf;
    for(it = cnt.begin(); it != cnt.end(); it++) {
        if(it -> second != n)
            continue;

        ans = min(ans, (ll)it->first);
    }

    cout << ans << endl;

    return 0;
}