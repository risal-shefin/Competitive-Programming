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

const ll sz = 1e3 + 10;
char grid[sz][sz];

struct node {
    int r, c, gam;
};
queue <node> q[10];

ll s[10], cnt[10], n, m, p, lev[sz][sz];
bool vis[sz][sz];

ll dr[] = {-1, 1, 0, 0};
ll dc[] = {0, 0, 1, -1};

int main()
{
    cin >> n >> m >> p;

    for1(i, p) sl(s[i]);

    for1(i, n) {
        scanf("%s", grid[i]+1);

        for1(j, m) {
            if(grid[i][j] == '.' || grid[i][j] == '#') continue;

            ll now = grid[i][j] - '0';
            q[now].push({i, j, 1});
            vis[i][j] = 1;
            cnt[now]++;
        }
    }

    bool chk;
    ll gam = 1;
    do {
        chk = 0;
        for1(i, p)
        {
            while(!q[i].empty())
            {
                node u = q[i].front();
                if(u.gam != gam) break;
                q[i].pop();

                for0(j, 4)
                {
                    ll nr = u.r + dr[j], nc = u.c + dc[j];

                    if(nr < 1 || nc < 1 || nr > n || nc > m || vis[nr][nc] || grid[nr][nc] == '#')
                        continue;

                    cnt[i]++;
                    vis[nr][nc] = 1, chk = 1;
                    lev[nr][nc] = lev[u.r][u.c] + 1;

                    if(lev[nr][nc] == s[i])
                    {
                        lev[nr][nc] = 0;
                        q[i].push({nr, nc, gam+1});
                    }
                    else
                        q[i].push({nr, nc, gam});
                }
            }
        }
        gam++;
    } while(chk);

    for1(i, p) {
        if(i != 1) pf(" ");
        pf("%lld", cnt[i]);
    }
    pn;

    return 0;
}