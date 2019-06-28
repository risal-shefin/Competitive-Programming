#include <bits/stdc++.h>
using namespace std;
#define ll int
map <string, string> par;
map <string, bool> visit;
struct node
{
    string u, v;
    ll c;
};
node graph[55];
bool cmp (node a, node b)
{
    return a.c < b.c;
}
string findpar(string u)
{
    if(par[u] == u)
        return par[u];
    return findpar(par[u]);
}
char ara[55];
int main()
{
    ll t, caseno = 0;
    cin >> t;
    while(t--)
    {
        set <string> city;
        ll n;
        scanf("%d", &n);
        for(ll i = 0; i < n; i++)
        {
            scanf("%s", ara);
            string s(ara, strlen(ara));
            scanf("%s", ara);
            string s1(ara, strlen(ara));
            ll w;
            scanf("%d", &w);
              graph[i].u = s, graph[i].v = s1, graph[i].c = w;
            city.insert(s);
            city.insert(s1);
        }
          ll ans = 0;
        for(ll i = 0; i < n; i++)
        {
            par[ graph[i].u ] = graph[i].u;
            par[ graph[i].v ] = graph[i].v;
        }
          sort(graph, graph + n, cmp);
        ll cnt = 1;
          for(ll i = 0; i < n; i++)
        {
            string u = findpar( graph[i].u);
            string v = findpar( graph[i].v);
              if(u != v)
            {
                ans += graph[i].c;
                par[v] = u;
                cnt++;
            }
        }
          printf("Case %d: ", ++caseno);
        if(cnt != city.size())
            printf("Impossible\n");
        else
            printf("%d\n", ans);
            par.clear();
        visit.clear();
    }
      return 0;
}
 
