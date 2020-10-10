#include <stdio.h>

int main()

{
    int n, i;
    char s1[110], s2[110];
    scanf("%s", s1);
    scanf("%s", s2);

    for(i = 0; s1[i] != '\0'; i++) {
        if(s1[i] >= 'A' && s1[i] <= 'Z') {
            s1[i] = s1[i] + 32;
        }

        if(s2[i] >= 'A' && s2[i] <= 'Z') {
            s2[i] = s2[i] + 32;
        }

        if(s1[i] > s2[i]) {
            printf("1\n");
            return 0;
        }

        else if(s1[i] < s2[i]) {
            printf("-1\n");
            return 0;
        }
    }


    printf("0\n");

    return 0;
}