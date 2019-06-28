#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        int n, r;
        scanf("%d %d", &n, &r);
        vector <int> graph[n + 5];
          for(int i = 1; i <= r; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
          int s, d;
        scanf("%d %d", &s, &d);
          int dst1[n + 5], dst2[n + 5];
        bool visit[n + 5];
        for(int i = 0; i < n + 2; i++) {
            dst1[i] = 1e7;
            dst2[i] = 1e7;
        }
        dst1[s] = 0;
        dst2[d] = 0;
        memset(visit, 0, sizeof(visit));
          queue <int> q;
        q.push(s);
          while(!q.empty()) {
            int u = q.front();
            q.pop();
              if(visit[u] == 1)
                continue;
            visit[u] = 1;
              for(int i = 0; i < graph[u].size(); i++) {
                if(dst1[ graph[u][i] ] > dst1[u] + 1 && visit[ graph[u][i] ] == 0) {
                    dst1[ graph[u][i] ] = dst1[u] + 1;
                    q.push(graph[u][i]);
                }
            }
          }
          memset(visit, 0, sizeof(visit));
        q.push(d);
        while(!q.empty()) {
            int u = q.front();
            q.pop();
              if(visit[u] == 1)
                continue;
            visit[u] = 1;
              for(int i = 0; i < graph[u].size(); i++) {
                if(dst2[ graph[u][i] ] > dst2[u] + 1 && visit[ graph[u][i] ] == 0) {
                    dst2[ graph[u][i] ] = dst2[u] + 1;
                    q.push(graph[u][i]);
                }
            }
          }
          int ans = INT_MIN;
        for(int i = 0; i < n; i++) {
            int d = dst1[i] + dst2[i];
            ans = max(ans, d);
        }
          printf("Case %d: %d\n", ++caseno, ans);
    }
      return 0;
}
 
