#include <bits/stdc++.h>
using namespace std;

#define ll int
#define block 320
const ll sz = 100009;

ll togo[sz + 9], jump[sz + 9], p[sz + 9], n;

void update(ll b)

{
    ll lp = b * block, rp = min(n - 1, (b + 1) * block - 1);
    for(ll i = rp; i >= lp; i--) {
        if(i + p[i] > rp) {
            togo[i] = i;
            jump[i] = 1;
        }
        else {
            togo[i] = togo[i + p[i]];
            jump[i] = 1 + jump[i + p[i]];
        }
    }
}

ll query(ll pos)

{
    ll cnt = 0, last;
    while(pos < n) {
        cnt += jump[pos];
        last = togo[pos];
        pos = last + p[last];
    }

    printf("%d %d\n", last + 1, cnt);
}

int main()

{
    ll q;
    cin >> n >> q;
    for(ll i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    for(ll i = 0; i <= n / block; i++)
        update(i);

    while(q--) {
        ll t;
        scanf("%d", &t);
        if(t == 1) {
            ll a;
            scanf("%d", &a);
            a--;
            query(a);
        }
        else {
            ll a, b;
            scanf("%d %d", &a, &b);
            a--;
            p[a] = b;
            update(a / block);
        }
    }

    return 0;
}