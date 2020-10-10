// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T>  using orderedSet =
	tree<T, null_type, less<T>,   /// greater<T> for sorting decreasingly
	rb_tree_tag, tree_order_statistics_node_update>;


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

const ll sz = 2e5 + 10;
ll tr[4*sz];

unordered_map <int, int> num;
vector <int> lst;

struct info {
    ll typ, d;
} ara[sz];

void update(ll lo, ll hi, ll idx, ll v, ll node)
{
    if(lo > idx || hi < idx)
        return;
    if(lo == hi) {
        tr[node] += v;
        return;
    }

    ll mid = lo+hi >>1, lft = node<<1, rgt=node<<1|1;

    update(lo, mid, idx, v, lft);
    update(mid+1, hi, idx, v, rgt);

    tr[node] = tr[lft] + tr[rgt];
}

ll query(ll lo, ll hi, ll l, ll r, ll node)
{
    if(lo > r || hi < l)
        return 0;
    if(lo >= l && hi <= r)
        return tr[node];

    ll mid = lo+hi>>1;

    return query(lo, mid, l, r, node<<1)
        +  query(mid+1, hi, l, r, node<<1 | 1);
}

orderedSet <int> spell, fire, light;

int main()
{
    ll n;
    cin >> n;

    for1(i, n) {
        sl(ara[i].typ), sl(ara[i].d);
        if(ara[i].d > 0)
            lst.pb(ara[i].d);
    }

    sort(all(lst));
    for0(i, lst.size()) num[ lst[i] ] = i+1;

    for1(i, n) {

        ll idx = num[ abs(ara[i].d) ];
        if(ara[i].d < 0) {
            update(1, lst.size(), idx, ara[i].d, 1);

            spell.erase(-ara[i].d);
            if(ara[i].typ == 0) fire.erase(-ara[i].d);
            else light.erase(-ara[i].d);
        }
        else {
            update(1, lst.size(), idx, ara[i].d, 1);

            spell.insert(ara[i].d);
            if(ara[i].typ == 0) fire.insert(ara[i].d);
            else light.insert(ara[i].d);
        }

        ll tot = tr[1];

        if(light.size() == 0) {
            pf("%lld\n", tot);
            continue;
        }

        ll more = light.size(), mn = *light.begin(), fir = -1;
        more--;

        if(!fire.empty()) {
            fir = *(--fire.end());
            tot += fir;
        }

        spell.erase(mn);
        update(1, lst.size(), num[mn], -mn, 1);
        if(fir != -1) {
            spell.erase(fir);
            update(1, lst.size(), num[fir], -fir, 1);
        }

        ll index = spell.size() - more;
        if(index < spell.size()) {
            ll val = *spell.find_by_order(index);

            tot += query(1, lst.size(), num[val], lst.size(), 1);
        }

        pf("%lld\n", tot);

        spell.insert(mn);
        update(1, lst.size(), num[mn], mn, 1);
        if(fir != -1) {
            spell.insert(fir);
            update(1, lst.size(), num[fir], fir, 1);
        }
    }

    return 0;
}