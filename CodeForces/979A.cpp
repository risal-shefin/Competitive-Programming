#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1e18
#define sl(val) scanf("%lld", &val)
int main()
{
    ll n;
    cin >> n;
    if(n == 0) {
        printf("0\n");
        return 0;
    }
    n++;
    if(n % 2 == 0) {
        printf("%lld\n", n / 2);
        return 0;
    }
    else {
        printf("%lld\n", n);
        return 0;
    }
    return 0;
}
