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
#define fastio std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const ll sz = 2e5 + 10;

struct tre {
    ll now, sum;
} tree[4*sz];

struct laz {
    ll v, ad;
} lazy[4*sz];

void prop(ll lo, ll hi, ll node)
{
    if(lo == hi)    return;

    ll mid = lo+hi >> 1, l = node<<1, r = node<<1|1;

    tree[l] = {lazy[node].v, tree[l].sum + lazy[node].ad*(mid-lo+1) };
    tree[r] = {lazy[node].v, tree[r].sum + lazy[node].ad*(hi-mid) };

    lazy[l] = {lazy[node].v, lazy[l].ad+lazy[node].ad};
    lazy[r] = {lazy[node].v, lazy[r].ad+lazy[node].ad};

    lazy[node] = {-1, 0};
}

void build(ll lo, ll hi, ll node)
{
    if(lo == hi) {
        tree[node] = {lo, 0};
        lazy[node] = {-1, 0};
        return;
    }

    ll mid = lo+hi >> 1;
    build(lo, mid, node<<1);
    build(mid+1, hi, node << 1 | 1);

    tree[node] = {-1, 0};
    lazy[node] = {-1, 0};
}

void update(ll lo, ll hi, ll l, ll r, ll v, ll node)
{
    if(lazy[node].v != -1) prop(lo, hi, node);

    if(lo > r || hi < l)
        return;
    if(lo >= l && hi <= r && tree[node].now != -1) {

        ll d = abs(tree[node].now - v);
        tree[node] = {v, tree[node].sum + d*(hi-lo+1)};
        lazy[node] = {v, lazy[node].ad + d};

        return;
    }

    ll mid = lo+hi >> 1;
    update(lo, mid, l, r, v, node<<1);
    update(mid+1, hi, l, r, v, node<<1 | 1);

    if(tree[node<<1].now == tree[node<<1|1].now)
        tree[node].now = tree[node<<1].now;
    else
        tree[node].now = -1;

    tree[node].sum = tree[(node<<1)].sum + tree[(node<<1|1)].sum;
}

ll query(ll lo, ll hi, ll l, ll r, ll node)
{
    if(lazy[node].v != -1) prop(lo, hi, node);

    if(lo > r || hi < l)
        return 0;
    if(lo >= l && hi <= r)
        return tree[node].sum;

    ll mid = (lo+hi)>>1;
    return query(lo, mid, l, r, node<<1)
        +  query(mid + 1, hi, l, r, node<<1|1);
}

int main()
{
    ll n, q;
    cin >> n >> q;

    build(1, n, 1);
    while(q--) {
        ll typ, l, r;
        sl(typ), sl(l), sl(r);

        if(typ == 1) {
            ll v; sl(v);

            update(1, n, l, r, v, 1);
        }
        else
            pf("%lld\n", query(1, n, l, r, 1));
    }

    return 0;
}