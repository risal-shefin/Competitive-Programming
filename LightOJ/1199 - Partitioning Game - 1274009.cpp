#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[10009];
ll solve(ll n)
{
    if(n <= 2) return 0;
      ll mid = n / 2;
    if(n % 2 == 0) mid--;
      if(dp[n] != -1)
        return dp[n];
      set <ll> st;
    for(ll i = 1; i <= mid; i++) {
        st.insert( solve(i) ^ solve(n - i) );
    }
      ll ret = 0;
    while(st.find(ret) != st.end()) ret++;
      return dp[n] = ret;
}
int main()
{
    memset(dp, -1, sizeof(dp));
    ll t, caseno = 0;
    cin >> t;
    while(t--) {
        ll n, sum = 0;
        scanf("%lld", &n);
        for(ll i = 1; i <= n; i++) {
            ll in;
            scanf("%lld", &in);
              sum ^= solve(in);
        }
          if(sum)
            printf("Case %lld: Alice\n", ++caseno);
        else
            printf("Case %lld: Bob\n", ++caseno);
    }
      return 0;
}
 
