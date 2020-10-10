#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll a[100009], b[100009], ara[100009], n;

ll solve(ll num)

{
    ara[1] = num;
    for(ll i = 1; i < n; i++) {

        bool check = 0;
        for(ll j = 0; j <= 3; j++) {
            if( (ara[i] | j) == a[i] && (ara[i] & j) == b[i] ) {
                ara[i + 1] = j;
                check = 1;
                //cout << i + 1 << "  " << j << "  " << a[i] << "  " << (ara[i] | j) << endl;
                break;
            }
        }

        if(!check)
            return 0;
    }

    return 1;
}

int main()

{
    cin >> n;
    for(ll i = 1; i < n; i++)
        scanf("%lld", &a[i]);
    for(ll i = 1; i < n; i++)
        scanf("%lld", &b[i]);

    for(ll i = 0; i <= 3; i++) {
        bool state = solve(i);
        if(state) {
            printf("YES\n");
            for(ll i = 1; i <= n; i++) {
                if(i != 1)
                    printf(" ");
                printf("%lld", ara[i]);
            }
            printf("\n");
            return 0;
        }
    }

    printf("NO\n");

    return 0;
}