#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

ll d1[1000009], d2[1000009];
struct node {
    ll u, c;
};

bool operator <(node a, node b)

{
    return a.c > b.c;
}

vector <node> g[1000009], rev[1000009];

int main()

{
    ll t;
    cin >> t;
    while(t--) {
        for(ll i = 1; i <= 1000005; i++) {
            d1[i] = 1e18;
            d2[i] = 1e18;
            g[i].clear();
            rev[i].clear();
        }

        ll n, q;
        scanf("%lld %lld", &n, &q);

        for(ll i = 1; i <= q; i++) {
            ll u, v, c;
            scanf("%lld %lld %lld", &u, &v, &c);
            g[u].pb({v, c});
            rev[v].pb({u, c});
        }

        priority_queue <node> pq;
        pq.push({1, 0});
        d1[1] = 0;
        while(!pq.empty()) {
            node u = pq.top();
            pq.pop();

            if(d1[u.u] != u.c)
                continue;

            for(node v: g[u.u]) {
                if(u.c + v.c < d1[v.u]) {
                    d1[v.u] = u.c + v.c;
                    pq.push({v.u, d1[v.u]});
                }
            }
        }

        pq.push({1, 0});
        d2[1] = 0;
        while(!pq.empty()) {
            node u = pq.top();
            pq.pop();

            if(d2[u.u] != u.c)
                continue;

            for(node v: rev[u.u]) {
                if(u.c + v.c < d2[v.u]) {
                    d2[v.u] = u.c + v.c;
                    pq.push({v.u, d2[v.u]});
                }
            }
        }

        ll ans = 0;
        for(ll i = 1; i <= n; i++)
            ans += d1[i] + d2[i];

        printf("%lld\n", ans);
    }

    return 0;
