#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    scanf("%I64d", &n);
    ll sqt = sqrt(n);
    for(ll i = 1; i <= sqt; i++) {
        ll j = n - i * i;
        ll tmpsqt = sqrt(j);
        if(tmpsqt * tmpsqt == j) {
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
    return 0;
}