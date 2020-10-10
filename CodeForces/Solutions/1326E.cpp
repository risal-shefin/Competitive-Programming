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

const ll sz = 3e5 + 10;
ll pos[sz], q[sz], lazy[4*sz], tree[4*sz];

void prop(ll lo, ll hi, ll node)
{
    if(lo == hi) return;

    tree[node<<1] += lazy[node], tree[node<<1|1] += lazy[node];
    lazy[node<<1] += lazy[node], lazy[node<<1|1] += lazy[node];

    lazy[node] = 0;
}

void update(ll lo, ll hi, ll l, ll r, ll v, ll node)
{
    if(lazy[node]) prop(lo, hi, node);

    if(lo > r || hi < l)
        return;
    if(lo >= l && hi <= r) {
        tree[node] += v;
        lazy[node] += v;
        return;
    }

    ll mid = lo+hi >> 1;
    update(lo, mid, l, r, v, node<<1);
    update(mid+1, hi, l, r, v, node<<1|1);

    tree[node] = max(tree[node<<1], tree[node<<1|1]);
}

ll query(ll lo, ll hi, ll l, ll r, ll node)
{
    if(lazy[node]) prop(lo, hi, node);

    if(lo > r || hi < l)
        return -inf;
    if(lo >= l && hi <= r)
        return tree[node];

    ll mid = lo+hi >> 1;
    return max(query(lo, mid, l, r, node<<1),
               query(mid+1, hi, l, r, node<<1|1));
}

ll cost[sz];

int main()
{
    ll n;
    cin >> n;
    for1(i, n) {
        ll inp;
        sl(inp);
        pos[inp] = i;
    }

    for1(i, n) sl(q[i]);

    ll large = n;
    update(1, n, 1, pos[large], 1, 1);

    for1(i, n) {

        while(1) {
            ll ret = query(1, n, 1, n, 1);
            if(ret > 0) break;

            large--;
            update(1, n, 1, pos[large], 1, 1);
        }
        cost[i] = large;

        update(1, n, 1, q[i], -1, 1);
    }

    for1(i, n) {
        if(i != 1)
            pf(" ");

        pf("%lld", cost[i]);
    }
    pn;

    return 0;
}