#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 2e18

int main()

{
    ll n, m, p;
    cin >> n;
    m = n;
    p = n;
    if(n <= 2) {
        printf("1\n1\n");
        return 0;
    }
    if(n == 3) {
        printf("2\n1 3\n");
        return 0;
    }

    cout << n << endl;
    ll ara[n + 5];
    ll indx = 1;

    if(p % 2 == 0)
        p--;
    for(ll i = p; i >= 1; i-=2) {
        if(indx > n)
            break;
        ara[indx++] = i;
    }

    if(m % 2 != 0)
        m--;

    for(ll i = m; i >= 2; i -= 2) {
        if(indx > n)
            break;
        ara[indx++] = i;
    }

    for(ll i = 1; i < indx; i++) {
        printf("%lld", ara[i]);
        if(i != indx - 1)
            printf(" ");
    }

    cout << endl;

    return 0;
}