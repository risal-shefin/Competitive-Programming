#define ll long long
vector <ll> graph[100009];

ll table[100009][20], sz[100009], MLOG, n;   /// MLOG = log(n) + 1

void szdfs(ll u, ll p, ll lv)

{
    sz[u] = 1;
    table[u][0] = p;
    for(ll i = 0; i < graph[u].size(); i++) {
        ll nd = graph[u][i];
        if(nd == p)
            continue;

        szdfs(nd, u, lv + 1);
        sz[u] += sz[nd];
    }
}

void build()

{
    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= MLOG; j++) {
            table[i][j] = table[ table[i][j - 1] ][j - 1];
        }
    }
}

ll kth(ll u, ll k)

{
    for(ll i = MLOG; i >= 0; i--) {
        if( (1 << i) <= k) {
            u = table[u][i];
            k -= (1 << i);
        }
    }

    return u;
}
