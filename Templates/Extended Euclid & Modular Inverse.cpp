#define ll long long
typedef pair<ll, ll> pii;
#define x first
#define y second

pii extendedEuclid(ll a, ll b)   // returns x, y for ax + by = gcd(a,b)
{
    if(b == 0) return pii(1, 0);
    else
    {
        pii d = extendedEuclid(b, a % b);
        return pii(d.y, d.x - d.y * (a / b));
    }
}

ll modularInverse(ll a, ll m)
{
    pii ret = extendedEuclid(a, m);
    return ((ret.x % m) + m) % m;
}
