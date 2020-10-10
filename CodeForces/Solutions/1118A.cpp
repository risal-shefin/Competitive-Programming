#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()

{
    ll q;
    cin >> q;
    while(q--) {
        ll n, a, b;
        scanf("%lld %lld %lld", &n, &a, &b);

        if(2 * a <= b) {
            printf("%lld\n", n * a);
        }
        else {
            ll am = n / 2;
            ll cst = am * b;;
            if(n % 2 != 0) {
                cst += a;
            }

            printf("%lld\n", cst);
        }
    }
    return 0;
}