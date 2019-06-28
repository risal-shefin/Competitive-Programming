#include <bits/stdc++.h>
using namespace std;
#define ll long long
bitset <1000009> check;
ll dv[10000009];
unordered_map <ll, ll> cnt;
#define ll long long
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
    return ret;
}
bool isPrime(ll n)
{
    if(n == 2 || n == 3) return true;
    if(n == 1 || !(n & 1)) return false;
    ll d = n - 1;
    int s = 0;
    while (d % 2 == 0)
    {
        s++;
        d /= 2;
    }
     int a[9] = { 2, 3, 5, 7, 11, 13, 17, 19, 23 };
    for(int i = 0; i < 9; i++)
    {
        bool comp = fastPow(a[i], d, n) != 1;
        if(comp) for(int j = 0; j < s; j++)
            {
                ll fp = fastPow(a[i], (1LL << (ll)j)*d, n);
                if (fp == n - 1)
                {
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
    for(ll i = 2; i <= 1000000; i++) {
        if(check[i] == 0) {
            for(ll j = i * i; j <= 1000000; j += i)
                check[j] = 1;
        }
    }
    ll n, m;
    while(scanf("%lld", &n) && n != -1) {
         ll ans1 = 1, ans2;
        m = n;
          if(n <= 1000000 && check[n] == 0) {
            ans1 = 1, ans2 = n;
        }
        else if(n > 1000000 && isPrime(n)) {
            ans1 = 1, ans2 = n;
        }
        else {
            ll indx = 0;
            for(ll i = 2; i * i * i <= n; i++) {
                if(n % i == 0) {
                    dv[indx++] = i;
                    while(n % i == 0) {
                        n /= i;
                        cnt[i]++;
                    }
                }
            }
             if(n > 1) {
                ll sqt = sqrt(n);
                if(sqt * sqt == n) {
                    dv[indx++] = sqt;
                    cnt[sqt] += 2;
                }
                dv[indx++] = n;
                cnt[n]++;
            }
             ll lim;
            for(ll i = 0; i < indx; i++) {
                lim = cnt[ dv[i] ] / 2;
                for(ll j = 1; j <= lim; j++)
                    ans1 *= dv[i];
            }
             ans2 = m / (ans1 * ans1);
        }
         printf("%lld %lld\n", ans1, ans2);
        cnt.clear();
    }
     return 0;
