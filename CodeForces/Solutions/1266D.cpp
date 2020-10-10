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

ll ase[100009];
struct node {
    ll u, v, d;
};
vector <node> ans;
vector <pll> gain, loss;

int main()

{
    ll n, m;
    sl(n), sl(m);
    forn(i, m) {
        ll u, v, d;
        sl(u), sl(v), sl(d);
        ase[u] -= d;
        ase[v] += d;
    }

    forn(i, n) {
        if(ase[i] > 0)
            gain.pb(mp(i, ase[i]));
        else if(ase[i] < 0)
            loss.pb(mp(i, -ase[i]));
    }

    ll idg = 0, idl = 0;
    while(idg < gain.size() && idl < loss.size()) {

        ll d = min(gain[idg].second, loss[idl].second);
        ans.pb({loss[idl].first, gain[idg].first, d});

        gain[idg].second -= d;
        loss[idl].second -= d;

        if(gain[idg].second == 0)
            idg++;
        if(loss[idl].second == 0)
            idl++;
    }

    cout << ans.size() << endl;
    for(node nd: ans)
        pf("%lld %lld %lld\n", nd.u, nd.v, nd.d);

    return 0;
}