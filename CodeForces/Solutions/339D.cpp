#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll ara[200009], tree[600009];

void build(ll lo, ll hi, ll state, ll node)

{
    if(lo == hi) {
        tree[node] = ara[lo];
       // state = 1;
        return;
    }

    ll mid = (lo + hi) / 2;
    build(lo, mid, state ^ 1, 2 * node);
    build(mid + 1, hi, state ^ 1, 2 * node + 1);

    if(state)
        tree[node] = tree[2 * node] | tree[2 * node + 1];
    else
        tree[node] = tree[2 * node] ^ tree[2 * node + 1];
}

void update(ll lo, ll hi, ll indx, ll val, ll state, ll node)

{
    if(lo > indx || hi < indx)
        return;
    if(lo == hi) {
        tree[node] = val;
       // state = 1;
        return;
    }

    ll mid = (lo + hi) / 2;
    update(lo, mid, indx, val, state ^ 1, 2 * node);
    update(mid + 1, hi, indx, val, state ^ 1, 2 * node + 1);
    if(state) {
        tree[node] = tree[2 * node] | tree[2 * node + 1];
    }
    else
        tree[node] = tree[2 * node] ^ tree[2 * node + 1];

        //cout << tree[node] << "  " << tree[2 * node] << "  " << tree[2 * node + 1] << "  " << state << "  " << lo << "  "  << hi << endl;
}

int main()

{
    ll n, q;
    cin >> n >> q;
    ll pw = 1 << n;
    for(ll i = 1; i <= pw; i++)
        scanf("%lld", &ara[i]);

    ll state = 1;
    if(n % 2 == 0)
        state = 0;

    build(1, pw, state, 1);
    while(q--) {
        ll indx, num;
        scanf("%lld %lld", &indx, &num);

        update(1, pw, indx, num, state, 1);
        printf("%lld\n", tree[1]);
    }

    return 0;
}