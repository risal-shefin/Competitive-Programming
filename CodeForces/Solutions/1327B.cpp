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

const ll sz = 1e5 + 10;
vector <ll> d[sz];
bool vis[sz];

int main()
{
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        sl(n);
        for1(i, n) {
            ll inp;
            sl(inp);

            for1(j, inp) {
                ll s;
                sl(s);
                d[i].pb(s);
            }
        }

        ll blank=-1, son;
        for1(i, n) {
            bool got = 0;
            for(ll s : d[i]) {
                if(!vis[s]) {
                    vis[s] = got = 1;
                    break;
                }
            }
            if(!got) blank = i;
        }

        for1(i, n) {
            if(!vis[i])
                son = i;
        }

        if(blank == -1)
            pf("OPTIMAL\n");
        else
            pf("IMPROVE\n%lld %lld\n", blank, son);

        for1(i, n) {
            d[i].clear();
            vis[i] = 0;
        }
    }

    return 0;
}