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

ll way[12][1009][1009], cs[1009][1009];
/*
 * way[i][j][k] = Total number of ways if we put j in
   "a" array and "j,j+1,j+2,,,,,k" in "b" array in ith index.
 *
 * cs[j][k] for a position i = way[i][1][k] + way[i][2][k] +
   ...........+ way[i][k][k]
*/
const ll mod = 1e9 + 7;

int main()

{
    ll n, m;
    cin >> n >> m;

    for1(i, n) {
        for(ll j = i; j <= n; j++)
            way[m][i][j] = 1 + way[m][i][j-1];
    }

    for1(i, n) {
        for(ll j = 1; j <= i; j++)
            cs[j][i] = (way[m][j][i] + cs[j - 1][i]) % mod;
    }

    rep1(i, m-1) {

        for1(j, n) {
            for(ll k = j; k <= n; k++) {
                way[i][j][k] = (cs[k][k] - cs[j-1][k]) % mod;
                if(way[i][j][k] < 0)
                    way[i][j][k] += mod;

                way[i][j][k] = (way[i][j][k] + way[i][j][k-1]) % mod;
            }
        }

        for1(j, n) {
            for(ll k = 1; k <= j; k++)
                cs[k][j] = (way[i][k][j] + cs[k-1][j]) % mod;
        }
    }

    ll ans = 0;
    for1(i, n) {
        ans = (ans + way[1][i][n]) % mod;
    }

    cout << ans << endl;

    return 0;
}