#include <bits/stdc++.h>
using namespace std;
int N, K, cnt;
bool used[30];
char ara[30];
void permut(int n)
{
    if(cnt == K)
        return;
    if(n == N) {
        for(int j = 0; j < N; j++) {
            printf("%c", ara[j]);
        }
        printf("\n");
        cnt++;
        return;
    }
      for(int i = 0; i < N; i++) {
        if(used[i])
            continue;
        ara[n] = 'A' + i;
        used[i] = 1;
        permut(n + 1);
        used[i] = 0;
        if(cnt == K)
            break;
    }
}
int main()
{
    int T;
    scanf("%d", &T);
    int caseno = 0;
    while(T--) {
        scanf("%d %d", &N, &K);
        cnt = 0;
        printf("Case %d:\n",++caseno);
        permut(0);
    }
      return 0;
}
 
