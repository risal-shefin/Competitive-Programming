#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll tree[400009], lazy[400009], last[100009], ans[100009], ara[100009];

struct query {
    ll l, r, id;
} qry[100009];

bool cmp(query a, query b)

{
    return a.r < b.r;
}

void prop(ll lo, ll hi, ll node)

{
    if(lo == hi)
        return;

    tree[2 * node] += lazy[node];
    tree[2 * node + 1] += lazy[node];

    lazy[2 * node] += lazy[node];
    lazy[2 * node + 1] += lazy[node];

    lazy[node] = 0;
}

void update(ll lo, ll hi, ll left, ll right, ll node)

{
    if(lazy[node]) prop(lo, hi, node);

    if(lo > right || hi < left)
        return;
    if(lo >= left && hi <= right) {
        tree[node]++;
        lazy[node]++;
        return;
    }

    ll mid = (lo + hi) / 2;
    update(lo, mid, left, right, 2 * node);
    update(mid + 1, hi, left, right, 2 * node + 1);

    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}

ll query(ll lo, ll hi, ll left, ll right, ll node)

{
    if(lazy[node]) prop(lo, hi, node);

    if(lo > right || hi < left)
        return 0;

    if(lo >= left && hi <= right)
        return tree[node];

    ll mid = (lo + hi) / 2;
    ll p1 = query(lo, mid, left, right, 2 * node);
    ll p2 = query(mid + 1, hi, left, right, 2 * node + 1);

    return max(p1, p2);
}

bool mark[100009];

int main()

{
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++)
        scanf("%lld", &ara[i]);

    for(ll i = 1; i < n; i++)
    {
        qry[i].l = i + 1, qry[i].r = n;
        qry[i].id = i;
    }

    //sort(qry + 1, qry + q + 1, cmp);
    ll indx = 1, me = 0;
    for(ll i = 1; i <= n; i++)
    {
        update(1, n, last[ ara[i] ] + 1, i, 1);
        last[ ara[i] ] = i;

        while(indx <= n && qry[indx].r == i)
        {
            ans[ qry[indx].id ] = query(1, n, qry[indx].l, qry[indx].r, 1);
            ll tmpa = ans[ qry[indx].id ];
            ll left = qry[indx].l - 1;
            if(mark[ ara[left] ] == 1) {
                indx++;
                continue;
            }
            mark[ ara[left] ] = 1;
            //cout << left << "  " << ara[left] << endl;
            me += tmpa;
            indx++;
        }
    }

    cout << me << endl;

    return 0;
}