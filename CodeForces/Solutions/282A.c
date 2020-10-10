#include <stdio.h>

int main()

{
    int n, i, x = 0;
    char s[5];
    scanf("%d", &n);

    for(i = 1; i <= n; i++) {
        scanf("%s", s);
        if(s[0] == '+' || s[2] == '+')
            x++;
        else if(s[0] == '-' || s[2] == '-')
            x--;
    }

    printf("%d\n", x);
    return 0;
}