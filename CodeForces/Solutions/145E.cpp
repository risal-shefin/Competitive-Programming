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

const ll sz = 1e6 + 10;

char s[sz];

struct info {
    int fo, sev, inc, dec;
} tree[4*sz];

bool lazy[4*sz];

void build(ll lo, ll hi, ll node)
{
    if(lo == hi) {
        if(s[lo] == '4') tree[node].fo = 1;
        else tree[node].sev = 1;

        tree[node].inc = tree[node].dec = 1;
        return;
    }

    ll mid = lo+hi >> 1, l = node<<1, r = node<<1|1;

    build(lo, mid, l);
    build(mid+1, hi, r);

    tree[node].fo = tree[l].fo + tree[r].fo;
    tree[node].sev = tree[l].sev + tree[r].sev;

    tree[node].inc = max(tree[l].inc + tree[r].sev, tree[l].fo + tree[r].inc);
    tree[node].dec = max(tree[l].dec + tree[r].fo, tree[l].sev + tree[r].dec);
}

void prop(ll lo, ll hi, ll node)
{
    if(lo == hi) return;

    ll l = node << 1, r = node << 1 | 1;
    lazy[l] ^= 1, lazy[r] ^= 1;

    swap(tree[l].fo, tree[l].sev);
    swap(tree[l].inc, tree[l].dec);

    swap(tree[r].fo, tree[r].sev);
    swap(tree[r].inc, tree[r].dec);

    lazy[node] = 0;
}

void update(ll lo, ll hi, ll l, ll r, ll node)
{
    if(lo > r || hi < l) return;
    if(lo >= l && hi <= r) {
        swap(tree[node].fo, tree[node].sev);
        swap(tree[node].inc, tree[node].dec);

        lazy[node] ^= 1;
        return;
    }
    if(lazy[node]) prop(lo, hi, node);

    ll mid = lo+hi >> 1, lft = node<<1, rgt = node<<1 | 1;
    update(lo, mid, l, r, lft);
    update(mid+1, hi, l, r, rgt);

    tree[node].fo = tree[lft].fo + tree[rgt].fo;
    tree[node].sev = tree[lft].sev + tree[rgt].sev;

    tree[node].inc = max(tree[lft].inc + tree[rgt].sev, tree[lft].fo + tree[rgt].inc);
    tree[node].dec = max(tree[lft].dec + tree[rgt].fo, tree[lft].sev + tree[rgt].dec);
}

int main()
{
    ll n, m;
    cin >> n >> m;
    scanf("%s", s+1);

    build(1, n, 1);

    while(m--) {
        scanf("%s", s+1);

        if(s[1] == 'c')
            pf("%d\n", tree[1].inc);
        else {
            ll l, r;
            scanf("%lld %lld", &l, &r);
            update(1, n, l, r, 1);
        }
    }

    return 0;
}