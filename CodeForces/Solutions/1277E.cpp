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
#define inf (1LL << 62)
#define loop(i, start, stop, inc) for(ll i = start; i <= stop; i += inc)
#define forn(i, stop) for(ll i = 1; i <= stop; i++)
#define rep(i, start) for(ll i = start; i >= 1; i--)
#define ms(n, i) memset(n, i, sizeof(n))
#define casep(n) printf("Case %lld:", ++n)
#define pn printf("\n")
#define pf printf
#define fastio std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
vector <ll> g[200009];
queue <ll> q;
bool vis1[200009], vis2[200009];
 
int main()
 
{
    ll t;
    sl(t);
    while(t--) {
        ll n, m, a, b;
        sl(n), sl(m), sl(a), sl(b);
 
        forn(i, m) {
            ll u, v;
            sl(u), sl(v);
            g[u].pb(v);
            g[v].pb(u);
        }
 
        q.push(a);
        vis1[a] = 1;
        while(!q.empty()) {
            ll u = q.front();
            q.pop();
 
            for(ll v : g[u]) {
                if(vis1[v] || v == b)
                    continue;
 
                vis1[v] = 1;
                q.push(v);
            }
        }
 
        q.push(b);
        vis2[b] = 1;
        while(!q.empty()) {
            ll u = q.front();
            q.pop();
 
            for(ll v : g[u]) {
                if(vis2[v] || v == a)
                    continue;
 
                vis2[v] = 1;
                q.push(v);
            }
        }
 
        ll p1 = 0, p2 = 0;
        forn(i, n) {
            if(vis1[i] == 1 && vis2[i] == 1)
                continue;
 
            if(vis1[i])
                p1++;
            if(vis2[i])
                p2++;
        }
 
        p1--, p2--;
 
        ll ans = p1*p2;
        pf("%lld\n", ans);
 
        forn(i, n) {
            g[i].clear();
            vis1[i] = 0, vis2[i] = 0;
        }
    }
 
    return 0;
}