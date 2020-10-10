// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;

#define ll int
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

const ll sz = 3e4+10, nsz = 1e4+5, block = sqrtl(sz*14);
ll ara[sz], tree[4*nsz][sz/block + 5];

void update(ll lo, ll hi, ll idx, ll v, ll b, ll node)
{
    if(lo > idx || hi < idx)
        return;
    if(lo == hi) {
        tree[node][b] += v;
        return;
    }

    ll mid = lo+hi>>1, lft = node<<1, rgt = lft|1;
    update(lo, mid, idx, v, b, lft);
    update(mid+1, hi, idx, v, b, rgt);

    tree[node][b] = tree[lft][b] + tree[rgt][b];
}

ll query(ll lo, ll hi, ll l, ll r, ll b, ll node)
{
    if(lo > r || hi < l)
        return 0;
    if(lo >= l && hi <= r)
        return tree[node][b];

    ll mid = lo+hi >> 1;
    return query(lo, mid, l, r, b, node<<1)
        +  query(mid+1, hi, l, r, b, node<<1|1);
}

ll query_block(ll l, ll r, ll k)
{
    ll lb = l / block, rb = r / block, ret = 0;

    if(lb == rb) {
        for(ll i = l; i <= r; i++)
            ret += (ara[i] > k);

        return ret;
    }

    for(ll i = l; i < (lb+1)*block; i++)
        ret += (ara[i] > k);

    for(ll i = lb+1; i < rb; i++)
        ret += query(1, nsz, k+1, nsz, i, 1);

    for(ll i = rb*block; i <= r; i++)
        ret += (ara[i] > k);

    return ret;
}

int main()
{
    ll n;
    cin >> n;
    for0(i, n) {
        si(ara[i]);

        ll b = i / block;
        update(1, nsz, ara[i], 1, b, 1);
    }

    ll q;
    cin >> q;
    while(q--) {

        ll op, l, r, k;
        si(op);

        if(op == 1) {
            scanf("%d %d %d", &l, &r, &k);
            l--, r--;

            pf("%d\n", query_block(l, r, k));
        }
        else {
            scanf("%d %d", &l, &k);
            l--;

            ll prv = ara[l];
            ara[l] = k;

            update(1, nsz, prv, -1, l/block, 1);
            update(1, nsz, ara[l], 1, l/block, 1);
        }
    }

    return 0;
}

