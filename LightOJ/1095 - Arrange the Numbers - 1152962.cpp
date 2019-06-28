#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define ll long long
ll nCr[1009][1009];
ll fact[1009];
void comb()
{
    for(ll i = 0; i <= 1000; i++){
        nCr[i][0] = nCr[i][i] = 1;
          for(ll j = 1; j <= i / 2; j++){
              nCr[i][j] = nCr[i][i - j] = ( nCr[i - 1][j] % M + nCr[i - 1][j - 1] % M) % M;
        }
    }
}
void perm()
{
    fact[0] = 1;
    for(ll i = 1; i <= 1000; i++) {
        fact[i] = ( (fact[i - 1] % M) * (i % M) ) % M;
    }
}
ll dearrange(ll n, ll k)
{
    ll ans = fact[n];
    for(int i = 1; i <= k; i++) {
        ll neg;
        if(i % 2 == 1)
            neg = -1;
        else
            neg = 1;
        ans += neg * ( (nCr[k][i]) % M * (fact[n - i]) % M ) % M;
        ans = (ans + M) % M;
    }
    return ans;
}
int main()
{
    comb();
    perm();
      ll t, caseno = 0;
    scanf("%lld", &t);
    while(t--) {
        int n, m, k;
        scanf("%d %d %d", &n, &m, &k);
          ll ans = ( (nCr[m][k] % M) * (dearrange(n - k, m - k) % M) ) % M;
        printf("Case %lld: %lld\n", ++caseno, ans);
    }
      return 0;
}
 
