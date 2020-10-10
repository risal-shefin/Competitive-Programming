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

const ll sz = 1e3 + 10;
bool mat[sz][sz];
ll node = 3, digit[sz], lim;

void build(ll pos, ll now, ll prvL, ll prvR, bool done)
{
    ll start = node, stop, need;

    if(pos == now) need = digit[now];
    else {
        if(done) need = 10;
        else need = 1;
    }
    stop = start + need - 1;

    for(ll i = start; i <= stop; i++) {
        for(ll j = prvL; j <= prvR; j++)
            mat[i][j] = mat[j][i] = 1;

        if(pos == 1) mat[i][2] = mat[2][i] = 1;
    }
    node = stop + 1;

    if(pos == 1) return;

    build(pos-1, now, start, stop, done | (pos==now) );
}

int main()
{
    ll k, dg = 0;
    cin >> k;

    while(k) {
        digit[++dg] = k % 10;
        k /= 10;
    }

    lim = dg;
    rep1(i, dg) {
        if(digit[i] == 0)
            continue;

        build(lim, i, 1, 1, 0);
    }

    cout << node-1 << EL;
    for1(i, node-1) {
        for1(j, node-1) {
            pf("%c", mat[i][j]? 'Y' : 'N');
        }
        pn;
    }

    return 0;
}