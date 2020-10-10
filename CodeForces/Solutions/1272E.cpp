#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ull unsigned long long
#define dd double
#define ld long double
#define sl(n) scanf("%lld", &n)
#define si(n) scanf("%d", &n)
#define sd(n) scanf("%lf", &n)
#define pll pair <ll, ll>
#define pii pair <int, int>
#define mp make_pair
#define pb push_back
#define inf (1LL << 50)
#define loop(i, start, stop, inc) for(ll i = start; i <= stop; i += inc)
#define forn(i, stop) for(ll i = 1; i <= stop; i++)
#define rep(i, start) for(ll i = start; i >= 1; i--)
#define ms(n, i) memset(n, i, sizeof(n))
#define casep(n) printf("Case %lld:", ++n)
#define pn printf("\n")
#define pf printf
#define fastio std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
ll ara[200009];
vector <ll> g[200009];
ll dist[200009][2];
queue <ll> q[2];
 
int main()
 
{
    ms(dist, -1);
    ll n;
    sl(n);
    forn(i, n) {
        sl(ara[i]);
 
        if(i - ara[i] >= 1)
            g[i-ara[i]].pb(i);
        if(i+ara[i] <= n)
            g[i+ara[i]].pb(i);
 
        if(ara[i] & 1) {
            q[1].push(i);
            dist[i][1] = 0;
        }
        else {
            q[0].push(i);
            dist[i][0] = 0;
        }
    }
 
    for(ll i = 0; i <= 1; i++) {
 
        while(!q[i].empty()) {
            ll u = q[i].front();
            q[i].pop();
 
            for(ll v : g[u]) {
                if(dist[v][i] == -1) {
                    dist[v][i] = dist[u][i] + 1;
                    q[i].push(v);
                }
            }
        }
 
    }
 
    forn(i, n) {
        if(i != 1)
            pf(" ");
        if(ara[i] & 1)
            pf("%lld", dist[i][0]);
        else
            pf("%lld", dist[i][1]);
    }
    pn;
 
    return 0;
}