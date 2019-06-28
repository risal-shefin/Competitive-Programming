#include <bits/stdc++.h>
using namespace std;
#define ll long long
unordered_map <ll, ll> plcm, pnum;
int main()
{
    ll a, b, l;
    ll t, cs = 0;
    cin >> t;
    while(t--) {
        scanf("%lld %lld %lld", &a, &b, &l);
          if( !(l % a == 0 && l % b == 0) ) {
            printf("Case %lld: impossible\n", ++cs);
            continue;
        }
          for(ll i = 2; i * i <= a; i++) {
            if(a % i == 0) {
                ll cnt = 0;
                while(a % i == 0) {
                    cnt++;
                    a /= i;
                }
                pnum[i] = max(pnum[i], cnt);
            }
        }
        if(a > 1)
            pnum[a] = 1;
          for(ll i = 2; i * i <= b; i++) {
            if(b % i == 0) {
                ll cnt = 0;
                while(b % i == 0) {
                    cnt++;
                    b /= i;
                }
                pnum[i] = max(pnum[i], cnt);
            }
        }
        if(b > 1)
            pnum[b] = max(pnum[b], 1LL);
          for(ll i = 2; i * i <= l; i++) {
            if(l % i == 0) {
                ll cnt = 0;
                while(l % i == 0) {
                    cnt++;
                    l /= i;
                }
                plcm[i] = max(plcm[i], cnt);
            }
        }
        if(l > 1)
            plcm[l] = 1;
          ll ans = 1;
        for(auto it = plcm.begin(); it != plcm.end(); it++) {
            ll lcmcnt = it -> second;
            ll numcnt = pnum[it -> first];
            //cout << lcmcnt << "  " << numcnt << endl;
            if(numcnt < lcmcnt) {
                for(ll i = 1; i <= lcmcnt; i++)
                    ans *= (it -> first);
            }
        }
          printf("Case %lld: %lld\n", ++cs, ans);
          plcm.clear(), pnum.clear();
    }
      return 0;
}
 
