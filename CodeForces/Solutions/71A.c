#include <stdio.h>

int main()

{
    int n, i, j, count;
    char s[110];
    scanf("%d", &n);

    for(i = 1; i <= n; i++) {
        scanf("%s", s);
        count = 0;
        for(j = 0 ; s[j] != '\0'; j++) {
            count++;
        }

        if(count <= 10) {
            printf("%s\n", s);
        }

        else {
            printf("%c%d%c\n", s[0], count - 2, s[count - 1]);
        }
    }

    return 0;
}