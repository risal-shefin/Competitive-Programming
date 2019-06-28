#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t, caseno = 0;
    cin >> t;
    while(t--) {
        ll n;
        scanf("%lld", &n);
          ll sum = 0;
        for(ll i = 1; i <= n; i++)
        {
            ll in;
            scanf("%lld", &in);
            while(in & 1)
                in /= 2;
              ll lo = 0, hi = 1e9, ans;
            while(lo <= hi)
            {
                ll mid = (lo + hi) / 2;
                if(2 * mid > in)
                    hi = mid - 1;
                else if(2 * mid < in)
                    lo = mid + 1;
                else
                {
                    ans = mid;
                    break;
                }
            }
              //cout << in << "  " << ans << endl;
            sum ^= ans;
          }
          if(sum)
            printf("Case %lld: Alice\n", ++caseno);
        else
            printf("Case %lld: Bob\n", ++caseno);
    }
      return 0;
}
 
