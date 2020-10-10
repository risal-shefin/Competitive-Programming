#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define eps 1e-9
#define dd double

bool isSq(ll n)

{
    dd tmp = sqrt( (dd) n) + eps;
    tmp = floor(tmp);
    ll tmp2 = (ll)tmp;
    if(tmp2 * tmp2 == n)
        return 1;
    return 0;
}

int main()

{
    ll t;
    cin >> t;
    while(t--) {
        ll in, n, m;
        scanf("%I64d", &in);

        if(in == 0) {
            printf("1 1\n");
            continue;
        }
        bool flag = 0;
        for(ll i = 1; i <= 100000; i++)
        {
            if(i * i <= in)
                continue;
            ll valx = (i / 2LL);
            valx *= valx;
            if( (i * i - valx) > in)
                break;
            ll tmp = i * i - in;

            if(!isSq(tmp) )
                continue;
            dd tmp2 = sqrt((dd)tmp) + eps;
            tmp2 = floor(tmp2);
            ll nm = (ll)tmp2;

            ll nn = i;
            ll mm = i / nm;
            ll tre=nn/mm;
            tre*=tre;
            ll tmp3 = nn * nn - tre;
            if(tmp3 == in) {
                flag = 1;
                n = nn;
                m = mm;
                break;
            }
        }

        if(flag == 1)
            printf("%I64d %I64d\n", n, m);
        else
            printf("-1\n");
    }

    return 0;
}