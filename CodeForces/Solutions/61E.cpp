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
int ara[sz], num[sz];

ll tree[4*sz][2];

void update(ll lo, ll hi, ll idx, ll v, bool typ, ll node)
{
    if(lo > idx || hi < idx)
        return;
    if(lo == hi) {
        tree[node][typ] = v;
        return;
    }

    ll mid = lo+hi>>1, lft = node<<1, rgt = lft|1;

    update(lo, mid, idx, v, typ, lft);
    update(mid+1, hi, idx, v, typ, rgt);

    tree[node][typ] = tree[lft][typ] + tree[rgt][typ];
}

ll query(ll lo, ll hi, ll l, ll r, bool typ, ll node)
{
    if(lo > r || hi < l)
        return 0;
    if(lo >= l && hi <= r)
        return tree[node][typ];

    ll mid = lo+hi>>1, lft = node<<1, rgt = lft|1;

    return query(lo, mid, l, r, typ, lft)
        +  query(mid+1, hi, l, r, typ, rgt);
}

int main()
{
    ll n; sl(n);

    for1(i, n) {
        si(ara[i]);
        num[i] = ara[i];
    }
    sort(num+1, num+n+1);

    for1(i, n) ara[i] = lower_bound(num+1, num+n+1, ara[i]) - num;

    ll ans = 0, MAX_N = n+1;
    for1(i, n) {
        ans += query(1, MAX_N, ara[i]+1, MAX_N, 1, 1);

        ll f = query(1, MAX_N, ara[i]+1, MAX_N, 0, 1);
        update(1, MAX_N, ara[i], f, 1, 1);

        update(1, MAX_N, ara[i], 1, 0, 1);
    }

    cout << ans << EL;

    return 0;
}