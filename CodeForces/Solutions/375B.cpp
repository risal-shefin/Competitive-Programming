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

const ll sz = 5002;
char mat[sz][sz];

int csum[sz][sz];

int main()
{
    ll n, m;
    cin >> n >> m;

    for1(i, n)
        scanf("%s", mat[i]+1);


    for1(i, n) {

        int en = -1;

        rep1(j, m) {
            if(mat[i][j] == '0') {
                en = -1;
                continue;
            }

            if(en == -1) en = j;
            csum[j][j]++, csum[j][en+1]--;
        }
    }

    for1(i, m)
        for1(j, m)
            csum[i][j] += csum[i][j-1];


    ll ans = 0;
    for1(i, m)
        for1(j, m)
            ans = max(ans, (j-i+1)*csum[i][j]);

    cout << ans << EL;

    return 0;
}