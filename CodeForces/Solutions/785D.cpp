#include <bits/stdc++.h>
using namespace std;

#define ll long long

typedef pair<ll, ll> pii;
#define x first
#define y second
#define mod 1000000007

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

ll fact[200009], inv[200009];

int main()

{
    std::ios_base::sync_with_stdio(false);
    fact[0] = inv[0] = 1;
    for(ll i = 1; i <= 200005; i++) {
        fact[i] = (i * fact[i - 1]) % mod;
        inv[i] = modularInverse(fact[i], mod);
    }

    string s;
    cin >> s;

    ll open = 0, close = 0;
    for(ll i = 0; i < s.length(); i++) {
        if(s[i] == ')')
            close++;
    }

    ll ans = 0;
    for(ll i = 0; i < s.length(); i++) {
        if(s[i] == ')') {
            close--;
            continue;
        }
        else
            open++;

        ans += ( (fact[open + close - 1] * inv[open]) % mod * inv[close - 1]) % mod;
        ans %= mod;
    }

    cout << ans << endl;

    return 0;
}