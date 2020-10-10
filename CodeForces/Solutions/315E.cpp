#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

ll BITree[1000009];

///do this for range: getSum(r) - getSum(l - 1)
ll getSum(ll index)
{
    ll sum = 0; // Iniialize result

    // Traverse ancestors of BITree[index]
    while (index>0)
    {
        // Add current element of BITree to sum
        sum += BITree[index];
        sum %= mod;

        // Move index to parent node in getSum View
        index -= index & (-index);
    }
    return sum;
}

void updateBIT(ll n, ll index, ll val)

{

    // Traverse all ancestors and add 'val'
    while (index <= n)
    {
       // Add 'val' to current node of BI Tree
       BITree[index] += val;
       BITree[index] %= mod;

       // Update index to that of parent in update View
       index += index & (-index);
    }
}

int main()

{
    ll n, in;
    cin >> n;
    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &in);

        ll v = (getSum(in) * in + in) % mod;
        ll toAdd = v -  ( (getSum(in) - getSum(in - 1)) + mod) % mod;

        updateBIT(1000001, in, (toAdd + mod) % mod );
    }

    cout << getSum(1000001) % mod << endl;

    return 0;
}