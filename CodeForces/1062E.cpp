#include <bits/stdc++.h>
using namespace std;
#define ll int
#define pll pair <ll, ll>
#define kom first
#define boro second
#define ln(node) (node << 1)
#define rn(node) ( (node << 1) | 1)
#define inf 1000000000
vector <ll> g[100009];
ll start[100009], stop[100009], TM = 0, id = 0;
ll ara[400009], nodeOf[100009], indexOf[100009], lev[100009];
pll maxmin[400009], treeTM2[400009];
ll treeTM[1600009];
void dfs(ll u, ll lv)
{
    start[u] = ++TM;
    nodeOf[TM] = u;
    ara[++id] = TM;
    indexOf[u] = id;
    lev[u] = lv;
    for(ll v: g[u]) {
        dfs(v, lv + 1);
        ara[++id] = start[u];
    }
    stop[u] = TM;
}
void buildmm(ll lo, ll hi, ll node)
{
    if(lo == hi) {
        maxmin[node] = make_pair(indexOf[lo], indexOf[lo]);
        return;
    }
    ll mid = (lo + hi) / 2;
    buildmm(lo, mid, 2 * node);
    buildmm(mid + 1, hi, 2 * node + 1);
    maxmin[node].kom = min(maxmin[ln(node)].kom, maxmin[rn(node)].kom);
    maxmin[node].boro = max(maxmin[ln(node)].boro, maxmin[rn(node)].boro);
}
pll querymm(ll lo, ll hi, ll left, ll right, ll node)
{
//    cout << lo << " " << hi << " " << left << "  " << right << endl;
    if(lo > right || hi < left)
        return pll(inf, -inf);
    if(lo >= left && hi <= right)
        return maxmin[node];
    ll mid = (lo + hi) / 2;
    pll p1 = querymm(lo, mid, left, right, ln(node));
    pll p2 = querymm(mid + 1, hi, left, right, rn(node));
    return pll(min(p1.kom, p2.kom), max(p1.boro, p2.boro));
}
void buildTM(ll lo, ll hi, ll node)
{
    if(lo == hi) {
        treeTM[node] = ara[lo];
        return;
    }
    ll mid = (lo + hi) / 2;
    buildTM(lo, mid, ln(node));
    buildTM(mid + 1, hi, rn(node));
    treeTM[node] = min(treeTM[ln(node)], treeTM[rn(node)]);
}
ll queryTM(ll lo, ll hi, ll left, ll right, ll node)
{
    if(lo > right || hi < left)
        return inf;
    if(lo >= left && hi <= right)
        return treeTM[node];
    ll mid = (lo + hi) / 2;
    ll p1 = queryTM(lo, mid, left, right, ln(node));
    ll p2 = queryTM(mid + 1, hi, left, right, rn(node));
    return min(p1, p2);
}
void buildTM2(ll lo, ll hi, ll node)
{
    if(lo == hi) {
        treeTM2[node] = pll(start[lo], start[lo]);
        return;
    }
    ll mid = (lo + hi) / 2;
    buildTM2(lo, mid, ln(node));
    buildTM2(mid + 1, hi, rn(node));
    treeTM2[node].kom = min(treeTM2[ln(node)].kom, treeTM2[rn(node)].kom);
    treeTM2[node].boro = max(treeTM2[ln(node)].boro, treeTM2[rn(node)].boro);
}
pll queryTM2(ll lo, ll hi, ll left, ll right, ll node)
{
    if(lo > right || hi < left)
        return pll(inf, -inf);
    if(lo >= left && hi <= right)
        return treeTM2[node];
    ll mid = (lo + hi) / 2;
    pll p1 = queryTM2(lo, mid, left, right, ln(node));
    pll p2 = queryTM2(mid + 1, hi, left, right, rn(node));
    return pll(min(p1.kom, p2.kom), max(p1.boro, p2.boro));
}
int main()
{
    ll n, q;
    cin >> n >> q;
    for(ll i = 2; i <= n; i++) {
        ll inp;
        scanf("%d", &inp);
        g[inp].push_back(i);
    }
    dfs(1, 0);
    buildmm(1, n, 1);
    buildTM2(1, n, 1);
    buildTM(1, id, 1);
    while(q--) {
        ll u, v, ansNode = 0;
        scanf("%d %d", &u, &v);
        pll p = querymm(1, n, u, v, 1);
//        cout << p.first << endl;
        ll lcaTM = queryTM(1, id, p.kom, p.boro, 1);
        ll lca = nodeOf[lcaTM], lcaLeft, lcaRight;
//        cout << lca << endl;
        pll p2 = queryTM2(1, n, u, v, 1);
        ll leftNode = nodeOf[p2.kom], rightNode = nodeOf[p2.boro];
        if(leftNode > rightNode)
            swap(leftNode, rightNode);
        if(leftNode == u) {
            pll p3 = querymm(1, n, u + 1, v, 1);
            ll lcaTM2 = queryTM(1, id, p3.kom, p3.boro, 1);
            lcaLeft = nodeOf[lcaTM2];
        }
        else {
            pll p4 = querymm(1, n, u, leftNode - 1, 1);
            pll p5 = querymm(1, n, leftNode + 1, v, 1);
            p4.kom = min(p4.kom, p5.kom), p4.boro = max(p4.boro, p5.boro);
            ll lcaTM2 = queryTM(1, id, p4.kom, p4.boro, 1);
            lcaLeft = nodeOf[lcaTM2];
        }
        if(rightNode == v) {
            pll p3 = querymm(1, n, u, v - 1, 1);
            ll lcaTM2 = queryTM(1, id, p3.kom, p3.boro, 1);
            lcaRight = nodeOf[lcaTM2];
        }
        else {
            pll p4 = querymm(1, n, u, rightNode - 1, 1);
            pll p5 = querymm(1, n, rightNode + 1, v, 1);
            p4.kom = min(p4.kom, p5.kom), p4.boro = max(p4.boro, p5.boro);
            ll lcaTM2 = queryTM(1, id, p4.kom, p4.boro, 1);
            lcaRight = nodeOf[lcaTM2];
        }
        if(lev[lcaLeft] > lev[lca]) {
            lca = lcaLeft;
            ansNode = leftNode;
        }
        if(lev[lcaRight] > lev[lca]) {
            lca = lcaRight;
            ansNode = rightNode;
        }
        printf("%d %d\n", ansNode==0?u:ansNode, lev[lca]);
    }
    return 0;
}
