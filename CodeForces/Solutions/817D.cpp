#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

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
#define inf (1LL << 30)
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

#define mn first
#define mx second

const ll sz = 1e6 + 10;
pll t[4*sz];
ll ara[sz];

void build(ll lo, ll hi, ll node)
{
    if(lo == hi) {
        t[node] = {ara[lo], ara[lo]};
        return;
    }

    ll mid = lo + hi >> 1;
    build(lo, mid, node<<1);
    build(mid+1, hi, node<<1|1);

    t[node].mn = min(t[node<<1].mn, t[node<<1|1].mn);
    t[node].mx = max(t[node<<1].mx, t[node<<1|1].mx);
}

ll querymx1(ll lo, ll hi, ll l, ll r, ll v, ll node)
{
    if(lo > r || hi < l)
        return inf;
    if(lo == hi)
        return lo;

    ll mid = lo+hi >> 1, lft = node<<1, rgt = node<<1 | 1;

    ll ret = inf;
    if(t[rgt].mx > v)
        ret = querymx1(mid+1, hi, l, r, v, rgt);
    if(ret == inf && t[lft].mx > v)
        ret = querymx1(lo, mid, l, r, v, lft);

    return ret;
}

ll querymx2(ll lo, ll hi, ll l, ll r, ll v, ll node)
{
    if(lo > r || hi < l)
        return inf;
    if(lo == hi)
        return lo;

    ll mid = lo+hi >> 1, lft = node<<1, rgt = node<<1 | 1;

    ll ret = inf;
    if(t[lft].mx > v)
        ret = querymx2(lo, mid, l, r, v, lft);
    if(ret == inf && t[rgt].mx > v)
        ret = querymx2(mid+1, hi, l, r, v, rgt);

    return ret;
}

ll querymn1(ll lo, ll hi, ll l, ll r, ll v, ll node)
{
    if(lo > r || hi < l)
        return inf;
    if(lo == hi)
        return lo;

    ll mid = lo+hi >> 1, lft = node<<1, rgt = node<<1 | 1;

    ll ret = inf;
    if(t[rgt].mn < v)
        ret = querymn1(mid+1, hi, l, r, v, rgt);
    if(ret == inf && t[lft].mn < v)
        ret = querymn1(lo, mid, l, r, v, lft);

    return ret;
}

ll querymn2(ll lo, ll hi, ll l, ll r, ll v, ll node)
{
    if(lo > r || hi < l)
        return inf;
    if(lo == hi)
        return lo;

    ll mid = lo+hi >> 1, lft = node<<1, rgt = node<<1 | 1;

    ll ret = inf;
    if(t[lft].mn < v)
        ret = querymn2(lo, mid, l, r, v, lft);
    if(ret == inf && t[rgt].mn < v)
        ret = querymn2(mid+1, hi, l, r, v, rgt);

    return ret;
}

vector <ll> pos[sz];

int main()
{
    ll n;
    cin >> n;
    for1(i, n) {
        si(ara[i]);
        pos[ara[i]].pb(i);
    }

    build(1, n, 1);

    long long ans = 0;
    for(ll i = 1; i < sz; i++) {
        ll last = 0;
        for(ll &p : pos[i]) {

            ll lft = querymx1(1, n, last+1, p, i, 1);
            if(lft == inf) lft = last+1;
            else lft++;

            ll rgt = querymx2(1, n, p, n, i, 1);
            if(rgt == inf) rgt = n;
            else rgt--;

            ll leftIndex = p - lft + 1, rightIndex = rgt - p + 1;
            long long tot = (long long)leftIndex * rightIndex;
            ans += (tot * i);

            last = p;
        }
    }

    for(ll i = 1; i < sz; i++) {
        ll last = 0;
        for(ll &p : pos[i]) {

            ll lft = querymn1(1, n, last+1, p, i, 1);
            if(lft == inf) lft = last+1;
            else lft++;

            ll rgt = querymn2(1, n, p, n, i, 1);
            if(rgt == inf) rgt = n;
            else rgt--;

            ll leftIndex = p - lft + 1, rightIndex = rgt - p + 1;
            long long tot = (long long)leftIndex * rightIndex;
            ans -= (tot * i);

            last = p;
        }
    }
    cout << ans << endl;

    return 0;
}