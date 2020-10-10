#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define inf (1LL<<61)
#define sl(val) scanf("%lld", &val)

ll r1[200009], ans[200009];
struct node {
    ll r;
    ll id;
} r2[200009];


bool cmp(node a, node b)

{
    return a.r < b.r;
}

int main()

{

    ll n, k;
    cin >> n >> k;
    for(ll i = 1; i <= n; i++) {
        sl(r1[i]);
        r2[i].r = r1[i];
        r2[i].id = i;
    }

    sort(r2 + 1, r2 + n + 1, cmp);

    for(ll i = 1; i <= n; i++) {
        ll tmp = r2[i].r, sf = 0;
        ll lo = 1, hi = n;
        while(lo <= hi) {
            ll mid = (lo + hi) / 2;

            if(r2[mid].r >= tmp)
                hi = mid - 1;
            else if(r2[mid].r < tmp) {
                sf = mid;
                lo = mid + 1;
            }
        }
        ans[ r2[i].id ] =sf;
    }

    for(ll i = 1; i <= k; i++) {
        ll u, v;
        sl(u), sl(v);

        if(r1[u] > r1[v]) {
            ans[u]--;
        }
        if(r1[u] < r1[v]) {
            ans[v]--;
        }
    }

    for(ll i = 1; i <= n; i++) {
        if(i != 1)
            printf(" ");
        printf("%lld", ans[i]);
    }

    cout << endl;
    return 0;
}