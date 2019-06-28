#include <stdio.h>
int main()
{
    int T, i, m, l, time;
    scanf("%d", &T);
    for(i = 1; i <= T; i++) {
        scanf("%d %d", &m, &l);
        if(m <= l)
           time = l * 4 + 19;
        else
            time = m * 4 + (m - l) * 4 + 19;
          printf("Case %d: %d\n", i, time);
    }
      return 0;
}
 
