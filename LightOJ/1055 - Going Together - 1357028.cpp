#include <bits/stdc++.h>
using namespace std;
#define ll int
#define pii pair <ll, ll>
#define x first
#define y second
char grid[12][12];
bool vis[10][10][10][10][10][10];
bool istar[12][12];
pii v[3];
struct node {
    pii A, B, C;
    ll lev;
    node(pii _A, pii _B, pii _C, ll _lev) {
        A = _A;
        B = _B;
        C = _C;
        lev = _lev;
    }
};
pii operator +(pii a, pii b) {
    return pii(a.x + b.x, a.y + b.y);
}
ll row[] = {1, -1, 0, 0};
ll col[] = {0, 0, 1, -1};
int main()
{
    ll t, caseno = 0;
    cin >> t;
    while(t--) {
        memset(istar, 0, sizeof(istar));
        memset(vis, 0, sizeof(vis));
          ll n, indx = 0;
        scanf("%d", &n);
        for(ll i = 1; i <= n; i++) {
            for(ll j = 1; j <= n; j++) {
                scanf(" %c", &grid[i][j] );
                  if(grid[i][j] == 'X')
                    istar[i][j] = 1;
                else if(isalpha( grid[i][j] ))
                    v[indx++] =  pii(i, j);
            }
        }
          sort(v, v + indx);
        bool check = 0;
        queue <node> q;
        q.push( node(v[0], v[1], v[2], 0) );
        vis[ v[0].x ][ v[0].y ][ v[1].x ][ v[1].y ][ v[2].x][ v[2].y ] = 1;
        while(!q.empty()) {
            node u = q.front();
            q.pop();
              if( istar[u.A.x][u.A.y] & istar[u.B.x][u.B.y] & istar[u.C.x][u.C.y] ) {
//                cout << u.A.x << "  " << u.A.y << " || " << u.B.x << "  " << u.B.y << "  || " << u.C.x << "  " << u.C.y << endl;
                printf("Case %d: %d\n", ++caseno, u.lev);
                check = 1;
                break;
            }
              for(ll i = 0; i < 4; i++) {
                pii a = u.A + pii(row[i], col[i]);
                pii b = u.B + pii(row[i], col[i]);
                pii c = u.C + pii(row[i], col[i]);
                  if(a.x < 1 || a.y < 1 || a.x > n || a.y > n || grid[a.x][a.y] == '#')
                    a = u.A;
                if(b.x < 1 || b.y < 1 || b.x > n || b.y > n || grid[b.x][b.y] == '#')
                    b = u.B;
                if(c.x < 1 || c.y < 1 || c.x > n || c.y > n || grid[c.x][c.y] == '#')
                    c = u.C;
                  if(a == b && a == c) {
                    a = u.A;
                    b = u.B;
                    c = u.C;
                }
                if(a == b) {
                    a = u.A;
                    b = u.B;
                    if(a == c || b == c)
                        c = u.C;
                }
                if(a == c) {
                    a = u.A;
                    c = u.C;
                    if(a == b || c == b)
                        b = u.B;
                }
                if(b == c) {
                    b = u.B;
                    c = u.C;
                    if(a == b || a == c)
                        a = u.A;
                }
                  if(a > b) swap(a, b);
                if(a > c) swap(a, c);
                if(b > c) swap(b, c);
                  if(vis[a.x][a.y][b.x][b.y][c.x][c.y] == 1)
                    continue;
                  //cout << a.x << "  " << a.y << " || " << b.x << "  " << b.y << "  ||  " << c.x << "  " << c.y << endl;
                vis[a.x][a.y][b.x][b.y][c.x][c.y] = 1;
                q.push( node(a, b, c, u.lev + 1) );
            }
          }
          if(!check)
            printf("Case %d: trapped\n", ++caseno);
    }
      return 0;
}
 
