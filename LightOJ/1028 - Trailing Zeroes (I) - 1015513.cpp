#include <bits/stdc++.h>
using namespace std;
#define siz 1000000
char ara[siz + 5];
vector <int> v;
int main()
{
    for(int i = 2; i <= siz; i++) {
        if(ara[i] == '\0') {
           for(int j = i + i; j <= siz; j += i) {
               ara[j] = '1';
           }
           v.push_back(i);
        }
    }
    v.push_back(99999999);
      int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; i++) {
        long long n;
        scanf("%lld", &n);
        long long count, div = 1;
        int sqt = sqrt(n);
        for(int j = 0; v[j] <= sqt; j++)  {
            sqt = sqrt(n);
            if(n % v[j] == 0) {
                count = 1;
                while(n % v[j] == 0) {
                    n /= v[j];
                    count++;
                }
                div *= count;
            }
        }
        if(n > 1)
            div *= 2;
          printf("Case %d: %lld\n", i, div - 1);
    }
      return 0;
}
 
