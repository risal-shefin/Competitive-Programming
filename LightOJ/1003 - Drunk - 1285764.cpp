#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector <ll> graph[20009];
ll val[20009];
bool vis[20009];
int main()
{
    std::ios_base::sync_with_stdio(false);
    ll t, caseno = 0;
    cin >> t;
    while(t--) {
        map <string, ll> mark;
        ll m, id = 1;
        cin >> m;
          for(ll i = 1; i <= m; i++) {
            string u, v;
            cin >> u >> v;
            if(mark.find(u) == mark.end())
                mark[u] = id++;
            if(mark.find(v) == mark.end())
                mark[v] = id++;
              graph[ mark[u] ].push_back( mark[v] );
              val[ mark[v] ]++;
        }
          queue <ll> q;
        for(ll i = 1; i < id; i++) {
            if(val[i] == 0) {
                q.push(i);
                //cout << i << endl;
            }
        }
          bool flag = 0;
        cout << "Case " << ++caseno << ": ";
          while(!q.empty()) {
            ll u = q.front();
            q.pop();
              vis[u] = 1;
            for(ll i = 0; i < graph[u].size(); i++) {
                  val[ graph[u][i] ]--;
                if(graph[u][i] < 0) {
                    cout << "No" << endl;
                    flag = 1;
                }
                  if(val[ graph[u][i] ] == 0)
                    q.push(graph[u][i]);
            }
          }
          for(ll i = 1; i < id && flag == 0; i++) {
            if(vis[i] == 0) {
                cout << "No" << endl;
                flag = 1;
            }
        }
          if(flag == 0) {
            cout << "Yes" << endl;
        }
          for(ll i = 1; i <= 20009; i++) {
            graph[i].clear();
            val[i] = 0;
            vis[i] = 0;
        }
    }
      return 0;
}
 
