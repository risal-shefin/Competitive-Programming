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

const ll sz = 52, mod = 1e9 + 7;
ll lev[sz][sz][2], dp[sz][sz][2], nCr[sz][sz];

struct node {
    int one, two;
    bool side;
};
vector <node> par[sz][sz][2];

ll one, two, n, k;

ll bfs()
{
    for0(i, sz)
        for0(j, sz)
            lev[i][j][0] = lev[i][j][1] = inf;

    queue <node> q;
    q.push({one, two, 0});
    lev[one][two][0] = 0;

    while(!q.empty()) {
        node u = q.front();
        q.pop();

        ll none = u.one, ntwo = u.two, lv = lev[u.one][u.two][u.side];
        if(u.side) none = one - none, ntwo = two - ntwo;

        for(ll i = 0; i <= none; i++) {
            if(i > k) break;

            for(ll j = 0; j <= ntwo; j++) {
                if(i == 0 && j == 0) continue;
                if(i + 2*j > k) break;

                ll nxone, nxtwo;
                if(u.side) nxone = u.one + i, nxtwo = u.two + j;
                else    nxone = u.one - i, nxtwo = u.two - j;

                if(lev[nxone][nxtwo][u.side^1] > lv + 1) {
                    q.push({nxone, nxtwo, u.side^1});
                    lev[nxone][nxtwo][u.side^1] = lv + 1;
                    par[nxone][nxtwo][u.side^1].pb(u);
                }
                else if(lev[nxone][nxtwo][u.side^1] == lv + 1) {
                    lev[nxone][nxtwo][u.side^1] = lv + 1;
                    par[nxone][nxtwo][u.side^1].pb(u);
                }
            }
        }
    }

    if(lev[0][0][1] == inf) return -1;
    return lev[0][0][1];
}

ll solve(ll on, ll tw, bool side)
{
    if(par[on][tw][side].size() == 0) return 1;
    ll &ret = dp[on][tw][side];
    if(ret != -1)
        return ret;

    ll rt = 0, none = on, ntwo = tw;
    if(side) none = one - none, ntwo = two - ntwo;

    for(node &nd : par[on][tw][side]) {
        ll way, passOne = abs(on - nd.one), passTwo = abs(tw - nd.two);

        way = (nCr[none][passOne] * nCr[ntwo][passTwo]) % mod;

        way = (way * solve(nd.one, nd.two, nd.side)) % mod;
        rt = (rt + way) % mod;
    }

    return ret = rt;
}

int main()
{
    nCr[0][0] = 1;
    for(ll i = 1; i < sz; i++) {
        nCr[i][0] = nCr[i][i] = 1;
        for(ll j = 1; j < i; j++)
            nCr[i][j] = (nCr[i-1][j-1] + nCr[i-1][j]) % mod;
    }

    cin >> n >> k;
    k /= 50;
    for1(i, n) {
        ll w; sl(w);
        if(w == 50) one++;
        else two++;
    }

    ll ride = bfs();
    if(ride == -1) {
        cout << -1 << EL << 0 << EL;
        return 0;
    }

    ms(dp, -1);
    cout << ride << EL;
    cout << solve(0, 0, 1) << EL;

    return 0;
}