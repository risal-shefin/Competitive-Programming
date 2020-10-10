#include <stdio.h>

int main()

{
    char s1[110], s2[210];
    int i, j;
    scanf("%s", s1);
    for(i = 0, j = 0; s1[i] != '\0'; i++) {
        if(s1[i] >= 'A' && s1[i] <= 'Z') {
            s1[i] = s1[i] + 32;
        }

        if(s1[i] == 'a' || s1[i] == 'e' || s1[i] == 'y' || s1[i] == 'i' || s1[i] == 'o' || s1[i] == 'u') {
            continue;
        }

        s2[j] = '.';
        j++;
        s2[j] = s1[i];
        j++;
    }

    s2[j] = '\0';
    printf("%s\n", s2);
    return 0;
}