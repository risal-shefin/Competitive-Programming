#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll n, ara[2009], len[2009], k, ans = 0;

struct node {
    ll num;
    ll id;
} ara2[2009];

bool cmp(node a, node b) {
    return a.num > b.num;
}

bool cmp2(node a, node b) {
    return a.id < b.id;
}

int main()

{
    cin >> n >> k;
    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &ara[i]);
        ara2[i].id = i;
        ara2[i].num = ara[i];
    }

    sort(ara2 + 1, ara2 + n + 1, cmp);
    sort(ara2 + 1, ara2 + k + 1, cmp2);
    ll sum = 0;
    for(ll i = 1; i <= k; i++) {
        sum += ara2[i].num;

        if(i == k)
            len[i] = n - ara2[i].id + 1;
        else if(i == 1)
            len[i] = ara2[i + 1].id - 1;
        else
            len[i] = ara2[i + 1].id - ara2[i].id;
    }

    cout << sum << endl;
    if(k == 1)
        len[1] = n;

    for(ll i = 1; i <= k; i++) {
        if(i != 1)
            printf(" ");
        printf("%lld", len[i]);
    }

    cout << endl;


    return 0;
}