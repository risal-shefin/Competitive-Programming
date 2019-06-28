#include <bits/stdc++.h>
using namespace std;
vector <int> v[10009];
vector <int> topsort;
bool visit[10009];
void dfs(int i)
{
    for(int j = 0; j < v[i].size(); j++) {
        if(visit[ v[i][j] ] == 0) {
            visit[ v[i][j] ] = 1;
            dfs( v[i][j] );
        }
    }
      topsort.push_back(i);
}
void dfs2(int i)
{
    for(int j = 0; j < v[i].size(); j++) {
        if(visit[ v[i][j] ] == 0) {
            visit[ v[i][j] ] = 1;
            dfs2( v[i][j] );
        }
    }
}
int main()
{
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        int n, m, counter = 0;
        set <int> switches;
        scanf("%d %d", &n, &m);
          for(int i = 1; i <= m; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            v[a].push_back(b);
        }
          memset(visit, 0, sizeof(visit));
        for(int i = 1; i <= n; i++) {
            if(visit[i] == 0) {
                visit[i] = 1;
                dfs(i);
            }
        }
          memset(visit, 0, sizeof(visit));
        for(int i = topsort.size() - 1; i >= 0; i--) {
            if(visit[ topsort[i] ] == 0) {
                visit[ topsort[i] ] = 1;
                dfs2( topsort[i] );
                counter++;
            }
        }
          printf("Case %d: %d\n", ++caseno, counter);
        for(int i = 0; i < 10009; i++)
            v[i].clear();
        topsort.clear();
    }
      return 0;
}
 
