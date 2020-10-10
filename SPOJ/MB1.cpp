#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector <ll> prime, palprime;
bool mark[1000009];

bool isPal(ll n)

{
    ll num = 0, tmp = n;
    while(tmp != 0) {
        ll rem = tmp % 10;
        num = num * 10 + rem;
        tmp /= 10;
    }

    if(num == n)
        return 1;
    return 0;
}

ll mul(ll n)

{
    ll tmp = n, ret = 1;
    while(tmp != 0) {
        ll rem = tmp % 10;
        if(rem != 0)
            ret *= rem;
        tmp /= 10;
    }

    return ret;
}

int main()

{
    prime.push_back(2);
    palprime.push_back(2);
    for(ll i = 3; i <= 1000000; i += 2) {
        if(mark[i] == 0) {
            for(ll j = i * i; j <= 1000000; j += i + i) {
                mark[j] = 1;
            }
            if(isPal(i)) {
                palprime.push_back(i);
                //cout << i << endl;
            }

            prime.push_back(i);
        }
    }
    //cout << prime.size() << endl;

    sort(prime.begin(), prime.end());
    sort(palprime.begin(), palprime.end());

    ll t;
    cin >> t;
    while(t--) {
        ll n;
        scanf("%lld", &n);
        ll m = mul( palprime[n - 1] );
        printf("%lld %lld\n", palprime[n - 1], prime[m - 1]);
    }

    return 0;
}
