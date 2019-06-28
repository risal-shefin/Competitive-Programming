#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[1009], ispal[1009][1009];
char s[1009];
ll solve(ll pos)
{
    if(s[pos] == '\0')
        return 0;
    ll &ret = dp[pos];
    if(ret != -1)
        return ret;
      ret = 1e18;
    for(ll i = pos; s[i] != '\0'; i++) {
        if(ispal[pos][i])
            ret = min(ret, 1 + solve(i + 1));
    }
      return ret;
}
int main()
{
    ll t, cs = 0;
    cin >> t;
    while(t--) {
        memset(dp, -1, sizeof(dp));
        memset(ispal, 0, sizeof(ispal));
          scanf("%s", s);
          for(ll i = 0; s[i] != '\0'; i++) {
              ispal[i][i] = 1;
            for(ll j = i - 1, k = i + 1; j >= 0 && s[k] != '\0'; j--, k++) {
                if(s[j] != s[k])
                    break;
                ispal[j][k] = 1;
            }
              for(ll j = i - 1, k = i; j >= 0 && s[k] != '\0'; j--, k++) {
                if(s[j] != s[k])
                    break;
                ispal[j][k] = 1;
            }
        }
          printf("Case %lld: %lld\n", ++cs, solve(0));
    }
      return 0;
}
 
