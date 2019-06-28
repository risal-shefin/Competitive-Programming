#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll ara[109], n;
double dp[109];
bool check[109];
double solve(ll pos, ll factor)
{
    if(check[pos] != 0)
        return (1.0 / factor) * dp[pos];
      ll nfact;
    if(pos + 6 <= n)
        nfact = 6;
    else
        nfact = n - pos;
      double sum = ara[pos];
    for(ll i = pos + 1; i <= pos + nfact; i++) {
        double ret = solve(i, nfact);
        sum += ret;
    }
      dp[pos] = sum;
    check[pos] = 1;
      return (1.0 / factor) * sum;
}
int main()
{
    ll t, cs = 0;
    cin >> t;
    while(t--) {
        memset(check, 0, sizeof(check));
          scanf("%lld", &n);
        for(ll i = 1; i <= n; i++) {
            scanf("%lld", &ara[i]);
        }
          double ans = solve(1, 1);
          printf("Case %lld: %0.9f\n", ++cs, ans);
    }
      return 0;
}
 
