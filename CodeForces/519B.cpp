#include <bits/stdc++.h>
using namespace std;
int tmp[100009], ara[100009];
int main()
{
    int n;
    scanf("%d", &n);
    bool checker = 0;
    for(int i = 0; i < n; i++)
        scanf("%d", &tmp[i]);
    sort(tmp, tmp + n);
    for(int i = 0; i < n; i++)
        ara[i] = tmp[i];
    for(int i = 0; i < n - 1; i++)
        scanf("%d", &tmp[i]);
    sort(tmp, tmp + n - 1);
    for(int i = 0; i < n - 1; i++) {
        if(ara[i] != tmp[i] && checker == 0) {
            printf("%d\n", ara[i]);
            checker = 1;
        }
        ara[i] = tmp[i];
    }
    if(checker == 0) {
        printf("%d\n", ara[n - 1]);
    }
    checker = 0;
    for(int i = 0; i < n - 2; i++)
        scanf("%d", &tmp[i]);
    sort(tmp, tmp + n - 2);
    for(int i = 0; i < n - 2; i++) {
        if(ara[i] != tmp[i]) {
            printf("%d\n", ara[i]);
            checker = 1;
            break;
        }
    }
    if(checker == 0)
        printf("%d\n", ara[n - 2]);
    return 0;
}
