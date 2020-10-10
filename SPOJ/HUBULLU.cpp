#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()

{
    ll t;
    cin >> t;
    while(t--) {
        ll n, state;
        scanf("%lld %lld", &n, &state);
        if(state == 0)
            printf("Airborne wins.\n");
        else
            printf("Pagfloyd wins.\n");
    }

    return 0;
}
