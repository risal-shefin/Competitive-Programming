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

ll mat[502][502];

int main()

{
    ll r, c;
    sl(r), sl(c);
    if(r == 1 && c == 1) {
        pf("0\n");
        return 0;
    }
    if(r == 1) {
        for(ll i = 1; i <= c; i++) {
            if(i != 1)
                pf(" ");
            pf("%lld", i+1);
        }
        pn;
        return 0;
    }
    if(c == 1) {
        for(ll i = 1; i <= r; i++) {
            pf("%lld\n", i+1);
        }
        return 0;
    }

    ll lim = r + c, mx = 0;
    ll now = lim;
    forn(i, r) {
        forn(j, c) {
            mat[i][j] = now;
        }
        now--;
    }

    for(ll i = 2; i <= c; i++) {
        for(ll j = 1; j <= r; j++)
            mat[j][i] = mat[j][i] * now;

        now--;
    }

    forn(i, r) {
        forn(j, c) {
            if(j != 1)
                pf(" ");
            pf("%lld", mat[i][j]);
        }
        pn;
    }


    return 0;
}