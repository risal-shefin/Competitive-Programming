// C++ program to compute Totient function for
// all numbers smaller than or equal to n.
#include<iostream>
using namespace std;

// Computes and prints totien of all numbers
// smaller than or equal to n.

#define sz 10000000
#define ll long long

ll prime[sz + 9], etf[sz + 9];

void computeTotient() {
    etf[1] = 1;
    for(ll i = 2; i <= sz; i++){
        if(!prime[i]){
            etf[i] = i - 1;
            for(ll j = 1; j * i <= sz; j++)
                if(!prime[j*i])prime[j*i] = i;
        }
        else{
            etf[i] = etf[prime[i]] * etf[ i/prime[i] ];
            ll g = 1;
            if(i % (prime[i]*prime[i]) == 0) g = prime[i];
            etf[i] *= g;
            etf[i] /= etf[g];
        }
    }
}

// Driver program to test above function
int main()
{
    computeTotient();
    return 0;
}
