#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct node {
    ll i, j, lev;
    node(ll _i, ll _j, ll _lev) {
        i = _i;
        j = _j;
        lev = _lev;
    }
};
ll lev[105][12][12], ct[105][12][12], lim, r, c, indx;
char grid[12][12];
ll row[] = {1, 1, -1, -1, 2, 2, -2, -2};
ll col[] = {2, -2, 2, -2, 1, -1, 1, -1};
queue <node> q;
void solve(ll rw, ll cl, ll lv, ll cnt)
{
    //cout << rw << "  " << cl << endl;
    if(rw < 1 || cl < 1 || rw > r || cl > c)
        return;
    if(cnt > lim)
        return;
//    if(indx == 5 && rw == 2 && cl == 3)
//        cout << 123 << "  " << ct[indx][rw][cl] << endl;;
    if(ct[indx][rw][cl] <= cnt && ct[indx][rw][cl] != -1)
        return;
      ct[indx][rw][cl] = cnt;
    if(lev[indx][rw][cl] == 0) {
        lev[indx][rw][cl] = lv;
        q.push( node(rw, cl, lv) );
    }
      for(ll i = 0; i < 8; i++)
        solve(rw + row[i], cl + col[i], lv, cnt + 1);
}
int main()
{
    ll t, caseno = 0;
    cin >> t;
    while(t--) {
        memset(lev, 0, sizeof(lev));
        memset(ct, -1, sizeof(ct));
        scanf("%lld %lld", &r, &c);
        for(ll i = 1; i <= r; i++)
            scanf("%s", grid[i] + 1);
          indx = 0;
        for(ll i = 1; i <= r; i++) {
            for(ll j = 1; j <= c; j++) {
                if(grid[i][j] == '.')
                    continue;
                  q.push( node(i, j, 1) );
                lev[indx][i][j] = 1;
                ct[indx][i][j] = 0;
                lim = grid[i][j] - '0';
                  while(!q.empty()) {
                    node u = q.front();
                    q.pop();
                      for(ll k = 0; k < 8; k++) {
                        ll nr = u.i + row[k];
                        ll nc = u.j + col[k];
                          solve(nr, nc, u.lev + 1, 1);
                    }
                }
                  indx++;
             }
        }
          bool chk = 1;
        ll mn = 1LL << 60;
        for(ll i = 1; i <= r; i++) {
            for(ll j = 1; j <= c; j++) {
                chk = 1;
                ll ans = 0;
                for(ll k = 0; k < indx; k++) {
                    if(lev[k][i][j] == 0) {
                        chk = 0;
                        break;
                    }
                    else
                        ans += (lev[k][i][j] - 1);
                      //cout << k << " || " << i << " " << j << " || " << lev[k][i][j] - 1 <<  endl;
                }
                  if(chk)
                    mn = min(mn, ans);
            }
        }
          printf("Case %lld: ", ++caseno);
        if(mn == (1LL << 60))
            printf("-1\n");
        else
            printf("%lld\n", mn);
    }
      return 0;
}
 
