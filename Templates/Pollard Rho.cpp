/// find any divisor of (n) in ˜O(n^(1/4))
ll pollard_rho(ll n)
{
    if (n <= 1) return 1;
    if (isPrime(n)) return n;
 
    ll d = n;
    for (ll c = 2; d == n; ++c)
    {    
        ll x = 2, y = 2, i = 2, k = 2;
        while (true)
        {
            x = (mulmod(x, x, n) + c);
            if (x >= n)	x -= n;
            d = __gcd(abs(x - y), n);
            if (d > 1 && n % d == 0) break;
            if (i++ == k) y = x, k <<= 1;
        }
    }
 
    return d;
}

// isPrime(n) -> use Miller-Rabin or similar efficient primality test
// mulmod(a,b,m) -> compute (a*b)%m without overflow
// long long divisor = pollard_rho(n);   // to find one (any) divisor of n
