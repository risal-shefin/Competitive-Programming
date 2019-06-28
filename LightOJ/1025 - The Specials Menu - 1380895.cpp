#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[70][70];
char ara[70];
ll solve(ll left, ll right)
{
    if(left > right) return 0;
    if(left == right) return 1;
    ll &ret = dp[left][right];
    if(ret != -1) return ret;
    ret = solve(left + 1, right) + solve(left, right - 1) - solve(left + 1, right - 1);
    if(ara[left] == ara[right])
        ret += 1 + solve(left + 1, right - 1);
      return ret;
}
int main()
{
    ll t, cs = 0;
    cin >> t;
    while(t--) {
        memset(dp, -1, sizeof(dp));
        scanf("%s", ara);
        printf("Case %lld: %lld\n", ++cs, solve(0, strlen(ara) - 1));
    }
      return 0;
}
 
