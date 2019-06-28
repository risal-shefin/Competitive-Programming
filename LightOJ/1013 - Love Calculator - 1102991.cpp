#include <bits/stdc++.h>
using namespace std;
char a[35], b[35];
int lena, lenb;
int stlen[40][40];
long long stnum[40][40][40];
long long stringlen(int i, int j)
{
    if(stlen[i][j] != -1)
        return stlen[i][j];
      if(i == lena)
        return lenb - j;
      if(j == lenb)
        return lena - i;
      if(a[i] == b[j])
        return stlen[i][j] = 1 + stringlen(i + 1, j + 1);
      return stlen[i][j] = 1 + min(stringlen(i + 1, j), stringlen(i, j + 1));
}
long long stringnum(int i, int j, long long len)
{
    if(stnum[i][j][len] != -1)
        return stnum[i][j][len];
      if(i == lena && j == lenb && len == 0)
        return 1;
      if(i == lena && j == lenb && len != 0)
        return 0;
      if(i == lena &&  j != lenb)
        return stringnum(i, j + 1, len - 1);
      if(i != lena && j == lenb)
        return stringnum(i + 1, j, len - 1);
      if(a[i] == b[j])
        return stnum[i][j][len] = stringnum(i + 1, j + 1, len - 1);
      return stnum[i][j][len] = stringnum(i, j + 1, len - 1) + stringnum(i + 1, j, len - 1);
}
int main()
{
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        scanf("%s %s", a, b);
        lena = strlen(a);
        lenb = strlen(b);
          memset(stlen, -1, sizeof(stlen));
        long long len = stringlen(0, 0);
          memset(stnum, -1, sizeof(stnum));
        long long num = stringnum(0, 0, len);
          printf("Case %d: %lld %lld\n", ++caseno, len, num);
    }
      return 0;
}
 
