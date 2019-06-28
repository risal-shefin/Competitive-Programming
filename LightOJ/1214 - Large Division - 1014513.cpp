#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    long long int b;
    scanf("%d", &T);
    for(int i = 1; i <= T; i++) {
        char a[250];
        long long int num = 0, mod = 0;
        scanf("%s %lld", a, &b);
        int j = 0;
        if(a[j] == '-')
            j = 1;
        for(; a[j] != '\0'; j++) {
            num += a[j] - 48;
            mod = num % b;
            num = mod * 10;
        }
          printf("Case %d: ", i);
        if(mod == 0)
            printf("divisible\n");
        else
            printf("not divisible\n");
    }
      return 0;
}
 
