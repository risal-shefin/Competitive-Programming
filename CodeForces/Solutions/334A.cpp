#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

int main()

{
    ll n;
    cin >> n;
    ll tot = n * n;
    vector <ll> v[n + 5];

    ll id = 1, pls = 1;
    for(ll i = 1; i <= tot; i++) {
        v[id].pb(i);
        id += pls;
        if(id > n) {
            pls = -1;
            id = n;
        }
        if(id == 0) {
            pls = 1;
            id = 1;
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < v[n].size(); j++) {
            printf("%lld", v[i][j]);
            if(j != v[i].size() - 1)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}