#include <bits/stdc++.h>
using namespace std;
struct node {
    int row;
    int col;
      node(int r, int c) {
        row = r;
        col = c;
    }
};
int main()
{
    int t, caseno = 0;
    scanf("%d", &t);
    int rowset[] = {0, 0, 1, -1};
    int colset[] = {-1, 1, 0, 0};
    int level[15][15];
    bool visit[15][15] = {};
      while(t--) {
        int n;
        scanf("%d", &n);
        char ara[n + 5][n + 5];
          int srow = -1, scol = -1;
        char mx = 'A';
          for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                scanf(" %c", &ara[i][j]);
                //cout << i << "  " << j << endl;
                  if(ara[i][j] == 'A') {
                    srow = i;
                    scol = j;
                }
                  if(ara[i][j] >= 'A' && ara[i][j] <= 'Z')
                    mx = max(mx, ara[i][j]);
            }
        }
          printf("Case %d: ", ++caseno);
          if(srow == -1) {
            printf("Impossible\n");
            continue;
        }
          if(mx == 'A') {
            printf("0\n");
            continue;
        }
            bool checker = 0;
        queue <node> q;
        q.push(node(srow, scol));
        char dest = 'B';
        memset(level, 0, sizeof(level));
        memset(visit, 0, sizeof(visit));
        level[srow][scol] = 0;
        visit[srow][scol] = 1;
          while(!q.empty()) {
            newstart:
            node u = q.front();
            q.pop();
              for(int i = 0; i < 4; i++) {
                  int tmprow = u.row + rowset[i];
                int tmpcol = u.col + colset[i];
                  if(tmprow >= 0 && tmprow < n) {
                    if(tmpcol >= 0 && tmpcol < n) {
                          if(visit[tmprow][tmpcol] == 1)
                            continue;
                          if(ara[tmprow][tmpcol] >= 'A' && ara[tmprow][tmpcol] <= 'Z') {
                              if(ara[tmprow][tmpcol] == dest) {
                                level[tmprow][tmpcol] = level[u.row][u.col] + 1;
                                memset(visit, 0, sizeof(visit));
                                ara[tmprow][tmpcol] = '.';
                                  if(dest == 'B')
                                    ara[srow][scol] = '.';
                                while(!q.empty())
                                    q.pop();
                                  if(dest == mx) {
                                    printf("%d\n", level[tmprow][tmpcol]);
                                    checker = 1;
                                    goto over;
                                }
                                q.push(node(tmprow, tmpcol));
                                visit[tmprow][tmpcol] = 1;
                                dest++;
                                goto newstart;
                            }
                        }
                          else if(ara[tmprow][tmpcol] != '#') {
                            q.push(node(tmprow, tmpcol));
                            level[tmprow][tmpcol] = level[u.row][u.col] + 1;
                            visit[tmprow][tmpcol] = 1;
                        }
                    }
                  }
                }
          }
          printf("Impossible\n");
        over:;
      }
      return 0;
}
 
