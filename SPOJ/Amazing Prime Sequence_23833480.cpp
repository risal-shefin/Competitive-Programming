#include <bits/stdc++.h>
using namespace std;
#define ll int
ll dv[10000009];
long long ans[10000009];
bool mark[3170];
int main()
 {
    for(ll i = 2; i <= 3163; i++) {
        if(mark[i] == 0) {
            for(ll j = i + i; j <= 10000000; j += i) {
                if(j < 3170)
                    mark[j] = 1;
                 if(dv[j] == 0)
                    dv[j] = i;
                else
                    dv[j] = min(dv[j], i);
            }
        }
    }
     for(ll i = 2; i <= 10000000; i++) {
        if(dv[i] == 0)
            ans[i] = ans[i - 1] + (long long)i;
        else
            ans[i] = ans[i - 1] + (long long)dv[i];
    }
     ll t;
    cin >> t;
    while(t--) {
        ll n;
        scanf("%d", &n);
        printf("%lld\n", ans[n]);
    }
     return 0;
}
