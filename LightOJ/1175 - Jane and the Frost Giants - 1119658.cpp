#include <bits/stdc++.h>
using namespace std;
struct node {
    int row;
    int col;
    int level;
    node(int r, int c, int l) {
        row = r;
        col = c;
        level = l;
    }
};
    int main()
{
    int t, caseno = 0;
    int rowset[] = {1, -1, 0, 0};
    int colset[] = {0, 0, 1, -1};
    int dist[210][210];
    int fdist[210][210];
    char grid[210][210];
      scanf("%d", &t);
    while(t--) {
        int row, col;
        bool visit[210][210] = {};
        scanf("%d %d", &row, &col);
        queue <node> q, fire;
          for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                scanf(" %c", &grid[i][j]);
                dist[i][j] = INT_MAX;
                fdist[i][j] = INT_MAX;
                  if(grid[i][j] == 'J') {
                    q.push(node(i, j, 1));
                }
                  if(grid[i][j] == 'F') {
                    fire.push(node(i, j, 1));
                }
            }
        }
          while(!fire.empty()) {
            node f = fire.front();
            fire.pop();
              for(int j = 0; j < 4; j++) {
                int tr = f.row + rowset[j];
                int tc = f.col + colset[j];
                  if(tr >= 0 && tc >= 0 && tr < row && tc < col && grid[tr][tc] != '#' && f.level + 1 < fdist[tr][tc]) {
                    fire.push(node(tr, tc, f.level + 1));
                    fdist[ tr ][ tc ] = f.level + 1;
                }
            }
          }
        //memset(visit, 0, sizeof(visit));
          while(!q.empty() ) {
            node u = q.front();
            q.pop();
              if(visit[u.row][u.col] == 1)
                continue;
              visit[u.row][u.col] = 1;
            dist[u.row][u.col] = u.level;
              for(int j = 0; j < 4; j++) {
                int tr = u.row + rowset[j];
                int tc = u.col + colset[j];
                  if(tr >= 0 && tc >= 0 && tr < row && tc < col && grid[tr][tc] != '#' && grid[tr][tc] != 'F' && visit[tr][tc] == 0) {
                    q.push(node(tr, tc, u.level + 1));
                }
            }
          }
          int ans = INT_MAX;
        for(int i = 0; i < row; i++) {
            if(dist[i][0] < fdist[i][0]) {
                ans = min(ans, dist[i][0]);
            }
              if(dist[i][col - 1] < fdist[i][col - 1]) {
                ans = min(ans, dist[i][col - 1]);
            }
        }
          for(int i = 0; i < col; i++) {
              if(dist[0][i] < fdist[0][i]) {
                ans = min(ans, dist[0][i]);
            }
              if(dist[row - 1][i] < fdist[row - 1][i]) {
                ans = min(ans, dist[row - 1][i]);
            }
        }
          if(ans != INT_MAX)
            printf("Case %d: %d\n", ++caseno, ans);
        else
            printf("Case %d: IMPOSSIBLE\n", ++caseno);
      }
      return 0;
}
 
