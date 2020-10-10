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

const ll sz = 1e5 + 10;
ll ara[sz], cnt[30][sz], csum[30][sz];

struct query {
    ll l, r, q;
} Q[sz];

int main()
{
    ll n, q;
    cin >> n >> q;
    for1(i, q) {
        sl(Q[i].l), sl(Q[i].r), sl(Q[i].q);

        rep0(j, 30) {
            bool bt = (Q[i].q >> j) & 1;
            if(bt)
                cnt[j][Q[i].l]++, cnt[j][Q[i].r+1]--;
        }
    }

    for1(i, n) {
        rep0(j, 30) {
            cnt[j][i] += cnt[j][i-1];
            csum[j][i] += csum[j][i-1];

            if(cnt[j][i]) {
                ara[i] |= (1 << j);
                csum[j][i]++;
            }
        }
    }

    bool ok = 1;
    for1(i, q) {
        rep0(j, 30) {
            bool bt = (Q[i].q >> j) & 1;
            if(bt) continue;

            ll one = csum[j][Q[i].r] - csum[j][Q[i].l - 1];
            if(one == (Q[i].r - Q[i].l + 1))
                ok = 0;
        }
    }

    if(!ok) cout << "NO" << EL;
    else {
        cout << "YES" << EL;
        for1(i, n) {
            if(i != 1) pf(" ");
            pf("%lld", ara[i]);
        }
        pn;
    }

    return 0;
}