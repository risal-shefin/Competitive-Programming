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
char s[sz];

struct info {
    ll b1, b2, ok;
} tree[4*sz];

void build(ll lo, ll hi, ll node)
{
    if(lo == hi) {

        if(s[lo] == '(') tree[node].b1 = 1;
        if(s[lo] == ')') tree[node].b2 = 1;

        return;
    }

    ll mid = lo+hi >> 1, lft = node<<1, rgt = lft|1;
    build(lo, mid, lft);
    build(mid+1, hi, rgt);

    tree[node].b1 = tree[lft].b1 + tree[rgt].b1;
    tree[node].b2 = tree[lft].b2 + tree[rgt].b2;

    ll extraLftB1 = tree[lft].b1 - tree[lft].ok;
    ll extraRgtB2 = tree[rgt].b2 - tree[rgt].ok;

    ll mn = min(extraLftB1, extraRgtB2);

    tree[node].ok = max(tree[lft].ok + tree[rgt].ok + mn, min(tree[lft].b1, tree[rgt].b2));
}

info query(ll lo, ll hi, ll l, ll r, ll node)
{
    if(lo > r || hi < l)
        return {0, 0, 0};
    if(lo >= l && hi <= r)
        return tree[node];

    ll mid = lo+hi >> 1, lft = node<<1, rgt = lft|1;

    info p1 = query(lo, mid, l, r, lft), now;
    info p2 = query(mid+1, hi, l, r, rgt);

    ll extraLftB1 = p1.b1 - p1.ok;
    ll extraRgtB2 = p2.b2 - p2.ok;

    ll mn = min(extraLftB1, extraRgtB2);

    now.b1 = p1.b1 + p2.b1;
    now.b2 = p1.b2 + p2.b2;
    now.ok = max(p1.ok + p2.ok + mn, min(p1.b1, p2.b2));

    return now;
}

int main()
{
    scanf("%s", s+1);

    ll len = strlen(s+1);
    build(1, len, 1);

    ll q; sl(q);

    while(q--) {
        ll l, r;
        sl(l), sl(r);

        pf("%lld\n", 2*query(1, len, l, r, 1).ok);
    }

    return 0;
}