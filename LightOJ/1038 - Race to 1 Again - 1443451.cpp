#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector <ll> dv[100009];
bool check[100009];
double dp[100009];
double solve(ll n)
{
    if(n == 1)
        return 0.0;
    if(check[n])
        return dp[n];
      double sum = 0;
    for(ll i = 0; i < dv[n].size(); i++)
        sum += dv[n][i] == n? 1: 1 + solve(dv[n][i]);
      sum *= (1.0 / dv[n].size());
    sum /= (1.0 - (1.0 / dv[n].size()) );
      check[n] = 1;
    return dp[n] = sum;
}
int main()
{
    for(ll i = 1; i <= 100000; i++) {
        for(ll j = i; j <= 100000; j += i) {
            dv[j].push_back(i);
        }
    }
      ll t, cs = 0;
    cin >> t;
    while(t--) {
        memset(check, 0, sizeof(check));
          ll n;
        scanf("%lld", &n);
          printf("Case %lld: %0.9f\n", ++cs, solve(n));
    }
      return 0;
}
 
