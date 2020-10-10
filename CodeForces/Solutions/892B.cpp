#include <bits/stdc++.h>
using namespace std;

int main()


{
    int n;
    scanf("%d", &n);
    int ara[n + 5];
    for(int i = 1; i <= n; i++)
        scanf("%d", &ara[i]);

    int kllpwr = 0, klld = 0;
    for(int i = n; i >= 1; i--) {
        if(kllpwr > 0) {
            kllpwr--;
            klld++;
        }

        if(ara[i] > kllpwr)
            kllpwr = ara[i];
    }

    printf("%d\n", n - klld);

    return 0;
}