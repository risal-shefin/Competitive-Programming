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
#define for1(i, stop) for(ll i = 1; i <= stop; i++)
#define for0(i, stop) for(ll i = 0; i < stop; i++)
#define rep1(i, start) for(ll i = start; i >= 1; i--)
#define rep0(i, start) for(ll i = (start-1); i >= 0; i--)
#define ms(n, i) memset(n, i, sizeof(n))
#define casep(n) printf("Case %lld:", ++n)
#define pn printf("\n")
#define pf printf
#define fastio std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const ll sz = 5e5 + 10;

struct node {
    ll u, v, w;
} edge[sz];

struct node2 {
    ll u, v, id;
};
vector <node2> wedge[sz], wqry[sz];
vector <ll> weights;

ll par[sz], rnk[sz];
bool no[sz];
stack <pll> parTrack, rnkTrack;

ll findpar(ll u)
{
    if(par[u] == u)
        return u;
    return findpar(par[u]);
}

bool join(ll u, ll v, bool track)
{
    ll pu = findpar(u), pv = findpar(v);
    if(pu == pv)
        return false;

    if(rnk[pu] < rnk[pv])   swap(pu, pv);

    if(track == true) {
        parTrack.push( mp(pv, pv) );
        rnkTrack.push( mp(pu, rnk[pu]) );
    }

    if(rnk[pu] == rnk[pv])  rnk[pu]++;
    par[pv] = pu;

    return true;
}

int main()

{
    ll n, m;
    sl(n), sl(m);
    for1(i, m) {
        sl(edge[i].u), sl(edge[i].v), sl(edge[i].w);
        wedge[ edge[i].w ].pb({edge[i].u, edge[i].v, i});

        weights.pb(edge[i].w);
    }
    sort(weights.begin(), weights.end());
    weights.erase(unique(weights.begin(), weights.end()), weights.end());

    ll q;
    sl(q);
    for1(i, q) {
        ll k, indx;
        sl(k);

        for1(j, k) {
            sl(indx);
            wqry[ edge[indx].w ].pb({edge[indx].u, edge[indx].v, i});
        }
    }

    for1(i, n)
        par[i] = i, rnk[i] = 0;

    for(ll i = 0; i < weights.size(); i++) {
        ll w = weights[i];

        for(ll j = 0; j < wqry[w].size(); ) {
            ll stop = j;
            while(stop+1 < wqry[w].size() && wqry[w][stop+1].id == wqry[w][j].id)
                stop++;

            for(ll k = j; k <= stop; k++) {
                bool ret = join(wqry[w][k].u, wqry[w][k].v, 1);
                if(ret == false)
                    no[ wqry[w][k].id ] = 1;
            }

            while(!parTrack.empty()) {
                pll u = parTrack.top();
                parTrack.pop();

                par[u.first] = u.second;
            }
            while(!rnkTrack.empty()) {
                pll u = rnkTrack.top();
                rnkTrack.pop();

                rnk[u.first] = u.second;
            }

            j = stop + 1;
        }

        for(ll j = 0; j < wedge[w].size(); j++)
            join(wedge[w][j].u, wedge[w][j].v, 0);
    }

    for1(i, q)
        no[i] == true ? pf("NO\n") : pf("YES\n");

    return 0;
}