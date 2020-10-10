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
vector <ll> g[2][sz];
ll cnt[2][100009], lvl[sz], n;
const ll base = 10001533, mod = 2000004143;

ll hashDfs(ll u, ll p, ll id)
{
    ll h = 1;
    deque <ll> hashSub;
    for(ll v: g[id][u]) {
        if(v == p)
            continue;

        hashSub.pb(hashDfs(v, u, id));
    }
    sort(hashSub.begin(), hashSub.end());

    for(ll val: hashSub)
        h = ((h * base) ^ val) % mod;

    return h;
}

pll findCenter(ll id)
{
    queue <ll> q;
    ll mxl = 0;
    for1(i, n) {
        if(cnt[id][i] == 1) {
            q.push(i);
            lvl[i] = 0;
        }
    }
    while(!q.empty()) {
        ll u = q.front();
        q.pop();

        for(ll v: g[id][u]) {
            cnt[id][v]--;
            if(cnt[id][v] == 1) {
                q.push(v);
                lvl[v] = lvl[u] + 1;
                mxl = max(mxl, lvl[v]);
            }
        }
    }

    pll ret = mp(-1, -1);
    for1(i, n) {
        if(lvl[i] == mxl) {
            if(ret.first == -1)
                ret.first = i;
            else
                ret.second = i;
        }
    }
    return ret;
}

ll getHash(ll id)
{
    pll cen1 = findCenter(id);
    ll root = cen1.first;
    if(cen1.second != -1) {
        root = 0;
        g[id][0].pb(cen1.first), g[id][0].pb(cen1.second);

        for(ll &v : g[id][cen1.first])
            if(v == cen1.second)  v = 0;
        for(ll &v : g[id][cen1.second])
            if(v == cen1.first)  v = 0;

    }
    return hashDfs(root, -1, id);
}

int main()

{
    ll t;
    cin >> t;
    while(t--) {
        sl(n);
        if(n == 1) {
            pf("YES\n");
            continue;
        }

        ll u, v;
        for1(i, n-1) {
            sl(u), sl(v);
            g[0][u].pb(v), g[0][v].pb(u);
            cnt[0][u]++, cnt[0][v]++;
        }
        for1(i, n-1) {
            sl(u), sl(v);
            g[1][u].pb(v), g[1][v].pb(u);
            cnt[1][u]++, cnt[1][v]++;
        }

        ll h1 = getHash(0), h2 = getHash(1);
        if(h1 == h2)
            pf("YES\n");
        else
            pf("NO\n");

        for0(i, (n+1)) {
            g[0][i].clear(), g[1][i].clear();
            cnt[0][i] = cnt[1][i] = 0;
        }
    }

    return 0;
}
