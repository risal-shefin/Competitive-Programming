#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define inf (1LL << 62)
#define mp make_pair
#define pb push_back
#define pll pair <ll, ll>

ll q[100009], ara[100009];
bool used[100009];

int main()

{
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        scanf("%lld", &n);
        for(ll i = 1; i <= n; i++) {
            scanf("%lld", &q[i]);
        }

        ll mx = 0;
        for(ll i = 1; i <= n; i++) {
            if(q[i] != mx) {
                mx = q[i];
                ara[i] = q[i];
                used[ q[i] ] = 1;
            }
        }

        ll idx = 1;
        for(ll i = 1; i <= n; i++) {
            if(ara[i] != 0)
                continue;

            while(used[idx] == 1)
                idx++;

            ara[i] = idx;
            used[idx] = 1;
        }

        bool chk = 1;
        mx = 0;
        for(ll i = 1; i <= n; i++) {
            mx = max(mx, ara[i]);
            if(mx != q[i]) {
                chk = 0;
                break;
            }
        }

        if(!chk)
            printf("-1\n");
        else {
            for(ll i = 1; i <= n; i++) {
                if(i != 1)
                    printf(" ");
                printf("%lld", ara[i]);
            }
            printf("\n");
        }

        memset(ara, 0, sizeof(ara));
        memset(used, 0, sizeof(used));
    }

    return 0;
}