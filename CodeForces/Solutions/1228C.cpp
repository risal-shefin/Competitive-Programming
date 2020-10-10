#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

vector <ll> prime;

ll mulmod(ll a, ll b, ll c)
{
    ll x = 0, y = a % c;
    while (b)
    {
        if (b & 1) x = (x + y) % c;
        y = (y << 1) % c;
        b >>= 1;
    }
    return x % c;
}

ll fastPow(ll x, ll n, ll MOD)
{
    ll ret = 1;
    while (n)
    {
        if (n & 1) ret = mulmod(ret, x, MOD);
        x = mulmod(x, x, MOD);
        n >>= 1;
    }
    return ret % MOD;
}

int main()

{
    ll x, n;
    cin >> x >> n;

    ll xx = x, nn = n;

    for(ll i = 2; i * i <= xx; i++) {
        if(xx % i == 0) {
            while(xx % i == 0) {
                xx /= i;
            }
            prime.push_back(i);
        }
    }
    if(xx > 1)
        prime.push_back(xx);

    ll mul = 1;
    for(ll i = 0; i < prime.size(); i++) {
        ll p = prime[i];

        while(p <= n) {
            ll cnt1 = n / p;
            ll cnt2 = 0;
            if(n / p >= prime[i])
                cnt2 += (n / (p * prime[i]));

//            if(p <= sqrtl(n)) {
//                ll tp = p * p;
//                cnt2 += n / tp;
////                while(1) {
////                    cnt2 += (n / tp);
////                    if(tp > n / p)
////                        break;
////                    tp *= p;
////                    cout << tp << " " << cnt2 << endl;
////                }
//            }

            mul = (mul * fastPow(p, cnt1 - cnt2, mod)) % mod;

            //cout << p << " " << (cnt1 - cnt2) << " " << cnt1 << " " << cnt2 << endl;

            if(n / p < prime[i])
                break;

            p *= prime[i];
        }
    }

    cout << mul << endl;

    return 0;
}