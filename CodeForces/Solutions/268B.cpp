#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int ans = (n * (n + 1)) / 2;
    for(int i = n - 2, j = 1; i >= 1; i--, j++) ans += i * j;
    printf("%d\n",  ans);
}