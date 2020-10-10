#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair <ll, ll>

ll ara[200009], ans[200009], ptree[800009];

struct node {
    ll k, pos, id;
} qry[200009];

bool operator <(const node &a, const node &b) {
    return a.k < b.k;
}

struct info {
    ll val, idx;
} num[200009];

bool operator <(const info &a, const info &b) {
    if(a.val == b.val)
        return a.idx < b.idx;
    return a.val > b.val;
}

void update(ll lo, ll hi, ll idx, ll node)

{
    if(lo > idx || hi < idx)
        return;
    if(lo == hi) {
        ptree[node]++;
        return;
    }

    ll mid = (lo + hi) / 2;
    update(lo, mid, idx, 2*node);
    update(mid+1, hi, idx,2*node + 1);

    ptree[node] = ptree[2*node] + ptree[2*node + 1];
}

ll query(ll lo, ll hi, ll k, ll node)

{
    if(lo == hi)
        return lo;

    ll mid = (lo + hi) / 2;
    if(ptree[2*node] >= k)
        return query(lo, mid, k, 2*node);

    return query(mid+1, hi, k - ptree[2*node], 2*node + 1);
}

int main()

{
    ll n, id = 1;
    cin >> n;
    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &ara[i]);
        num[i] = {ara[i], i};
    }
    sort(num + 1, num + n + 1);

    ll q;
    cin >> q;
    for(ll i = 1; i <= q; i++) {
        scanf("%lld %lld", &qry[i].k, &qry[i].pos);
        qry[i].id = i;
    }
    sort(qry + 1, qry + q + 1);

    ll sz = 0;
    for(ll i = 1; i <= q; i++) {

        ll k = qry[i].k, p = qry[i].pos;
        while(sz < k) {
            sz++;
            update(1, n, num[sz].idx, 1);
        }

        ans[qry[i].id] = ara[query(1, n, p, 1)];
    }

    for(ll i = 1; i <= q; i++)
        printf("%lld\n", ans[i]);

    return 0;
}