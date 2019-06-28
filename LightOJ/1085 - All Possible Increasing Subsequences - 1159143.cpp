#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
int ara[100009];
int ar[100009];
int main()
{
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        int n;
        map <int, int> m;
          memset(ar, 0, sizeof(ar));
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%d", &ara[i]);
        }
          int cnt = 0, ans = 0;
        vector <int> v(ara, ara + n);
        sort(v.begin(), v.end());
          for(int i = 0; i < n; i++) {
            if( m[ v[i] ] == 0)
                m[ v[i] ] = ++cnt;
        }
          for(int i = 0; i < n; i++) {
              int result = 0, start = m[ ara[i] ];
            for(int j = start - 1; j > 0; j -= (j & -j) )
                result = (result + ar[j]) % mod;
              result = result + 1;
            ans = (ans + result) % mod;
              for(int j = start; j <= cnt; j += (j & -j))
                ar[j] = (result + ar[j]) % mod;
        }
          printf("Case %d: %d\n", ++caseno, ans);
      }
      return 0;
}
 
