#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[52][2][2][2][2];
char s[52];
ll solve(ll pos, ll f1, ll f2, ll f3, ll f4)
{
    if(s[pos] == '\0')
        return 2;
    ll &ret = dp[pos][f1][f2][f3][f4];
    if(ret != -1)
        return ret;
      ret = 0;
    if(s[pos] == '?') {
        if(pos > 1 && (f1 == 0 && f2 == 0))
            ret |= 1;
        else
            ret |= solve(pos + 1, 0, f1, f2, f3);
          if(pos > 3 && (f1 == f2 && f2 == f3 && f3 == f4 && f4 == 1))
            ret |= 1;
        else
            ret |= solve(pos + 1, 1, f1, f2, f3);
    }
    else if(s[pos] == '0') {
        if(pos > 1 && (f1 == 0 && f2 == 0))
            ret |= 1;
        else
            ret |= solve(pos + 1, 0, f1, f2, f3);
    }
    else if(s[pos] == '1') {
        if(pos > 3 && (f1 == f2 && f2 == f3 && f3 == f4 && f4 == 1))
            ret |= 1;
        else
            ret |= solve(pos + 1, 1, f1, f2, f3);
    }
      return ret;
}
int main()
{
    ll t, cs = 0;
    cin >> t;
    while(t--) {
        memset(dp, -1, sizeof(dp));
        scanf("%s", s);
        for(ll i = 0; s[i] != '\0'; i++) {
            if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
                s[i] = '0';
            else if(s[i] != '?')
                s[i] = '1';
        }
          ll ret = solve(0, 0, 0, 0, 0);
        printf("Case %lld: %s\n", ++cs, ret == 2?"GOOD": ret == 1?"BAD": "MIXED");
    }
      return 0;
}
 
