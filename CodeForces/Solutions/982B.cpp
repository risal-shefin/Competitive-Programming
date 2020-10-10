#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sl(val) scanf("%lld", &val)
#define inf 2e18
#define pb push_back
vector <ll> v;

struct node {
    ll w;
    ll id;
} ara[200009];

bool cmp(node a, node b)

{
    return  a.w < b.w;
}

ll mark[200009];

int main()

{
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &ara[i].w);
        ara[i].id = i;
    }

    sort(ara + 1, ara + n + 1, cmp);
    string s;
    cin >> s;

    ll in = 1, ex = 1;
    for(ll i = 0; i < s.length(); i++) {

        if(i != 0)
            printf(" ");

        if(s[i] == '0') {
            printf("%lld", ara[in].id);
            v.pb(in);
            in++;
        }

        else {
            ll ans = v[ v.size() - 1 ];
            v.erase(v.end() - 1);
            printf("%lld", ara[ans].id);
        }

    }

    cout << endl;
    return 0;
}