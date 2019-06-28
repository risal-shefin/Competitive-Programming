#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int ara[n + 5];
    for(int i = 0; i < n; i++)
        cin >> ara[i];
    for(int i = 0; i < n; i++) {
        if(i < n - 1) {
            if(ara[i] >= 1) {
                printf("P");
                ara[i]--;
            }
            while(ara[i] > 0) {
                printf("RLP");
                ara[i]--;
            }
            printf("R");
        }
        else {
            if(ara[i] >= 1) {
                printf("P");
                ara[i]--;
            }
            while(ara[i] > 0) {
                printf("LRP");
                ara[i]--;
            }
        }
    }
    printf("\n");
    return 0;
}
