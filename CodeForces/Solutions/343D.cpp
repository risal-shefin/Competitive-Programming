#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
ll n, TM = 0;
vector <ll> graph[500009];
ll f[2000009], e[2000009], lazy[2000009], st[500009], ft[500009];

void dfs(ll u, ll p)

{
    st[u] = ++TM;
    for(ll i = 0; i < graph[u].size(); i++) {
        ll nd = graph[u][i];
        if(nd == p)
            continue;

        dfs(nd, u);
    }

    ft[u] = TM;
}

void prop(ll lo, ll hi, ll node)

{
    if(lo == hi)
        return;

    lazy[2 * node] = lazy[node];
    lazy[2 * node + 1] = lazy[node];

    f[2 * node] = lazy[node];
    f[2 * node + 1] = lazy[node];

    lazy[node] = 0;
}

void update(ll lo, ll hi, ll left, ll right, ll val, ll node)

{
    if(lazy[node]) prop(lo, hi, node);

    if(lo > right || hi < left)
        return;

    if(lo >= left && hi <= right) {
        f[node] = val;
        lazy[node] = val;
        return;
    }

    ll mid = (lo + hi) / 2;
    update(lo, mid, left, right, val, 2 * node);
    update(mid + 1, hi, left, right, val, 2 * node + 1);

    f[node] = f[2 * node] + f[2 * node + 1];
}

void update2(ll lo, ll hi, ll indx, ll val, ll node)

{
    if(lo > indx || hi < indx)
        return;
    if(lo == hi) {
        e[node] = val;
        return;
    }

    ll mid = (lo + hi) / 2;
    update2(lo, mid, indx, val, 2 * node);
    update2(mid + 1, hi, indx, val, 2 * node + 1);

    e[node] = max(e[2 * node], e[2 * node + 1]);
}

ll query1(ll lo, ll hi, ll indx, ll node)

{
    if(lazy[node]) prop(lo, hi, node);

    if(lo > indx || hi < indx)
        return 0;
    if(lo == hi)
        return f[node];

    ll mid = (lo + hi) / 2;
    ll p1 = query1(lo, mid, indx, 2 * node);
    ll p2 = query1(mid + 1, hi, indx, 2 * node + 1);

    return max(p1, p2);
}

ll query2(ll lo, ll hi, ll left, ll right, ll node)

{
    if(lo > right || hi < left)
        return 0;

    if(lo >= left && hi <= right)
        return e[node];

    ll mid = (lo + hi) / 2;
    ll p1 = query2(lo, mid, left, right, 2 * node);
    ll p2 = query2(mid + 1, hi, left, right, 2 * node + 1);

    return max(p1, p2);
}

int main()

{
    cin >> n;
    for(ll i = 1; i < n; i++) {
        ll u, v;
        scanf("%lld %lld", &u, &v);
        graph[u].pb(v);
        graph[v].pb(u);
    }

    dfs(1, -1);

    ll q;
    cin >> q;
    for(ll i = 1; i <= q; i++) {
        ll type, v;
        scanf("%lld %lld", &type, &v);
        if(type == 1) {
            update(1, TM, st[v], ft[v], i, 1);
        }
        else if(type == 2) {
            update2(1, TM, st[v], i, 1);
        }
        else {
            ll p1 = query1(1, TM, st[v], 1);
            ll p2 = query2(1, TM, st[v], ft[v], 1);

            //cout << p1 << "  " << p2 << "  " << st[v] << " " << ft[v] << endl;

            if(p1 > p2) {
                printf("1\n");
            }
            else
                printf("0\n");
        }
    }

    return 0;
}