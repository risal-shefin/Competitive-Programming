#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, r, b;
bool check[502][502][2];
double dp1[502][502][2];
double solve1(ll r, ll b, ll state)
{
    if(state == 1 && b == 0)
        return 0;
    if(r == 0 && b == 1)
        return 1;
      double &ret = dp1[r][b][state];
    if(check[r][b][state])
        return ret;
      ret = 0;
    if(state == 1)
        ret = solve1(r, b - 1, state ^ 1);
    else {
        if(r > 0)
            ret += (1.0 / (r + b) ) * r * solve1(r - 1, b, state ^ 1);
        if(b > 0)
            ret += (1.0 / (r + b)) * b * solve1(r, b - 1, state ^ 1);
    }
      check[r][b][state] = 1;
    return ret;
}
int main()
{
    ll t, cs = 0;
    cin >> t;
    while(t--) {
        scanf("%lld %lld", &r, &b);
          double ans = solve1(r, b, 0);
        printf("Case %lld: %0.10f\n", ++cs, ans);
    }
      return 0;
}
 
