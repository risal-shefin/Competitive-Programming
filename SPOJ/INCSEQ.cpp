#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 5000000

ll tree[52][400009];

void update(ll lo, ll hi, ll indx, ll node, ll val, ll len)

{
    if(lo > indx || hi < indx)
        return;
    if(lo == hi) {
        tree[len][node] += val;
        if(tree[len][node] > mod)
            tree[len][node] %= mod;
        return;
    }

    ll mid = (lo + hi) / 2;
    update(lo, mid, indx, 2 * node, val, len);
    update(mid + 1, hi, indx, 2 * node + 1, val, len);

    tree[len][node] = tree[len][2 * node] + tree[len][2 * node + 1];
    if(tree[len][node] > mod)
        tree[len][node] %= mod;
}

ll query(ll lo, ll hi, ll left, ll right, ll node, ll len)

{

    if(lo > right || hi < left)
        return 0;
    if(lo >= left && hi <= right)
        return tree[len][node];

    ll mid = (lo + hi) / 2;
    ll p1 = query(lo, mid, left, right, 2 * node, len);
    ll p2 = query(mid + 1, hi, left, right, 2 * node + 1, len);

    return (p1 + p2) % mod;
}

int main()

{
    ll n, k, ans = 0, in, ase;
    cin >> n >> k;
    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &in);
        in++;

        for(ll j = 1; j <= k; j++) {
            if(j == 1)
                ase = 1;
            else if(in == 1)
                ase = 0;
            else
                ase = query(1, 100001, 1, in - 1, 1, j - 1);

            update(1, 100001, in, 1, ase, j);

            if(j == k)
                ans = (ans + ase) % mod;
        }
    }

    printf("%lld\n", ans);

    return 0;
}
