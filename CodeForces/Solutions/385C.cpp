#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll cs[10000020], p[200];
bitset <10000010> mark;

ll pollard_rho(ll n)  //pollard rho implementation
{
    if(n % 2==0)
        return 2;

    ll x = rand() % n + 1;
    ll c = rand() % n + 1;
    ll y = x;
    ll d = 1;

    //fn is f(x) = x*x + c
    while(d==1)
    {
        x = ((x * x) % n + c) % n;
        y = ((y * y) % n + c) % n;
        y = ((y * y) % n + c) % n;

        d = __gcd(abs(x-y),n);
    }

    return d != n? d: pollard_rho(n);
}

const ll multiplier[] = {1, 3, 5, 7, 11, 3*5, 3*7, 3*11, 5*7, 5*11, 7*11, 3*5*7, 3*5*11, 3*7*11, 5*7*11, 3*5*7*11};
#define nelems(x) (sizeof(x) / sizeof((x)[0]))
ll SQUFOF( ll N )
{
    ll D, Po, P, Pprev, Q, Qprev, q, b, r, s;
    ll L, B, i;
    s = (ll)(sqrtl(N)+0.5);
    if (s*s == N) return s;
    for (ll k = 0; k < nelems(multiplier) && N <= UINT64_MAX/multiplier[k]; k++)
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
        }
        while (P != Pprev);
        r = __gcd(N, Qprev);
        if (r != 1 && r != N) return r;
    }
    return pollard_rho(N);
}

void factor(ll n)

{
    for(ll i = 0; p[i] * p[i] * p[i] <= n; i++) {
        if(n % p[i] == 0) {
            cs[p[i]]++;
            while(n % p[i] == 0)
                n /= p[i];
        }
    }

    if(n > 1) {
        if(!mark[n])
            cs[n]++;
        else {
            ll dv = SQUFOF(n);
            
            cs[dv]++;
            if(dv * dv != n)
                cs[n / dv]++;
        }
    }
}

int main()

{
    srand(time(NULL));
    ll indx =  0;
    p[indx++] = 2;
    for(ll i = 3; i <= 10000005; i += 2) {
        if(!mark[i]) {
            if(i <= 220)
                p[indx++] = i;
            for(ll j = i * i; j <= 10000005; j += i + i)
                mark[j] = 1;
        }
    }
    for(ll i = 4; i <= 10000005; i += 2)
        mark[i] = 1;
    mark[1] = 1;

    p[indx++] = 3000;

    ll n, inp;
    cin >> n;
    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &inp);
        factor(inp);
    }

    for(ll i = 1; i <= 10000002; i++)
        cs[i] += cs[i - 1];

    ll q, l, r;
    cin >> q;
    while(q--) {
        scanf("%lld %lld", &l, &r);
        if(l > 10000000) {
            printf("0\n");
            continue;
        }
        if(r > 10000000)
            r = 10000000;
        printf("%lld\n", cs[r] - cs[l - 1]);
    }

    return 0;
}