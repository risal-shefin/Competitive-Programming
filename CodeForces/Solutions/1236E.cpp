// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,fma")

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
#define all(v) v.begin(), v.end()
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
#define EL '\n'
#define fastio std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const ll sz = 3e5 + 10, ad = 1e5 + 2;
ll n, m, g, node[2];
ll par[2][sz], Left[sz], Right[sz], nodeOf[2][sz], exact[2][sz];

ll findPar(bool typ, ll u)
{
    if(par[typ][u] == u) return u;
    return par[typ][u] = findPar(typ, par[typ][u]);
}

inline void create(bool typ, ll v)
{
    if(nodeOf[typ][v] != 0) return;

    ++node[typ];
    nodeOf[typ][v] = node[typ];
    par[typ][ node[typ] ] = node[typ];

    if(exact[typ][v] == -1) exact[typ][v] = node[typ];

    if(typ == 0) Left[ node[typ] ] = max(1LL, v - (m+1));
    else    Right[ node[typ] ] = min(n, (v-ad) + (m+1));
}

int main()
{
    cin >> n >> m;

    if(n == 1) {
        cout << 0 << endl;
        return 0;
    }

    ms(exact, -1);
    for1(i, m) {
        sl(g);

        ll lstart = g+i, rstart = g-i + ad;
        create(0, lstart), create(1, rstart);

        ll lnxt = lstart+1, rnxt = rstart-1;
        create(0, lnxt), create(1, rnxt);

        par[0][ nodeOf[0][lstart] ] = findPar(0, nodeOf[0][lnxt]);
        par[1][ nodeOf[1][rstart] ] = findPar(1, nodeOf[1][rnxt]);

        nodeOf[0][lstart] = nodeOf[1][rstart] = 0;
    }

    ll ans = 0;
    for1(start, n) {
        create(0, start), create(1, start+ad);

        ll pl = findPar(0, exact[0][start]), pr = findPar(1, exact[1][start + ad]);

        ans += max(0LL, Right[pr] - Left[pl] + 1);
    }

    cout << ans << EL;

    return 0;
}