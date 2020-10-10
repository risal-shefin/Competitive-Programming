#include <bits/stdc++.h>
using namespace std;

#define siz 10000000
#define ll long long
bitset <siz + 9> mark;
int ara[100009], tree[300009], tree2[300009], prop[300009];

void propagate(int lo, int hi, int node)

{
    if(lo != hi) {
        prop[2 * node] = prop[node];
        prop[2 * node + 1] = prop[node];
    }

    int x = prop[node];
    if(x <= siz) {
        if(mark[x] == 0 && (x == 2 || (x % 2 != 0))) {
            tree[node] = hi - lo + 1;
        }
        else
            tree[node] = 0;
    }
    else
        tree[node] = 0;

    if(lo == hi)
        tree2[node] = x;

    prop[node] = 1e9;
}

void build(int lo, int hi, int node)

{
    if(lo == hi) {
        tree2[node] = ara[lo];
        if(ara[lo] <= siz) {
            if(mark[ ara[lo] ] == 0 && (ara[lo] == 2 || (ara[lo] % 2 != 0))) {
                tree[node] = 1;
                return;
            }
            else {
                tree[node] = 0;
                return;
            }
        }
        else {
            tree[node] = 0;
            return;
        }
    }

    int mid = (lo + hi) / 2;
    build(lo, mid, 2 * node);
    build(mid + 1, hi, 2 * node + 1);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

void update(int lo, int hi, int indx, int val, int node)

{
    if(prop[node] != 1e9) propagate(lo, hi, node);

    if(indx > hi || indx < lo)
        return;

    if(lo == indx && hi == indx) {
        tree2[node] += val;
        int x = tree2[node];
        if(x <= siz)
        {
            if(mark[x] == 0 && (x == 2 || (x % 2 != 0)))
            {
                tree[node] = 1;
            }
            else
                tree[node] = 0;
        }
        else
            tree[node] = 0;

        return;
    }

    int mid = (lo + hi) / 2;
    update(lo, mid, indx, val, 2 * node);
    update(mid + 1, hi, indx, val, 2 * node + 1);

    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

void update2(int lo, int hi, int left, int right, int x, int node)

{
    if(prop[node] != 1e9) propagate(lo, hi, node);

    if(lo > right || hi < left)
        return;

    if(lo >= left && hi <= right) {
        if(x <= siz)
        {
            if(mark[x] == 0 && (x == 2 || (x % 2 != 0)) )
            {
                tree[node] = hi - lo + 1;
            }
            else
                tree[node] = 0;
        }
        else
            tree[node] = 0;

        prop[node] = x;
        return;
    }

    int mid = (lo + hi) / 2;
    update2(lo, mid, left, right, x, 2 * node);
    update2(mid + 1, hi, left, right, x, 2 * node + 1);

    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int query(int lo, int hi, int left, int right, int node)

{
    if(prop[node] != 1e9) propagate(lo, hi, node);

    if(lo > right || hi < left)
        return 0;

    if(lo >= left && hi <= right)
        return tree[node];

    int mid = (lo + hi) / 2;
    int p1 = query(lo, mid, left, right, 2 * node);
    int p2 = query(mid + 1, hi, left, right, 2 * node + 1);
    return p1 + p2;
}

int main()

{
    for(int i = 0; i <= 300005; i++)
        prop[i] = 1e9;

    mark[1] = 1;
    for(ll i = 3; i * i <= siz; i += 2) {
        if(mark[i] == 0) {
            for(ll j = i * i; j <= siz; j += i + i) {
                mark[j] = 1;
            }
        }
    }

    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &ara[i]);
    }
    build(1, n, 1);

    for(int i = 1; i <= q; i++) {
        char ch;
        scanf(" %c", &ch);
        if(ch == 'A') {
            int val, indx;
            scanf("%d %d", &val, &indx);
            update(1, n, indx, val, 1);
        }
        else if(ch == 'R') {
            int val, l, r;
            scanf("%d %d %d", &val, &l, &r);
            update2(1, n, l, r, val, 1);
        }
        else {
            int l, r;
            scanf("%d %d", &l, &r);
            int ans = query(1, n, l, r, 1);
            printf("%d\n", ans);
        }
    }

    return 0;
}
