#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool isPrime(ll n)

{
    if(n == 1)
        return 0;
    ll sqt = sqrt(n);
    for(ll i = 2; i <= sqt; i++)
        if(n % i == 0)
            return 0;

    return 1;
}

int main()

{
    set <ll> div;
    ll n, a, b;
    cin >> n;
    for(ll i = 1; i <= n; i++) {
        scanf("%lld %lld", &a, &b);

        if(i == 1) {
            ll sqt = max( (ll)sqrt(a), (ll)sqrt(b) );

            for(ll j = 2; j <= sqt; j++) {
                if(a % j == 0 || b % j == 0) {
                    if(isPrime(j))
                        div.insert(j);
                    if(a % j == 0)
                        if(isPrime(a / j))
                            div.insert(a / j);
                    if(b % j == 0)
                        if(isPrime(b / j))
                            div.insert(b / j);
                }
            }

            if(isPrime(a))
                div.insert(a);
            if(isPrime(b))
                div.insert(b);
        }
        else {
            ll last = -1;
            for(auto it = div.begin(); it != div.end() && !div.empty(); ) {

                ll x = *it;
                //cout << x << endl;
                if(a % x != 0 && b % x != 0) {
                    div.erase(x);
                    if(last != -1)
                        it = div.find(last);
                    else
                        it = div.begin();
                }
                else {
                    last = x;
                    it++;
                }
            }
        }

    }

    if(div.empty())
        cout << -1 << endl;
    else
        cout << *div.begin() << endl;

    return 0;
}