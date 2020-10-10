#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define siz 31700

bitset <siz> mark;

int main()

{
    ll tmp = sqrt(siz);
    mark[1] = 1;
    vector <ll> primes;
    primes.push_back(2);
    for(ll i = 3; i <= tmp; i += 2) {

        if(mark[i] == 0) {
            for(ll j = i * i; j <= siz; j += i + i) {
                mark[j] = 1;
                //cout << j << endl;
            }
        }
        //cout << i << endl;
    }

    for(ll i = 3; i <= siz; i += 2) {
        if(mark[i] == 0)
            primes.push_back(i);
    }

    //cout << primes.size();
    ll t;
    cin >> t;

    while(t--) {
        ll a, b;
        scanf("%lld %lld", &a, &b);

        for(ll i = a; i <= b; i++) {
            if(i % 2 == 0 && i != 2)
                continue;
            if(i == 1)
                continue;

            bool flag = 1;
            for(ll j = 0; j < primes.size(); j++) {
                if(i <= primes[j])
                    break;
                if(i % primes[j] == 0) {
                    flag = 0;
                    break;
                }
            }

            if(flag == 1) {
                printf("%lld\n", i);
            }

        }

        if(t != 0)
            printf("\n");
    }

    return 0;
}
