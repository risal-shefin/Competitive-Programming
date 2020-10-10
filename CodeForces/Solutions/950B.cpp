#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define inf (1LL << 62)

ll ara1[100009], ara2[100009];

int main()

{
    ll n, m;
    cin >> n >> m;
    for(ll i = 1; i <= n; i++)
        scanf("%lld", &ara1[i]);
    for(ll i = 1; i <= m; i++)
        scanf("%lld", &ara2[i]);

    ll counter = 0, i = 1, j = 1, m1 = 1, m2 = 1, sum1 = 0, sum2 = 0;
    while(1) {

        if(i > n)
            break;

        if(m1)
            sum1 += ara1[i];
        if(m2)
           sum2 += ara2[j];

        if(sum1 == sum2) {
            counter++;
            sum1 = 0;
            sum2 = 0;
            i++, j++;
            m1 = 1, m2 = 1;
            continue;
        }

        if(sum1 > sum2) {
            m1 = 0;
            m2 = 1;
            j++;
            continue;
        }

        else {
            m1 = 1, m2 = 0;
            i++;
            continue;
        }

    }

    cout << counter << endl;

    return 0;
}