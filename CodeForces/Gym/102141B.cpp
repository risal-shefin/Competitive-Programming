#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll ara[50009];
vector <ll> fact;
const ll inf = 1e10;

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

const ll multiplier[] = {1, 3, 5, 7, 11, 13,
                        3*5, 3*7, 3*11, 3*13, 5*7, 5*11, 5*13, 7*11, 7*13, 11*13,
                        3*5*7, 3*5*11, 3*5*13, 3*7*11, 3*7*13, 3*11*13, 5*7*11, 5*7*13, 5*11*13, 7*11*13,
                        3*5*7*11, 3*5*7*13, 3*5*11*13, 3*7*11*13, 5*7*11*13, 3*5*7*11*13};
#define nelems(x) (sizeof(x) / sizeof((x)[0]))
ll SQUFOF( ll N )
{
    ll D, Po, P, Pprev, Q, Qprev, q, b, r, s;
    ll L, B, i;
    s = (ll)(sqrtl(N)+0.5);
    if (s*s == N) return s;
    for (int k = 0; k < nelems(multiplier) && N <= UINT64_MAX/multiplier[k]; k++)
    {
        D = multiplier[k]*N;
        Po = Pprev = P = sqrtl(D);
        Qprev = 1;
        Q = D - Po*Po;
        L = 2 * sqrtl( 2*s );
        B = 3 * L;
        for (i = 2 ; i < B ; i++)
        {
            b = (ll)((Po + P)/Q);
            P = b*Q - P;
            q = Q;
            Q = Qprev + b*(Pprev - P);
            r = (ll)(sqrtl(Q)+0.5);
            if (!(i & 1) && r*r == Q) break;
            Qprev = q;
            Pprev = P;
        };
        if (i >= B) continue;
        b = (ll)((Po - P)/r);
        Pprev = P = b*r + P;
        Qprev = r;
        Q = (D - Pprev*Pprev)/Qprev;
        i = 0;
        do
        {
            b = (ll)((Po + P)/Q);
            Pprev = P;
            P = b*Q - P;
            q = Q;
            Q = Qprev + b*(Pprev - P);
            Qprev = q;
            i++;
        } while (P != Pprev);

        r = __gcd(N, Qprev);
        if (r != 1 && r != N) return r;
    }
    return 0;
}

void factor(ll n)

{
    for(ll i = 2; i * i * i <= n; i++) {
        if(n % i == 0) {
            ll mul = 1;
            while(n % i == 0) {
                n /= i;
                mul *= i;
            }
            fact.push_back(mul);
        }
    }

    if(n > 1) {
        if(isPrime(n)) {
            fact.push_back(n);
        }
        else {

            ll dv = SQUFOF(n);
            if(dv == (n / dv)) {
                fact.push_back(n);
            }
            else {
                fact.push_back(dv);
                fact.push_back(n / dv);
            }
        }
    }
}

ll btm[50009];
bool pos[1 << 17], valid[50009];
ll dp[1 << 17];

int main()

{
    ll t, cs = 0;
    cin >> t;
    while(t--) {
        fact.clear();
        memset(pos, 0, sizeof(pos));
        memset(btm, 0, sizeof(btm));
        memset(valid, 0, sizeof(valid));

        ll n, x, check = 0;
        cin >> n >> x;
        for(ll i = 1; i <= n; i++) {
            scanf("%lld", &ara[i]);
            if(ara[i] == x)
                check = 1;
        }

        factor(x);

        for(ll i = 1; i <= n; i++) {

            if(x % ara[i] == 0 )
                valid[i] = 1;
        }

        if(check) {
            printf("Case %lld: 1\n", ++cs);
            continue;
        }
        else if(x == 1) {
            printf("Case %lld: -1\n", ++cs);
            continue;
        }

        for(ll i = 1; i <= n; i++) {
            if(!valid[i])
                continue;
            for(ll j = 0; j < fact.size(); j++) {
                if(ara[i] % fact[j] == 0)
                    btm[i] |= (1 << j);
            }

            pos[ btm[i] ] = 1;
        }

        ll hi = (1 << (fact.size()) ) - 1;
        for(ll i = 0; i <= hi; i++)
            dp[i] = inf;

        // iterate over all the masks
        for (int mask = 0; mask <= hi; mask++) {

            if(!pos[mask])
                continue;

            // iterate over all the subsets of the mask
            for(int i = mask; i > 0; i = (i-1) & mask){
                dp[i] = 1;
                pos[i] = 1;
            }
        }
        dp[0] = 0;

        // iterate over all the masks
        for (int mask = 0; mask <= hi; mask++) {

            // iterate over all the subsets of the mask
            for(int i = mask; i > 0; i = (i-1) & mask){
                if(!pos[i])
                    continue;

                dp[mask] = min(dp[mask], 1LL + dp[mask ^ i]);
            }
        }

        printf("Case %lld: %lld\n", ++cs, dp[hi] != inf? dp[hi] : -1);

    }

    return 0;
}