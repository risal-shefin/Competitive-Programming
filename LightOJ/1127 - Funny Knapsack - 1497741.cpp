#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector <ll> comb1, comb2;
ll n, half, w, ara[32], ans = 0;
void solve1(ll pos, ll sum)
{
    if(pos > half) {
        if(sum <= w) {
            ans++;
            comb1.push_back(sum);
        }
        return;
    }
    solve1(pos + 1, sum);
    solve1(pos + 1, sum + ara[pos]);
}
    void solve2(ll pos, ll sum)
{
    if(pos > n) {
        if(sum <= w) {
            ans++;
            comb2.push_back(sum);
        }
        return;
    }
    solve2(pos + 1, sum);
    solve2(pos + 1, sum + ara[pos]);
}
int main()
{
    ll t, cs = 0;
    cin >> t;
    while(t--) {
        scanf("%lld %lld", &n, &w);
        for(ll i = 1; i <= n; i++)
            scanf("%lld", &ara[i]);
          half = n / 2, ans = 0;
        solve1(1, 0);
        solve2(half + 1, 0);
        ans--;
          sort(comb1.begin(), comb1.end());
        sort(comb2.begin(), comb2.end());
          for(ll i = 1; i < comb1.size(); i++) {    // 0th index is the null combination
            ll maxLim = w - comb1[i];
            ll pos = upper_bound(comb2.begin(), comb2.end(), maxLim) - comb2.begin();
            pos--;
              ans += pos;
        }
          printf("Case %lld: %lld\n", ++cs, ans);
          comb1.clear(), comb2.clear();
    }
      return 0;
}
 
