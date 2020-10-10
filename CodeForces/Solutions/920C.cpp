#include <bits/stdc++.h>
using namespace std;

int ara[200009];
int mark[200009];

int main()

{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &ara[i]);
    }
    for(int i = 0; i < n - 1; i++) {
        char ch;
        scanf(" %c", &ch);
        mark[i] = ch - '0';
    }

    bool state = 1;
    for(int i = 0; i < n - 1; i++) {
        if(ara[i] > ara[i + 1] && mark[i] == 0) {
            state = 0;
            break;
        }
        if(ara[i] > ara[i + 1] && mark[i] == 1) {
            swap(ara[i], ara[i + 1]);
        }
    }

    if(state == 1)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}