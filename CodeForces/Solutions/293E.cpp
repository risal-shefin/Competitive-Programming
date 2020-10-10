#include <bits/stdc++.h>
using namespace std;

/// decompose(1, -1)   //For 1 rooted tree

#define ll long long
#define pb push_back
const ll MAX = 1e5;
vector <ll> g[MAX + 9], c[MAX + 9];
ll del[MAX + 9], sz[MAX + 9], par[MAX + 9], curSize, L, W, ans = 0;
ll BITree[MAX + 9], BITree2[MAX + 9];

struct node {
    ll t, l, w;
};

bool cmp(node a, node b)

{
    if(a.w == b.w)
        return a.t < b.t;

    return a.w < b.w;
}

vector <node> v, inpath;

///do this for range: getSum(r) - getSum(l - 1)
ll getSum(ll index)
{
    ll sum = 0; // Iniialize result

    // Traverse ancestors of BITree[index]
    while (index>0)
    {
        // Add current element of BITree to sum
        sum += BITree[index];

        // Move index to parent node in getSum View
        index -= index & (-index);
    }
    return sum;
}

void updateBIT(ll n, ll index, ll val)

{

    // Traverse all ancestors and add 'val'
    while (index <= n)
    {
       // Add 'val' to current node of BI Tree
       BITree[index] += val;

       // Update index to that of parent in update View
       index += index & (-index);
    }
}

ll getSum2(ll index)
{
    ll sum = 0; // Iniialize result

    // Traverse ancestors of BITree[index]
    while (index>0)
    {
        // Add current element of BITree to sum
        sum += BITree2[index];

        // Move index to parent node in getSum View
        index -= index & (-index);
    }
    return sum;
}

void updateBIT2(ll n, ll index, ll val)

{

    // Traverse all ancestors and add 'val'
    while (index <= n)
    {
       // Add 'val' to current node of BI Tree
       BITree2[index] += val;

       // Update index to that of parent in update View
       index += index & (-index);
    }
}


void dfs(ll u, ll p)

{
    sz[u] = 1;
    for(ll i = 0; i < g[u].size(); i++) {
        ll nd = g[u][i];
        if(nd == p || del[nd])
            continue;
        dfs(nd, u);
        sz[u] += sz[nd];
    }
}

ll findCentroid(ll u, ll p)

{
    for(ll i = 0; i < g[u].size(); i++) {
        ll nd = g[u][i];
        if(nd == p || del[nd] || sz[nd] <= curSize / 2)
            continue;

        return findCentroid(nd, u);
    }
    return u;
}

void adfs(ll u, ll p, ll d, ll w)

{
    v.pb({0, d, w});
    inpath.pb({0, d, w});
    if(d <= L && w <= W) {
        v.pb({1, L - d, W - w});
        inpath.pb({1, L - d, W - w});
        ans++;
    }

    for(ll i = 0; i < g[u].size(); i++) {
        ll nd = g[u][i], cst = c[u][i];
        if(nd == p || del[nd])
            continue;

        adfs(nd, u, d + 1, w + cst);
    }
}

void decompose(ll u, ll p)

{
    dfs(u, -1);
    curSize = sz[u];
    ll cen = findCentroid(u, -1);
    if(p == -1) p = cen;
    par[cen] = p, del[cen] = 1;

    ll tominus = 0, toadd = 0;
    for(ll i = 0; i < g[cen].size(); i++) {
        ll nd = g[cen][i], cst = c[cen][i];
        if(del[nd])
            continue;

        inpath.clear();

        adfs(nd, cen, 1, cst);

        sort(inpath.begin(), inpath.end(), cmp);
        for(ll j = 0; j < inpath.size(); j++) {
            if(inpath[j].t == 1)
                tominus += getSum2(inpath[j].l + 1);
            else
                updateBIT2(MAX + 5, inpath[j].l + 1, 1);
        }

        for(ll j = 0; j < inpath.size(); j++)
            if(inpath[j].t == 0)
                updateBIT2(MAX + 5, inpath[j].l + 1, -1);

    }

    sort(v.begin(), v.end(),  cmp);

    for(ll i = 0; i < v.size(); i++) {
        if(v[i].t == 1)
            toadd += getSum(v[i].l + 1);
        else
            updateBIT(MAX + 5, v[i].l + 1, 1);
    }

    toadd -= tominus;
    ans += (toadd / 2);

    for(ll i = 0; i < v.size(); i++) {
        if(v[i].t == 0)
            updateBIT(MAX + 5, v[i].l + 1, -1);
    }
    v.clear();

    for(ll i = 0; i < g[cen].size(); i++) {
        ll nd = g[cen][i];

        if(!del[nd])
            decompose(nd, cen);
    }
}

int main()

{
    ll n;
    cin >> n >> L >> W;

    for(ll i = 1; i < n; i++) {
        ll u, w;
        scanf("%lld %lld", &u, &w);;
        g[u].pb(i + 1);
        g[i + 1].pb(u);

        c[i + 1].pb(w);
        c[u].pb(w);
    }

    decompose(1, -1);

    cout << ans << endl;

    return 0;
}