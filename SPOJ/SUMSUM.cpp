#include <bits/stdc++.h>
using namespace std;

int one[300009][32], ara[100009];
char state[5];
#define ll long long

void build(int lo, int hi, int node)

{
    if(lo == hi) {
        for(int i = 30; i >= 0; i--) {
            int state = (ara[lo] >> i) & 1;
            if(state == 0) {
                one[node][i] = 0;
            }
            else {
                one[node][i] = 1;
            }
        }
        return;
    }

    int mid = (lo + hi) / 2;
    build(lo, mid, 2 * node);
    build(mid + 1, hi, 2 * node + 1);

    for(int i = 30; i >= 0; i--) {
        one[node][i] = one[2 * node][i] + one[2 * node + 1][i];
    }
}

void update(int lo, int hi, int indx, int x, int node)

{
    if(lo > indx || hi < indx)
        return;
    if(lo == indx && hi == indx) {
        for(int i = 30; i >= 0; i--) {
            int state = (x >> i) & 1;
            if(state == 0) {
                one[node][i] = 0;
            }
            else {
                one[node][i] = 1;
            }
        }
        return;
    }

    int mid = (lo + hi) / 2;
    update(lo, mid, indx, x, 2 * node);
    update(mid + 1, hi, indx, x, 2 * node + 1);

    for(int i = 30; i >= 0; i--) {
        one[node][i] = one[2 * node][i] + one[2 * node + 1][i];
    }
}

int query(int lo, int hi, int left, int right, int bt, int node)

{
    if(lo > right || hi < left)
        return 0;
    if(lo >= left && hi <= right) {
        return one[node][bt];
    }

    int mid = (lo + hi) / 2;
    int p1 = query(lo, mid, left, right, bt, 2 * node);
    int p2 = query(mid + 1, hi, left, right, bt, 2 * node + 1);

    return p1 + p2;
}

int main()

{
    int n, q;
    scanf("%d %d", &n, &q);
    for(int i = 1; i <= n; i++)
        scanf("%d", &ara[i]);
    build(1, n, 1);

    for(int i = 1; i <= q; i++) {
        int op;
        scanf("%d", &op);
        if(op == 1) {
            int x, indx;
            scanf("%d %d", &x, &indx);
            update(1, n, indx, x, 1);
        }
        if(op == 2) {
            scanf(" %s", state);
            int l, r;
            ll zer, on, ans = 0, total;
            scanf("%d %d", &l, &r);
            if(l == r) {
                printf("0\n");
                continue;
            }
            if(l > r)
                swap(l, r);

            if(state[0] == 'X') {
                for(int j = 30; j >= 0; j--) {
                    on = query(1, n, l, r, j, 1);
                    zer = (r - l + 1) - on;
                    total = zer + on;
                    total = (total * (total - 1)) / 2;
                    total -= (on * (on - 1)) / 2;
                    total -= (zer * (zer - 1)) / 2;
                    ans += (1 << j) * total;
                }
            }
            else if(state[0] == 'O') {
                for(int j = 30; j >= 0; j--) {
                    on = query(1, n, l, r, j, 1);
                    zer = (r - l + 1) - on;
                    total = zer + on;
                    total = (total * (total - 1)) / 2;
                    total -= (zer * (zer - 1)) / 2;
                    ans += (1 << j) * total;
                }
            }
            else {
                for(int j = 30; j >= 0; j--) {
                    on = query(1, n, l, r, j, 1);
                    total = (on * (on - 1)) / 2;
                    ans += (1 << j) * total;
                }
            }

            printf("%lld\n", ans);
        }
    }
    return 0;
}
