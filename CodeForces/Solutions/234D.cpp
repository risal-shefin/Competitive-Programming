
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
#define inf (1LL << 61)
#define loop(i, start, stop, inc) for(ll i = start; i <= stop; i += inc)
#define for1(i, stop) for(ll i = 1; i <= stop; ++i)
#define for0(i, stop) for(ll i = 0; i < stop; ++i)
#define rep1(i, start) for(ll i = start; i >= 1; --i)
#define rep0(i, start) for(ll i = (start-1); i >= 0; --i)
#define ms(n, i) memset(n, i, sizeof(n))
#define casep(n) printf("Case %lld:", ++n)
#define pn printf("\n")
#define pf printf
#define EL '\n'
#define fastio std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const ll sz = 105;
ll fv[sz], zero[sz], maxx[sz], minn[sz];
bool fav[sz];

char s[20];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ll m, k;
    cin >> m >> k;

    for1(i, k) {
        ll act; sl(act);
        fav[act] = 1;
    }

    ll n;
    sl(n);

    for1(i, n) {
        scanf("%s", s);

        ll sure = 0, d;
        sl(d);

        for1(j, d) {
            ll act; sl(act);

            zero[i] += (act == 0);
            fv[i] += fav[act];

            sure += (act != 0);
        }

        ll rest = d - sure, notFavSure = sure-fv[i], notFavTot = m-k;
        ll notFav = min(rest, notFavTot - notFavSure);
        ll extraFav = rest - notFav;

        maxx[i] = fv[i] + min(k-fv[i], zero[i]);

        minn[i] = fv[i] + extraFav;
    }

    if(n == 1) {
        cout << 0 << EL;
        return 0;
    }

    for1(i, n) {

        ll typ, mx = 0, mnMax = 0;

        for1(j, n) {
            if(i == j)
                continue;

            mx = max(mx, maxx[j]);
            mnMax = max(mnMax, minn[j]);
        }

        if(maxx[i] >= mnMax) typ = 2;
        if(minn[i] >= mx) typ = 0;
        if(maxx[i] < mnMax) typ = 1;

        pf("%lld\n", typ);
    }

    return 0;
}