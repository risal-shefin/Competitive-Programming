#include <bits/stdc++.h>
using namespace std;

#define ll int

int main()

{
    ll t;

    scanf("%d", &t);
    ll c1, c2;
    while(t--) {
        scanf("%d %d", &c1, &c2);

        if( (c1 & 1) && (c2 & 1) )
            printf("Ramesh\n");
        else
            printf("Suresh\n");

    }

    return 0;
}
