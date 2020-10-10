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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll hasZeroBit[12];
unordered_set <ll> found;

inline ll gen_random(ll l, ll r) {
    return uniform_int_distribution<ll>(l, r)(rng);
}

inline ll ask(ll i, ll j) {
    cout << "? " << i << " " << j << endl;
    ll ret; cin >> ret;
    return ret;
}

inline get_exact_val(ll i)
{
    ll ret = 0;
    for(ll bt = 11; bt >= 0; bt--) {
        if(hasZeroBit[bt] == i)
            continue;

        ll got = ask(i, hasZeroBit[bt]);
        if((got >> bt) & 1) ret |= (1LL << bt);
    }
    return ret;
}

ll ans[2050];

int main()
{
    fastio;
    ll n;
    cin >> n;

    while(found.size() != 12) {
        ll i = gen_random(1, n), j = gen_random(1, n);
        if(i == j) continue;

        ll got = ask(i, j);
        for(ll bt = 11; bt >= 0; bt--) {
            if((got >> bt) & 1)
                continue;

            hasZeroBit[bt] = i;
            found.insert(bt);
        }
    }

    ll zero_id = 1, num = get_exact_val(zero_id);
    for(ll i = 2; i <= n; i++) {
        ll got = ask(zero_id, i);
        if(got == num) {
            zero_id = i;
            num = get_exact_val(i);
        }
    }

    ans[zero_id] = 0;
    for1(i, n) {
        if(i == zero_id)
            continue;

        ans[i] = ask(i, zero_id);
    }

    cout << "!";
    for1(i, n) cout << " " << ans[i];
    cout << endl;

    return 0;
}