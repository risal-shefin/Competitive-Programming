//Bob likes trees and XOR (Exclusive OR) very much. So he created a tree with each edge having a weight associated with it.
//One day his friend Alice came to his house, after playing video games for some time they got bored and decided to play something else.
//Bob showed the tree to Alice and told her that given any 2 vertices in the tree he can tell the XOR of all the weights on the unique path joining these 2 vertices.
//Alice thought it was a little easy and wanted to twist this a little bit. Now she proposed a different version involving q queries:
//
//Each query can be of 2 types.
//1 x y change the weight of xth edge to y.
//2 u v find the xor of the weights on the path joining vertices u and v.
//Can you help Bob solve this problem? For every query of 2nd type output the XOR value.

#include <bits/stdc++.h>
using namespace std;

#define siz 100009
#define ll int
#define pb push_back

vector <ll> graph[siz], cost[siz], edge[siz];
ll start[siz], stop[siz], TM = 1, tree1[8 * siz], tree2[8 * siz], to[siz], val[siz];

void dfs(ll n, ll p)

{

    start[n] = TM++;
    for(ll i = 0; i < graph[n].size(); i++) {
        if( graph[n][i] == p)
            continue;

        to[ edge[n][i] ] = graph[n][i];
        val[ graph[n][i] ] = cost[n][i];
        dfs(graph[n][i], n);
    }
    stop[n] = TM++;
}

void update1(ll lo, ll hi, ll indx, ll val, ll node)

{
    if(lo > indx || hi < indx)
        return;
    if(lo == indx && hi == indx) {
        tree1[node] = val;
        return;
    }

    ll mid = (lo + hi) / 2;
    update1(lo, mid, indx, val, 2 * node);
    update1(mid + 1, hi, indx, val, 2 * node + 1);

    tree1[node] = tree1[2 * node] ^ tree1[2 * node + 1];
}

void update2(ll lo, ll hi, ll indx, ll val, ll node)

{
    if(lo > indx || hi < indx)
        return;
    if(lo == indx && hi == indx) {
        tree2[node] = val;
        return;
    }

    ll mid = (lo + hi) / 2;
    update2(lo, mid, indx, val, 2 * node);
    update2(mid + 1, hi, indx, val, 2 * node + 1);

    tree2[node] = tree2[2 * node] ^ tree2[2 * node + 1];
}

ll query1(ll lo, ll hi, ll left, ll right, ll node)

{
    if(lo > right || hi < left)
        return 0;
    if(lo >= left && hi <= right)
        return tree1[node];

    ll mid = (lo + hi) / 2;
    ll p1 = query1(lo, mid, left, right, 2 * node);
    ll p2 = query1(mid + 1, hi, left, right, 2 * node + 1);

    return p1 ^ p2;
}

ll query2(ll lo, ll hi, ll left, ll right, ll node)

{
    if(lo > right || hi < left)
        return 0;
    if(lo >= left && hi <= right)
        return tree2[node];

    ll mid = (lo + hi) / 2;
    ll p1 = query2(lo, mid, left, right, 2 * node);
    ll p2 = query2(mid + 1, hi, left, right, 2 * node + 1);

    return p1 ^ p2;
}

int main()

{
    ll n;
    cin >> n;
    for(ll i = 1; i < n; i++) {
        ll u, v, w;
        scanf("%lld %lld %lld", &u, &v, &w);
        graph[u].pb(v);
        graph[v].pb(u);

        cost[u].pb(w);
        cost[v].pb(w);

        edge[u].pb(i);
        edge[v].pb(i);
    }

    dfs(1, -1);

    for(ll i = 1; i < n; i++) {
        update1(1, TM, start[ to[i] ], val[ to[i] ], 1);
        update2(1, TM, stop[ to[i] ], val[ to[i] ], 1);
    }

    ll q;
    cin >> q;
    for(ll i = 1; i <= q; i++) {
        ll state, u, v;
        scanf("%d %d %d", &state, &u, &v);
        if(state == 1) {
            update1(1, TM, start[ to[u] ], v, 1);
            update2(1, TM, stop[ to[u] ], v, 1);
        }
        else {
            ll ans = 0;
            ans ^= query1(1, TM, 1, start[u], 1);
            ans ^= query2(1, TM, 1, start[u], 1);

            ans ^= query1(1, TM, 1, start[v], 1);
            ans ^= query2(1, TM, 1, start[v], 1);

            printf("%d\n", ans);
        }
    }

    return 0;
}
