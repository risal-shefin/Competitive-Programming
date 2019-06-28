#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        vector <int> graph[n + 5], dist[n + 5];
          int u, v, d;
        for(int i = 1; i < n; i++) {
            u, v, d;
            scanf("%d %d %d", &u, &v, &d);
            graph[u].push_back(v);
            graph[v].push_back(u);
              dist[u].push_back(d);
            dist[v].push_back(d);
        }
          queue <int> q;
        q.push(0);
        int dst[n + 5], node1, mx = INT_MIN;
        bool visit[n + 5];
        memset(dst, 0, sizeof(dst));
        memset(visit, 0, sizeof(visit));
          while(!q.empty()) {
            int p = q.front();
            q.pop();
              if(visit[p] == 1)
                continue;
            visit[p] = 1;
            int sz = graph[p].size();
              for(int i = 0; i < sz; i++) {
                int point = graph[p][i];
                  if(dst[point] < dst[p] + dist[p][i] && visit[ graph[p][i] ] == 0) {
                    q.push(point);
                    dst[point] = dst[p] + dist[p][i];
                    //cout << dst[point] << endl;
                }
                  if(dst[point] > mx) {
                    mx = dst[point];
                    node1 = point;
                    //cout << dst[point] << endl;
                }
            }
        }
          //cout << node1 << endl;
        q.push(node1);
        int node2, dst1[n + 5];
        mx = INT_MIN;
        memset(dst1, 0, sizeof(dst1));
        memset(visit, 0, sizeof(visit));
          while(!q.empty()) {
            int p = q.front();
            q.pop();
              if(visit[p] == 1)
                continue;
            visit[p] = 1;
            int sz = graph[p].size();
              for(int i = 0; i < sz; i++) {
                int point = graph[p][i];
                  if(dst1[point] < dst1[p] + dist[p][i]  && visit[ graph[p][i] ] == 0) {
                    q.push(point);
                    dst1[point] = dst1[p] + dist[p][i];
                }
                  if(dst1[point] > mx) {
                    mx = dst1[point];
                    node2 = point;
                }
            }
        }
          q.push(node2);
        int dst2[n + 5];
        memset(dst2, 0, sizeof(dst2));
        memset(visit, 0, sizeof(visit));
          while(!q.empty()) {
            int p = q.front();
            q.pop();
              if(visit[p] == 1)
                continue;
            visit[p] = 1;
            int sz = graph[p].size();
              for(int i = 0; i < sz; i++) {
                int point = graph[p][i];
                  if(dst2[point] < dst2[p] + dist[p][i] && visit[ graph[p][i] ] == 0) {
                    q.push(point);
                    dst2[point] = dst2[p] + dist[p][i];
                }
              }
        }
          printf("Case %d:\n", ++caseno);
        for(int i = 0; i < n; i++)
            printf("%d\n", max(dst1[i], dst2[i]));
      }
      return 0;
}
 
