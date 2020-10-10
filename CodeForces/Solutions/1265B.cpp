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
#define forn(i, stop) for(ll i = 1; i <= stop; i++)
#define rep(i, start) for(ll i = start; i >= 1; i--)
#define ms(n, i) memset(n, i, sizeof(n))
#define casep(n) printf("Case %lld:", ++n)
#define pn printf("\n")
#define pf printf
#define fastio std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
ll ara[200009];
ll tree[800009];
bitset <200009> check;
 
void build(ll lo, ll hi, ll node) {
    if(lo == hi) {
        tree[node] = 0;
        return;
    }
 
    ll mid = (lo + hi) / 2;
    build(lo, mid, 2*node);
    build(mid+1, hi, 2*node+1);
 
    tree[node] = 0;
}
 
void update(ll lo, ll hi, ll idx, ll node) {
    if(lo > idx || hi < idx)
        return;
    if(lo == hi) {
        tree[node] = ara[idx];
        return;
    }
 
    ll mid = (lo+hi) / 2;
    update(lo, mid, idx, 2*node);
    update(mid+1, hi, idx, 2*node+1);
 
    tree[node] = min(tree[2*node], tree[2*node + 1]);
}
 
ll query1(ll lo, ll hi, ll left, ll right, ll v, ll node) {
    if(lo > right || hi < left)
        return inf;
    if(lo == hi)
        return lo;
 
    ll mid = (lo + hi) / 2, p = inf;
//
//    if(v == 3)
//        cout << lo << " " << hi << " " << tree[node] << endl;
 
    if(tree[2*node+1] < v)
        p = query1(mid+1, hi, left, right, v, 2*node+1);
 
    if(p == inf && tree[2*node] < v)
        p = query1(lo, mid, left, right, v, 2*node);
 
    return p;
}
 
ll query2(ll lo, ll hi, ll left, ll right, ll v, ll node) {
    if(lo > right || hi < left)
        return inf;
    if(lo == hi)
        return lo;
 
    ll mid = (lo + hi) / 2, p = inf;
//
//    if(v == 3)
//        cout << lo << " " << hi << " " << tree[node] << endl;
 
    if(tree[2*node] < v)
        p = query2(lo, mid, left, right, v, 2*node);
 
    if(p == inf && tree[2*node+1] < v)
        p = query2(mid+1, hi, left, right, v, 2*node+1);
 
    return p;
}
 
int main()
 
{
    ll t;
    sl(t);
    while(t--) {
        check.reset();
        ll n, mx = 0;
        sl(n);
        build(1, n, 1);
 
        forn(i, n) {
            sl(ara[i]);
            update(1, n, i, 1);
        }
 
        forn(i, n) {
            if(ara[i] == 1) {
                check[1] = 1;
                continue;
            }
 
            ll ret1 = query2(1, n, 1, i-1, ara[i], 1);
            ll ret2 = query1(1, n, i+1, n, ara[i], 1);
//
//            if(i == 3)
//                cout << ret1 << " " << ret2 << endl;
 
            ll tot = 1;
            if(ret1 != inf)
                tot += (i - ret1);
            if(ret2 != inf)
                tot += (ret2 - i);
 
            //cout << tot << endl;
            if(tot == ara[i])
                check[ara[i]] = 1;
        }
 
        forn(i, n) {
            ll ans = check[i];
            pf("%lld", ans);
        }
        pn;
    }
 
    return 0;
}