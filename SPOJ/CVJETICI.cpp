#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll ltree[400009], rtree[400009], trace[100009];

void update(ll lo, ll hi, ll indx, ll state, ll node)

{
    if(lo > indx || hi < indx)
        return;
    if(lo == hi) {
        if(state)
            rtree[node]++;
        else
            ltree[node]++;

        return;
    }

    ll mid = (lo + hi) / 2;
    update(lo, mid, indx, state, 2 * node);
    update(mid + 1, hi, indx, state, 2 * node + 1);

    if(state)
        rtree[node] = rtree[2 * node] + rtree[2 * node + 1];
    else
        ltree[node] = ltree[2 * node] + ltree[2 * node + 1];
}

ll query(ll lo, ll hi, ll left, ll right, ll state, ll node)

{
    if(left > right)
        return 0;
    if(lo > right || hi < left)
        return 0;
    if(lo >= left && hi <= right)
        if(state)
            return rtree[node];
        else
            return ltree[node];

    ll mid = (lo + hi) / 2;
    ll p1 = query(lo, mid, left, right, state, 2 * node);
    ll p2 = query(mid + 1, hi, left, right, state, 2 * node + 1);

    return p1 + p2;
}

int main()

{
    ll n;
    cin >> n;
    while(n--) {
        ll x1, x2, ans = 0;
        scanf("%lld %lld", &x1, &x2);
        ll cnt1 = query(1, 100000, 1, x1 - 1, 0, 1);
        ll cnt2 = query(1, 100000, 1, x1, 1, 1);
        ll cnt = cnt1 - cnt2 - trace[x1];
        trace[x1] += cnt;
        ans += cnt;

        cnt1 = query(1, 100000, 1, x2 - 1, 0, 1);
        cnt2 = query(1, 100000, 1, x2, 1, 1);
        cnt = cnt1 - cnt2 - trace[x2];
        trace[x2] += cnt;
        ans += cnt;

        printf("%lld\n", ans);

        update(1, 100000, x1, 0, 1);
        update(1, 100000, x2, 1, 1);
    }

    return 0;
}
