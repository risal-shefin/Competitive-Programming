#include <bits/stdc++.h>
using namespace std;
#define siz 10000050
int prime[1013119];
int main()
{
    bitset <siz> mark;
    prime[0] = 2;
    int k = 1;
    long long j, i;
    for(int i = 3; i <= siz; i++) {
        if(mark[i] == 0) {
            for(j = 3 * i; j <= siz; j += i + i) {
                mark[j] = 1;
            }
            prime[k] = i;
            k++;
        }
    }
      prime[k] = INT_MAX;
    int T;
    long long N;
    scanf("%d", &T);
      for(int k = 1; k <= T; k++) {
        scanf("%lld", &N);
        long long temp = N, cnt = 0, r = 1;
        long long sqt = sqrt(temp);
        for(int i = 0; prime[i] <= sqt; i++) {
            sqt = sqrt(temp);
            if(temp % prime[i] == 0) {
                cnt = 1;
                while(temp % prime[i] == 0) {
                    temp /= prime[i];
                    cnt++;
                }
                  if(i != 0)
                    r *= cnt;
            }
        }
          if(temp > 1)
            r *= 2;
        r--;
        if(!(N ^ 2))
            r = 0;
          printf("Case %d: %lld\n", k, r);
      }
      return 0;
}
