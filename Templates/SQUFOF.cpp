#define ll long long

// trival divisor O( n^(1/4) )
// ll divisor = SQUFOF(n);   // a divisor of n
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
