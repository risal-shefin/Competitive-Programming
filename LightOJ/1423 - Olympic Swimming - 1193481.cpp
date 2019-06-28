#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define mod 1000025263
int cumsum[32][50009], mn[50009];
ll pwr[35];
int main()
{
    //freopen("input.txt", "r", stdin);
    pwr[0] = 1;
    for(int i = 1; i <= 31; i++) {
        pwr[i] = pwr[i - 1] * 50021;
    }
      int t, caseno = 0;
    cin >> t;
    while(t--) {
        memset(cumsum, 0, sizeof(cumsum));
        map <ll, int> indx;
        int l, k, ans = 0;
        scanf("%d %d", &l, &k);
        for(int i = 1; i <= k; i++) {
            int n;
            scanf("%d", &n);
            for(int j = 1; j <= n; j++) {
                int pi;
                scanf("%d", &pi);
                cumsum[i][pi + 1] += 1;
            }
        }
          mn[0] = 0;
        for(int i = 1; i <= k; i++) {
            for(int j = 1; j <= l; j++) {
                cumsum[i][j] += cumsum[i][j - 1];
                if(i == 1)
                    mn[j] = cumsum[i][j];
                else
                    mn[j] = min(mn[j], cumsum[i][j]);
            }
        }
          for(int j = 0; j <= l; j++) {
            ll hsh = 0;
            for(int i = 1; i <= k; i++) {
                ll tmp = cumsum[i][j] - mn[j] + 1;
                hsh = (tmp * pwr[i - 1]) + hsh;
            }
            if(indx.find(hsh) == indx.end())
                indx[hsh] = j;
            else {
                int tmp = j - indx[hsh];
                ans = max(tmp, ans);
            }
        }
          printf("Case %d: %d meter(s)\n", ++caseno, ans);
    }
      return 0;
}
 
