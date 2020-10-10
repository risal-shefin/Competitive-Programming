#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll par[100009], sz[100009];

ll findroot(ll u)

{
    if(par[u] == u)
        return u;
    return par[u] = findroot(par[u]);
}

int main()

{
    for(ll i = 1; i <= 100005; i++) {
        par[i] = i;
        sz[i] = 1;
    }

    ll n, m;
    cin >> n >> m;
    ll q;
    cin >> q;
    for(ll i = 1; i <= q; i++) {
        char state;
        scanf(" %c", &state);

        if(state == 'S') {
            ll in;
            scanf("%lld", &in);
            ll u = findroot(in);
            printf("%lld\n", sz[u]);
        }
        else if(state == 'E') {
            ll n1, n2;
            scanf("%lld %lld", &n1, &n2);
            ll u = findroot(n1);
            ll v = findroot(n2);
            if(u != v)
                printf("No\n");
            else
                printf("Yes\n");
        }
        else {
            ll n1, n2;
            scanf("%lld %lld", &n1, &n2);
            ll u = findroot(n1);
            ll v = findroot(n2);
            if( (sz[u] + sz[v]) <= m && u != v) {
                sz[u] += sz[v];
                par[v] = u;
            }
        }

    }

    return 0;
}
