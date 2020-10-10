#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define inf 2e18
#define ninf -2e18

ll ara[200009], ans[200009], cnt[200009], prv[200009];

int main()

{
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++)
        scanf("%lld", &ara[i]);

    ll mx = 0;
    map <ll, ll> mark, indx;
    for(ll i = 1; i <= n; i++) {
        mark[ ara[i] ] = mark[ ara[i] - 1 ] + 1;
        cnt[i] = mark[ ara[i] ];
        mx = max( mx, cnt[i]);
        indx[ ara[i] ] = i;
        prv[i] = indx[ ara[i] - 1];
    }

    ll counter = mx, stop = n, ind = 0;

    for(ll i = n; i >= 0; i--) {
        if(cnt[i] == mx) {
            ans[ind++] = i;
            ll tmp = prv[i];

            while(tmp != 0) {
                ans[ind++] = tmp;
                tmp = prv[tmp];
            }

            break;
        }
    }
    cout << counter << endl;
    for(ll j = ind - 1; j >= 0; j--) {
        printf("%lld", ans[j]);
        if(j != 0)
            printf(" ");
        else
            printf("\n");
    }

    return 0;
}