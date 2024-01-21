// Reference: https://github.com/ShahjalalShohag/code-library/blob/main/Number%20Theory/Pollard%20Rho.cpp
/// find any divisor of (n) in ˜O(n^(1/4))
namespace PollardRho {
    mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
    const int P = 1e6 + 9;
    ll seq[P];

    inline ll add_mod(ll x, ll y, ll m) {
        return (x += y) < m ? x : x - m;
    }
    inline ll mul_mod(ll x, ll y, ll m) {
        return (__int128)x*y % m;
    }

    ll pollard_rho(ll n) {
        if(n<=1) return 1;
        if(!(n&1)) return 2;
        if(isPrime(n)) return n;
        while (1) {
            ll x = rnd() % n, y = x, c = rnd() % n, u = 1, v, t = 0;
            ll *px = seq, *py = seq;
            while (1) {
                *py++ = y = add_mod(mul_mod(y, y, n), c, n);
                *py++ = y = add_mod(mul_mod(y, y, n), c, n);
                if ((x = *px++) == y) break;
                v = u;
                u = mul_mod(u, abs(y - x), n);
                if (!u) return __gcd(v, n);
                if (++t == 32) {
                    t = 0;
                    if ((u = __gcd(u, n)) > 1 && u < n) return u;
                }
            }
            if (t && (u = __gcd(u, n)) > 1 && u < n) return u;
        }
    }
}

// isPrime(n) -> use Miller-Rabin or similar efficient primality test
// long long divisor = PollardRho::pollard_rho(n);   // to find one (any) divisor of n
