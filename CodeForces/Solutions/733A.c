#include <stdio.h>
int main()

{
    char s[110];
    int count = 0, count1 = 0, i;
    scanf("%s", s);
    for(i = 0; s[i] != '\0'; i++) {
        if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'Y') {
            if(count1 > 0) {
                if(count1 > count) {
                    count = count1;
                }
                count1 = 0;
            }

            count1++;
            //printf("%d\t%c\t", count1, s[i]);
        }

        else {
            if(i == 0) count1++;
            count1++;
            //printf("%d\t%c\t", count1, s[i]);
        }

    }

    if(count1 > count) count = count1;
    printf("%d\n", count);
    return 0;
}