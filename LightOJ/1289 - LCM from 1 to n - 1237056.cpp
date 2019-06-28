#include <bits/stdc++.h>
using namespace std;
#define ll unsigned int
#define siz 100000000
#define sqt sqrt(siz)
bitset <siz + 9> mark;
ll ara[5761460], mul[5761460];
int main()
{
    ll i, j, indx = 0;
    mul[indx] = 2;
    ara[indx++] = 2;
      for(i = 3; i <= siz; i += 2) {
        if(!mark[i]) {
            if(i <= sqt) {
                for(j = i * i; j <= siz; j += i + i) {
                    mark[j] = 1;
                }
            }
              mul[indx] = mul[indx - 1] * i;
            ara[indx++] = i;
        }
    }
      ll t, caseno = 0, n, gun = 1, sqtn, pos, mulprime = 1;
    scanf("%u", &t);
    while(t--) {
        gun = 1;
        scanf("%u", &n);
        sqtn = sqrt(n);
        for(i = 0; ara[i] <= sqtn; i++) {
              mulprime = 1;
            ll tmp = n / ara[i];
            while(tmp >= ara[i]) {
                mulprime *= ara[i];
                tmp /= ara[i];
            }
              gun *= mulprime;
        }
          pos = upper_bound(ara, ara + indx, n) - ara;
        pos--;
        gun *= mul[pos];
          printf("Case %u: %u\n", ++caseno, gun);
    }
      return 0;
}
 
