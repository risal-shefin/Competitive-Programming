// C++ program to efficiently compute values
// of euler totient function for multiple inputs.
#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MAX = 100001;
bool isPrime[MAX+1];

// Stores prime numbers upto MAX - 1 values
vector<ll> p;

// Finds prime numbers upto MAX-1 and
// stores them in vector p
void sieve()
{

    for (ll i = 2; i<= MAX; i++)
    {
        // if prime[i] is not marked before
        if (isPrime[i] == 0)
        {
            // fill vector for every newly
            // encountered prime
            p.push_back(i);

            // run this loop till square root of MAX,
            // mark the index i * j as not prime
            for (ll j = 2; i * j<= MAX; j++)
                isPrime[i * j]= 1;
        }
    }
}

// function to find totient of n
ll phi(ll n)
{
    ll res = n;

    // this loop runs sqrt(n / ln(n)) times
    for (ll i=0; p[i]*p[i] <= n; i++)
    {
        if (n % p[i]== 0)
        {
            // subtract multiples of p[i] from r
            res -= (res / p[i]);

            // Remove all occurrences of p[i] in n
            while (n % p[i]== 0)
               n /= p[i];
        }
    }

    // when n has prime factor greater
    // than sqrt(n)
    if (n > 1)
       res -= (res / n);

    return res;
}

// Driver code
int main()
{
    // preprocess all prime numbers upto 10 ^ 5
    sieve();
    cout << phi(11) << "\n";
    cout << phi(21) << "\n";
    cout << phi(31) << "\n";
    cout << phi(41) << "\n";
    cout << phi(51) << "\n";
    cout << phi(61) << "\n";
    cout << phi(91) << "\n";
    cout << phi(101) << "\n";
    return 0;
}
