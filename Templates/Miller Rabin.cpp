/* Miller Rabin Primality Test for <= 10^18 */

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
    return ret % MOD;
}

const int a[9] = { 2, 3, 5, 7, 11, 13, 17, 19, 23 };
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

    for(int i = 0; i < 9; i++)
    {
        if(n == a[i]) return true;
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
