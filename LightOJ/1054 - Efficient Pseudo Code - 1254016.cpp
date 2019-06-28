#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
typedef pair <long long int, long long int> p;
#define x first
#define y second
p extendedEuclid(long long int a, long long int b)
{
    if(b == 0) return p(1, 0);
    else {
        p eq = extendedEuclid(b, a % b);
        return p(eq.y, eq.x - eq.y * (a / b));
    }
}
long long int modi(long long int a, long long int m)
{
    p inv = extendedEuclid(a, m);
    return ((inv.x % m) + m) % m;
}
long long bigmod(long long b, long long p, long long m)
{
    if(p == 0)
        return 1;
      else if(p & 1)
        return ((b % m) * bigmod(b, p - 1, m)) % m;
      else {
        long long r = bigmod(b, p / 2, m);
        return ((r % m) * (r % m)) % m;
    }
}
int main()
{
    ll t, caseno = 0;
    scanf("%lld", &t);
    while(t--) {
        ll n, p;
        scanf("%lld %lld", &n, &p);
        ll sqt = sqrt(n), ans = 1;
        for(ll i = 2; i <= sqt; i++) {
              if(n % i == 0) {
                ll cnt = 0;
                while(n % i == 0) {
                    n /= i;
                    cnt++;
                }
                  ll tmp = bigmod(i, cnt * p + 1, mod) - 1;
                ll tmp2 = modi(i - 1, mod);
                tmp = (tmp + mod) % mod;
                tmp = (tmp * tmp2) % mod;
                ans = (ans * tmp) % mod;
                sqt = sqrt(n);
            }
        }
          if(n > 1) {
            ll tmp = bigmod(n, p + 1, mod) - 1;
            ll tmp2 = modi(n - 1, mod);
            tmp = (tmp + mod) % mod;
            tmp = (tmp * tmp2) % mod;
            ans = (ans * tmp) % mod;
        }
          printf("Case %lld: %lld\n", ++caseno, ans);
    }
      return 0;
}
 
