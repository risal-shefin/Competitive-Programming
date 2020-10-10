#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll st[105], cd[205], freq[55], freqs[20];

int main()

{
    ll t;
    cin >> t;
    while(t--) {
        memset(freq, 0, sizeof(freq));
        memset(freqs, 0, sizeof(freqs));
        ll n, m;
        scanf("%lld %lld", &n, &m);
        for(ll i = 0; i < n; i++) {
            scanf("%lld", &st[i]);
            freqs[ st[i] ]++;
        }
        for(ll i = 0; i < m; i++) {
            scanf("%lld", &cd[i]);
            freq[ cd[i] ]++;
        }

        ll start = 1;
        bool chk = 1;
        for(ll i = 5; i <= 15; i++) {
            if(freqs[i] == 0)
                continue;

            bool state = 0;
            for(ll j = start; j <= 50; j++) {
                if(freq[j] >= freqs[i]) {
                    start = j + 1;
                    state = 1;
                    break;
                }
            }

            if(state == 0) {
                chk = 0;
                break;
            }
        }

        if(!chk)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}