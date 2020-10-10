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

vector <ll> g[2009];
ll small[2009], sub[2009], root, val[2009];
orderedSet <ll> lst;

void subdfs(ll u)
{
    for(ll v: g[u]){
        subdfs(v);
        sub[u] += sub[v] + 1;
    }
}

void dfs(ll u)
{
    if(small[u] > sub[u]) {
        val[u] = -1;
        return;
    }
    auto it = lst.find_by_order(small[u]);
    val[u] = *it;
    lst.erase(it);

    for(ll v: g[u])
        dfs(v);
}

int main()

{
    ll n;
    sl(n);
    for1(i, n) {
        lst.insert(i);
        ll p, c;
        sl(p), sl(c);

        small[i] = c;
        if(p == 0) {
            root = i;
            continue;
        }

        g[p].pb(i);
    }

    subdfs(root);

    dfs(root);

    bool chk = 1;
    for1(i, n) {
        if(val[i] <= 0)
            chk = 0;
    }

    if(!chk)
        pf("NO\n");
    else {
        pf("YES\n");
        for1(i, n) {
            if(i != 1)
                pf(" ");
            pf("%lld", val[i]);
        }
        pn;
    }

    return 0;
}