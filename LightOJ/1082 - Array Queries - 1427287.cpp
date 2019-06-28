#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define block 320
vector <ll> v[block];
ll mn[block];
ll query(ll l, ll r)
{
    ll lb = l / block, rb = r / block;
    ll lp = l - lb * block, rp = r - rb * block;
    ll ans = 1e18;
      if(lb == rb) {
        for(ll i = lp; i <= rp; i++)
            ans = min(ans, v[lb][i]);
          return ans;
    }
      for(ll i = lp; i < v[lb].size(); i++)
        ans = min(ans, v[lb][i]);
    for(ll i = lb + 1; i < rb; i++)
        ans = min(ans, mn[i]);
    for(ll i = 0; i <= rp; i++)
        ans = min(ans, v[rb][i]);
      return ans;
}
int main()
{
    ll t, cs = 0;
    cin >> t;
    while(t--) {
        for(ll i = 0; i < block; i ++) {
            mn[i] = 1e18;
            v[i].clear();
        }
          ll n, q;
        scanf("%lld %lld", &n, &q);
        for(ll i = 0; i < n; i++) {
            ll in;
            scanf("%lld", &in);
            v[i / block].push_back(in);
            mn[i / block] = min(mn[i / block], in);
        }
          printf("Case %lld:\n", ++cs);
        while(q--) {
            ll l, r;
            scanf("%lld %lld", &l, &r);
              printf("%lld\n", query(l - 1, r - 1) );
        }
      }
    return 0;
}
