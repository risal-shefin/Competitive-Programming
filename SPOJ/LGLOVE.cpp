#include <bits/stdc++.h>
using namespace std;

#define siz 300000
#define mod 1000000007
#define ll long long
ll ara[100009], mtree[300009], xtree[300009], lazy[300009], mul[siz + 9], indx = 0;
vector <ll> prime;
bool mark[siz + 9];

void propagate(ll lo, ll hi, ll node)

{
    if(lo == hi)
        return;

    lazy[2 * node] += lazy[node];
    lazy[2 * node + 1] += lazy[node];

    mtree[2 * node] += lazy[node];
    mtree[2 * node + 1] += lazy[node];

    xtree[2 * node] += lazy[node];
    xtree[2 * node + 1] += lazy[node];
    lazy[node] = 0;
}

void build(ll lo, ll hi, ll node)

{
    if(lo == hi) {
        mtree[node] = ara[lo];
        xtree[node] = ara[lo];
        return;
    }

    ll mid = (lo + hi) / 2;
    build(lo, mid, 2 * node);
    build(mid + 1, hi, 2 * node + 1);

    mtree[node] = min(mtree[2 * node], mtree[2 * node + 1]);
    xtree[node] = max(xtree[2 * node], xtree[2 * node + 1]);
}

void update(ll lo, ll hi, ll left, ll right, ll val, ll node)

{
    if(lazy[node]) propagate(lo, hi, node);
    if(lo > right || hi < left)
        return;
    if(lo >= left && hi <= right) {
        lazy[node] += val;
        mtree[node] += val;
        xtree[node] += val;
        return;
    }

    ll mid = (lo + hi) / 2;
    update(lo, mid, left, right, val, 2 * node);
    update(mid + 1, hi, left, right, val, 2 * node + 1);

    mtree[node] = min(mtree[2 * node], mtree[2 * node + 1]);
    xtree[node] = max(xtree[2 * node], xtree[2 * node + 1]);
}

ll query1(ll lo, ll hi, ll left, ll right, ll node)

{
    if(lazy[node]) propagate(lo, hi, node);

    if(lo > right || hi < left)
        return 1e18;
    if(lo >= left && hi <= right) {
        return mtree[node];
    }

    ll mid = (lo + hi) / 2;
    ll p1 = query1(lo, mid, left, right, 2 * node);
    ll p2 = query1(mid + 1, hi, left, right, 2 * node + 1);

    return min(p1, p2);
}

ll query2(ll lo, ll hi, ll left, ll right, ll node)

{
    if(lazy[node]) propagate(lo, hi, node);

    if(lo > right || hi < left)
        return 0;
    if(lo >= left && hi <= right) {
        return xtree[node];
    }

    ll mid = (lo + hi) / 2;
    ll p1 = query2(lo, mid, left, right, 2 * node);
    ll p2 = query2(mid + 1, hi, left, right, 2 * node + 1);

    return max(p1, p2);
}

ll lcm(ll n)

{
    ll sqt = sqrt(n);
    ll gun = 1;
    for(ll i = 0; prime[i] <= sqt; i++) {
        ll tmp = n / prime[i];
        ll mulp = 1;
        while(tmp >= prime[i]) {
            mulp = (mulp * (prime[i] % mod) ) % mod;
            tmp /= prime[i];
        }

        gun = (gun * mulp) % mod;
    }

    //cout << gun << " ff " << endl;

    ll pos = upper_bound(prime.begin(), prime.end(), n) - prime.begin();
    pos--;
    //cout << pos << "  " << mul[pos] << endl;
    gun = (gun * mul[pos]) % mod;

    return gun;
}

int main()

{
    prime.push_back(2);
    mul[indx++] = 2;
    for(ll i = 3; i <= siz; i += 2) {
        if(!mark[i]) {
            for(ll j = i * i; j <= siz; j += i + i) {
                mark[j] = 1;
            }
            prime.push_back(i);
            mul[indx] = (i * mul[indx - 1]) % mod;
            indx++;
        }
    }

    ll n, q, op, l, r, x;
    scanf("%lld %lld", &n, &q);
    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &ara[i]);
    }

    build(1, n, 1);
    for(ll i = 1; i <= q; i++) {
        scanf("%lld %lld %lld", &op, &l, &r);
        l++, r++;
        if(op == 0) {
            scanf("%lld", &x);
            update(1, n, l, r, x, 1);
        }
        else if(op == 2) {
            ll num = query1(1, n, l, r, 1);
            //cout << num << endl;
            if(num > 1)
                printf("%lld\n", lcm(num));
            else
                printf("%lld\n", num);
        }
        else {
            ll num = query2(1, n, l, r, 1);
            //cout << num << endl;
            if(num > 1)
                printf("%lld\n", lcm(num));
            else
                printf("%lld\n", num);
        }
    }

    return 0;
}
