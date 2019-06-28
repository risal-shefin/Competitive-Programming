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
    int row, col, t, caseno = 0;
    int rowset[4] = {0, 0, 1, -1};
    int colset[4] = {1, -1, 0, 0};
    cin >> t;
      while(t--) {
    scanf("%d %d", &row, &col);
      vector <node> v;
      char ara[row + 5][col + 5];
      for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            scanf(" %c", &ara[i][j]);
            if(ara[i][j] == 'a') {
                v.push_back(node(i, j));
            }
              else if(ara[i][j] == 'b') {
                v.push_back(node(i, j));
            }
              else if(ara[i][j] == 'c'){
                v.push_back(node(i, j));
            }
        }
    }
      int mx = INT_MIN;
    for(int i = 0; i < 3; i++) {
        bool vis[25][25] = {};
        int level[25][25] = {};
          queue <node> q;
        q.push(v[i]);
        //cout << v[i].row << "  " << v[i].col << endl;
          while(!q.empty()) {
            node u = q.front();
            q.pop();
              for(int j = 0; j < 4; j++) {
                int tr = u.row + rowset[j];
                int tc = u.col + colset[j];
                  if(tr >= 0 && tc >= 0 && tr < row && tc < col && vis[tr][tc] == 0 && ara[tr][tc] != 'm' && ara[tr][tc] != '#') {
                    level[tr][tc] = level[ u.row ][ u.col ] + 1;
                    //cout << tr << "  " << tc << endl;
                    if( ara[tr][tc] == 'h') {
                        mx = max(mx, level[tr][tc]);
                        goto ended;
                    }
                      q.push(node(tr, tc));
                    vis[tr][tc] = 1;
                }
              }
        }
          ended:;
    }
      printf("Case %d: %d\n", ++caseno, mx);
    }
      return 0;
}
 
