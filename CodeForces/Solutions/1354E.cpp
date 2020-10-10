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

const ll sz = 5009;
vector <ll> g[sz], comp[2][sz];
ll col[sz], val[2][sz], idx, ans[sz], whoTwo[sz];
ll n, m, n1, n2, n3;
int dp[sz][sz];

pll bfs(ll src)
{
    comp[0][idx].pb(src);
    col[src] = 0;
    queue <ll> q;
    q.push(src);

    while(!q.empty()) {
        ll u = q.front();
        q.pop();

        for(ll &v : g[u]) {
            if(col[v] == -1) {
                col[v] = col[u] ^ 1;
                q.push(v);

                comp[ col[v] ][idx].pb(v);
            }
            else if(col[v] == col[u])
                return mp(-1, -1);
        }
    }

    return mp(comp[0][idx].size(), comp[1][idx].size());
}

bool solve(ll pos, ll twoTaken)
{
    //cout << pos << " || " << twoTaken << endl;
    if(pos > idx)
        return twoTaken == n2;

    int &ret = dp[pos][twoTaken];
    if(ret != -1)
        return ret;

    bool rt = 0;
    for0(i, 2) rt |= solve(pos+1, twoTaken + val[i][pos]);
    return ret = rt;
}

void assign_solve(ll pos, ll twoTaken)
{
    if(pos > idx)
        return;

    for0(i, 2) {
        if(solve(pos+1, twoTaken + val[i][pos])) {
            whoTwo[pos] = i;
            assign_solve(pos+1, twoTaken + val[i][pos]);
            return;
        }
    }
}

int main()
{
    cin >> n >> m >> n1 >> n2 >> n3;

    for1(i, m) {
        ll u, v;
        sl(u), sl(v);

        g[u].pb(v);
        g[v].pb(u);
    }

    ms(col, -1);
    for1(i, n) {
        if(col[i] != -1)
            continue;

        ++idx;
        pll ret = bfs(i);
        if(ret.first == -1) {
            cout << "NO" << EL;
            return 0;
        }

        val[0][idx] = ret.first;
        val[1][idx] = ret.second;
    }

    ms(dp, -1);
    bool got = solve(1, 0);
    if(!got) {
        cout << "NO" << EL;
        return 0;
    }

    assign_solve(1, 0);
    for1(i, idx) {
        ll nowTwo = whoTwo[i];
        for(ll &u : comp[nowTwo][i]) ans[u] = 2;

        for(ll &u : comp[nowTwo ^ 1][i]) {
            if(n1 != 0) ans[u] = 1, n1--;
            else ans[u] = 3;
        }
    }

    cout << "YES" << EL;
    for1(i, n) {
        pf("%lld", ans[i]);
    }
    pn;

    return 0;
}