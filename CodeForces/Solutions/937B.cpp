#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define inf (1LL << 62)
#define sqt 31650
#define sqt2 178
#define siz 1000000
bool ara[siz + 20];
int prime[80000], k;

ll mulmod(ll a, ll b, ll c) {
    ll x = 0, y = a % c;
    while (b) {
        if (b & 1) x = (x + y) % c;
        y = (y << 1) % c;
        b >>= 1;
    }
  return x % c;
}

ll fastPow(ll x, ll n, ll MOD) {
    ll ret = 1;
    while (n) {
        if (n & 1) ret = mulmod(ret, x, MOD);
        x = mulmod(x, x, MOD);
        n >>= 1;
    }
  return ret;
}

bool isPrime(ll n) {
    if(n == 2 || n == 3) return true;
    if(n == 1 || !(n & 1)) return false;
    ll d = n - 1;
    ll s = 0;
    while (d % 2 == 0) {
        s++;
        d /= 2;
    }

    ll a[9] = { 2, 3, 5, 7, 11, 13, 17, 19, 23 };
    for(ll i = 0; i < 9; i++) {
        bool comp = fastPow(a[i], d, n) != 1;
        if(comp) for(ll j = 0; j < s; j++) {
            ll fp = fastPow(a[i], (1LL << (ll)j)*d, n);
            if (fp == n - 1) {
                comp = false;
                break;
            }
        }
        if(comp) return false;
    }
    return true;
}

int main()

{
    prime[0] = 2;
	k = 1;
	ara[1] = 1;
	for(int i = 3; i <= siz; i += 2) {
		if(ara[i] == 0) {
			for(int j = i + i; j <= siz; j += i) {
				ara[j] = 1;
			}
			prime[k] = i;
			k++;
        }
	}
	prime[k] = 9999999;

    ll p, y;
    cin >> p >> y;

    ll sq = sqrt(y);

    if(p >= sq) {
        for(ll i = y; i > p; i--) {
            if(i > siz) {
                if(isPrime(i)) {
                    cout << i << endl;
                    return 0;
                }
            }
            else {
                if(ara[i] == 0 && (i % 2 != 0) ) {
                    cout << i << endl;
                    return 0;
                }
            }
        }
    }

    else {
        for(ll i = y; i > p; i--) {

            bool flag = 1;
            for(ll j = 0; j < k; j++) {
                if(prime[j] > p)
                    break;
                if(i % prime[j] == 0) {
                    flag = 0;
                    break;
                }
            }
            if(flag == 1) {
                cout << i << endl;
                return 0;
            }
        }
    }

    cout << -1 << endl;

    return 0;
}