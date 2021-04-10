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

/// srand(time(NULL);   // setting seed for rand() at the start of main function
/// long long divisor = pollard_rho(n);   // to find one (any) divisor of n
