#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 1e18

int main()

{
    ll n;
    cin >> n;
    if(n < 6)
        printf("-1\n");
    else {
        printf("1 2\n2 3\n2 4\n");
        for(ll i = 5; i <= n; i++)
            printf("1 %lld\n", i);
    }
    for(ll i = 2; i <= n; i++) {
        printf("1 %lld\n", i);
    }
    return 0;
}