#include <stdio.h>
int main()
{
    int i, count = 1;
    char s[110];
    scanf("%s", s);
    for(i = 1; s[i] != '\0'; i++) {
        if(s[i] == '1') {
            if(s[i - 1] == '0') {
                count = 0;
            }
            count++;
        }
        else if(s[i] == '0') {
            if(s[i - 1] == '1') {
                count = 0;
            }
            count++;
        }
        if(count == 7) {
            break;
        }
    }
    if(count == 7) {
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }
    return 0;
}
