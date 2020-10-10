#include <bits/stdc++.h>
using namespace std;

#define ll int
#define pll pair <ll, ll>

ll ara1[200009], ara2[200009], t1[800009], t2[800009];

void build(ll lo, ll hi, ll node)

{
    if(lo == hi) {
        t1[node] = ara1[lo];
        t2[node] = ara2[lo];
        return;
    }

    ll mid = (lo + hi) / 2;
    build(lo, mid, 2 * node);
    build(mid + 1, hi, 2 * node + 1);

    t1[node] = max(t1[2 * node], t1[2 * node + 1]);
    t2[node] = min(t2[2 * node], t2[2 * node + 1]);
}

pll query(ll lo, ll hi, ll left, ll right, ll node)

{
    if(lo > right || hi < left)
        return pll((ll)(-2e9), (ll)2e9);
    if(lo >= left && hi <= right)
        return pll(t1[node], t2[node]);

    ll mid = (lo + hi) / 2;
    pll p1 = query(lo, mid, left, right, 2 * node);
    pll p2 = query(mid + 1, hi, left, right, 2 * node + 1);

    return pll(max(p1.first, p2.first), min(p1.second, p2.second));
}

int main()

{
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++)
        scanf("%d", &ara1[i]);

    for(ll i = 1; i <= n; i++)
        scanf("%d", &ara2[i]);

    build(1, n, 1);

    long long ans = 0;
    for(ll i = 1; i <= n; i++) {
        ll f = 0, s = 0;

        ll lo = i, hi = n;
        while(lo <= hi) {
            ll mid = (lo + hi) / 2;
            pll p = query(1, n, i, mid, 1);

            if(p.first > p.second)
                hi = mid - 1;
            else if(p.first < p.second)
                lo = mid + 1;
            else if(p.first == p.second) {
                hi = mid - 1;
                f = mid;
            }
        }

        lo = i, hi = n;
        while(lo <= hi) {
            ll mid = (lo + hi) / 2;
            pll p = query(1, n, i, mid, 1);

            if(p.first > p.second)
                hi = mid - 1;
            else if(p.first < p.second)
                lo = mid + 1;
            else if(p.first == p.second) {
                lo = mid + 1;
                s = mid;
            }
        }

        if(f != 0 && s != 0)
            ans += (s - f + 1);
    }

    cout << ans << endl;

    return 0;
}