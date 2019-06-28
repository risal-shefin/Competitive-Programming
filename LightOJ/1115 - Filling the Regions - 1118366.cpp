#include <bits/stdc++.h>
using namespace std;
struct point {
    int row, col;
    point(int r, int c) {
        row = r;
        col = c;
    }
};
int rowset[] = {1, -1, 0, 0};
int colset[] = {0, 0, -1, 1};
int n, m;
char grid[55][55];
void bfs(char c)
{
    bool visit[55][55] = {};
    queue <point> q;
      for(int i = 0; i < m; i++) {
        if(grid[i][0] != c) {
            visit[i][0] = 1;
            q.push(point(i, 0));
        }
          if(grid[i][n - 1] != c) {
            visit[i][n - 1] = 1;
            q.push(point(i, n - 1));
        }
    }
      for(int i = 1; i < n - 1; i++) {   // i = 0 && i = n - 1 have been covered by upper loop
        if(grid[0][i] != c) {
            visit[0][i] = 1;
            q.push(point(0, i));
        }
          if(grid[m - 1][i] != c) {
            visit[m - 1][i] = 1;
            q.push(point(m - 1, i));
        }
    }
      while(!q.empty()) {
        point u = q.front();
        q.pop();
          for(int i = 0; i < 4; i++) {
            int rw = u.row + rowset[i];
            int cl= u.col + colset[i];
              if(rw >= 0 && cl >= 0 && rw < m && cl < n) {
                if(visit[rw][cl] == 0 && grid[rw][cl] != c) {
                    visit[rw][cl] = 1;
                    q.push(point(rw, cl));
                }
            }
          }
    }
      for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(visit[i][j] == 0)
                grid[i][j] = c;
        }
    }
}
int main()
{
    //freopen("output.txt", "w", stdout);
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &m, &n);
          for(int i = 0; i < m; i++)
            scanf("%s", grid[i]);
          map <char, bool> checker;
          for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(checker[ grid[i][j] ] == 0 && grid[i][j] != '.') {
                    bfs( grid[i][j] );
                    checker[ grid[i][j] ] = 1;
                }
            }
        }
          printf("Case %d:\n", ++caseno);
        for(int i = 0; i < m; i++)
            printf("%s\n", grid[i]);
      }
      return 0;
}
 
