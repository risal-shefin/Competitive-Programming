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

const ll sz = 1e5 + 10, offset = 1e5;
set <int> row[sz], col[sz], rcAdd[2*sz], rcSub[2*sz];

struct queen {
    int r, c;
} ara[sz];

ll cnt[10];

int main()
{
    ll n, m;
    cin >> n >> m;

    for1(i, m) {
        si(ara[i].r), si(ara[i].c);

        row[ara[i].r].insert(ara[i].c);
        col[ara[i].c].insert(ara[i].r);

        ll sum = ara[i].r+ara[i].c, sub = ara[i].r-ara[i].c;

        rcAdd[sum].insert(ara[i].r);
        rcSub[sub+offset].insert(ara[i].r);
    }

    for1(i, m) {

        ll r = ara[i].r, c = ara[i].c, sum = r+c, sub = r-c, attack = 0;

        attack += (c != *(--row[r].end()) );
        attack += (c != *row[r].begin());

        attack += (r != *(--col[c].end()) );
        attack += (r != *col[c].begin());

        attack += (r != *(--rcAdd[sum].end()) );
        attack += (r != *rcAdd[sum].begin());

        attack += (r != *(--rcSub[sub+offset].end()) );
        attack += (r != *rcSub[sub+offset].begin());

        cnt[attack]++;
    }

    for(ll i = 0; i <= 8; i++) {
        if(i != 0) pf(" ");
        pf("%lld", cnt[i]);
    }
    pn;

    return 0;
}