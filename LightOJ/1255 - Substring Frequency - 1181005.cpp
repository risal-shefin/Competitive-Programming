#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000014143
ll pwr[1000009], hsh1[1000009];
char ara1[1000009], ara2[1000009];
int main()
{
    //freopen("out.txt", "w", stdout);
    pwr[0] = 1;
    for(ll i = 1; i <= 1000002; i++) {
        pwr[i] = (pwr[i - 1] * 30) % mod;
        if(pwr[i] < 0)
            pwr[i] = (pwr[i] + mod) % mod;
    }
      hsh1[0] = 0;
    ll t, caseno = 0;
    scanf("%lld", &t);
    while(t--) {
        scanf(" %s %s", ara1, ara2);
        ll len1 = strlen(ara1);
        ll len2 = strlen(ara2);
          for(ll i = 0; i < len1; i++) {
            hsh1[i + 1] = ( ( (ara1[i] - 96) * pwr[i]) % mod + hsh1[i] ) % mod;
            if(hsh1[i + 1] < 0)
                hsh1[i + 1] = (hsh1[i + 1] + mod) % mod;
        }
          ll hsh = 0;
        for(ll i = 0; i < len2; i++) {
            hsh = ( ( (ara2[i] - 96) * pwr[i] ) % mod + hsh ) % mod;
            if(hsh < 0)
                hsh = (hsh + mod) % mod;
        }
          ll cnt = 0;
        for(ll i = 0; i < (len1 - len2 + 1); i++) {
            ll tmp = hsh1[i + len2]  - hsh1[i];
            if(tmp < 0)
                tmp = (tmp + mod) % mod;
            ll cmp = (hsh * pwr[i]) % mod;
            if(cmp < 0)
                cmp = (cmp + mod) % mod;
            if(tmp == cmp)
                cnt++;
        }
          printf("Case %llu: %llu\n", ++caseno, cnt);
    }
      return 0;
}
 
