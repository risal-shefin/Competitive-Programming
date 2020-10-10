#include <bits/stdc++.h>
using namespace std;

int main()

{
    char R[] = "snvfrghjokl;,mp[wtdyibecux";
    char L[] = " vxswdfguhjknbio earycqzt ";

    char cmd;
    char a[120] ;
    scanf("%c", &cmd);
    scanf("%s", a);

    if(cmd == 'R') {
        for(int i = 0; a[i] != '\0'; i++) {
            if(a[i] == ';')
                printf("l");
            else if(a[i] == '/')
                printf(".");
            else if(a[i] == '.')
                printf(",");
            else if(a[i] == ',')
                printf("m");
            else
                printf("%c", L[a[i] - 97]);
        }
    }

    if(cmd == 'L') {
        for(int i = 0; a[i] != '\0'; i++) {
            if(a[i] == '.')
                printf("/");
            else if(a[i] == ',')
                printf(".");
            else
                printf("%c", R[a[i] - 97]);
        }
    }

    printf("\n");
    return 0;
}