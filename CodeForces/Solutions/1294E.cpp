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

vector < vector <ll> > mat, base;
ll cnt[200009], pos[200009];

int main()

{
    ll n, m;
    sl(n), sl(m);
    mat.resize(n);
    base.resize(n);
    for0(i, n) {
        mat[i].resize(m);
        base[i].resize(m);
    }

    ll idx = 1;
    for0(i, n) {
        for0(j, m) {
            base[i][j] = idx++;
        }
    }

    for0(i, n) {
        for0(j, m) {
            sl(mat[i][j]);
        }
    }

    //cout << mat[0][0] << endl;

    ll ans = 0;
    ms(pos, -1);
    for(ll j = 0; j < m; j++) {

        for0(i, n) pos[ base[i][j] ] = i;
        for0(i, n) {
            if(pos[ mat[i][j] ] == -1)
                continue;

            ll goal = pos[ mat[i][j] ];
            ll cycle = (i - goal);
            if(cycle < 0)
                cycle += n;

            cnt[cycle]++;
        }

        ll cst = inf;
        for0(i, n)  cst = min(cst, i + (n - cnt[i]));
        ans += cst;

        for0(i, n) pos[ base[i][j] ] = -1, cnt[i] = 0;
    }

    pf("%lld\n", ans);

    return 0;
}