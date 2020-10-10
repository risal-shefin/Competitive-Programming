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
char mat[sz][sz];
ll lev[sz][sz], cnt[sz*sz], mel, r, c;

ll dr[] = {1, -1, 0, 0};
ll dc[] = {0, 0, 1, -1};

inline bool isValid(ll row, ll col)
{
    if(row < 1 || col < 1 || row > r || col > c || lev[row][col] != 0 || mat[row][col] == 'T')
        return 0;

    return 1;
}

int main()
{
    #define row first
    #define col second

    cin >> r >> c;
    for1(i, r)
        scanf("%s", mat[i]+1);


    pii ext;
    for1(i, r) {
        for1(j, c)
            if(mat[i][j] == 'E')
                ext = mp(i, j);
    }

    lev[ext.row][ext.col] = 1;
    queue <pii> q;
    q.push(ext);

    while(!q.empty()) {
        pii u = q.front();
        q.pop();

        for0(i, 4) {
            ll nr = u.row + dr[i];
            ll nc = u.col + dc[i];

            if(!isValid(nr, nc))
                continue;

            lev[nr][nc] = lev[u.row][u.col] + 1;
            q.push(mp(nr, nc));

            if(mat[nr][nc] == 'S')
                mel = lev[nr][nc];
            else
                cnt[ lev[nr][nc] ] += (mat[nr][nc] - '0');
        }
    }

    ll ans = 0;
    for1(i, mel) ans += cnt[i];

    cout << ans << EL;

    return 0;
}