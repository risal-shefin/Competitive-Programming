#include <bits/stdc++.h>
using namespace std;
#define ll int
ll ara[40], n, k, indx = 0;
unordered_map <ll, bool> mark;
bool chk = 0;
void solve1(ll pos, ll sum)
{
    if(pos >= n) {
        mark[sum] = 1;
        return;
    }
      solve1(pos + 1, sum);
    solve1(pos + 1, sum + ara[pos]);
}
void solve2(ll pos, ll sum)
{
    if(pos >= 2 * n) {
        if(sum <= k && mark[k - sum])
            chk = 1;
          return;
    }
    if(chk) return;
      solve2(pos + 1, sum);
    solve2(pos + 1, sum + ara[pos]);
}
int main()
{
    ll t, cs = 0;
    cin >> t;
    while(t--) {
        indx = 0, chk = 0;
        scanf("%d %d", &n, &k);
          for(ll i = 0; i < n; i++) {
            scanf("%d", &ara[indx]);
            indx++;
            ara[indx] = ara[indx - 1];
            indx++;
        }
          solve1(0, 0);
        solve2(n, 0);
          if(chk) printf("Case %d: Yes\n", ++cs);
        else printf("Case %d: No\n", ++ cs);
          mark.clear();
    }
      return 0;
}
 
