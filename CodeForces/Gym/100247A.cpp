#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct node {
    ll a, b, c;
} ara[200009];

ll ans[200009], tmp[3];

int main()

{
    ll n;
    cin >> n;
    ll mxa = 0, mxb = 0, mxc = 0;
    for(ll i = 1; i <= n; i++) {
        scanf("%lld %lld %lld", &tmp[0], &tmp[1], &tmp[2]);
        sort(tmp, tmp + 3);
        ara[i].a = tmp[0], ara[i].b = tmp[1], ara[i].c = tmp[2];
        mxa = max(mxa, ara[i].a);
        mxb = max(mxb, ara[i].b);
        mxc = max(mxc, ara[i].c);
    }

    ll indx = 0;
    for(ll i = 1; i <= n; i++) {
        if(ara[i].b >= mxa && ara[i].c >= mxb)
            ans[indx++] = i;
    }

    printf("%lld\n", indx);
    for(ll i = 0; i < indx; i++) {
        if(i != 0)
            printf(" ");
        printf("%lld", ans[i]);
    }

    cout << endl;

    return 0;
}