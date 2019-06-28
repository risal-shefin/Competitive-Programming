#define siz 1000
#include <bits/stdc++.h>
using namespace std;
    struct ab {
    int num;
    int cnt;
} ara[1005];
bool compare(ab a, ab b)
{
    if(a.cnt == b.cnt) {
        return a.num > b.num;
    }
      return a.cnt < b.cnt;
}
int main()
{
    bitset <1005> mark;
    int prime[1005];
    prime[0] = 2;
    int k = 1;
    for(int i = 3; i <= siz; i += 2) {
        if(mark[i] == 0) {
            for(int j = i * i; j <= siz; j += i + i) {
                mark[j] = 1;
            }
            prime[k] = i;
            k++;
        }
    }
      for(int i = 1; i <= 1000; i++) {
        int tmp = i, dv = 1;
        for(int j = 0; prime[j] * prime[j] <= tmp; j++) {
            int count = 1;
            if(tmp % prime[j] == 0) {
                while(tmp % prime[j] == 0) {
                    tmp /= prime[j];
                    count++;
                }
                dv *= count;
            }
        }
          if(tmp > 1)
            dv *= 2;
          ara[i - 1].cnt = dv;
        ara[i - 1].num = i;
    }
      sort(ara, ara + 1000, compare);
      int T, n;
    scanf("%d", &T);
    for(int i = 1; i <= T; i++) {
        scanf("%d", &n);
        printf("Case %d: %d\n", i, ara[n - 1].num);
    }
      return 0;
}
 
