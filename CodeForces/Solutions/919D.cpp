#include <bits/stdc++.h>
using namespace std;

#define ll int
char str[300009];
ll val[300009];
vector <ll> graph[300009], start;
ll vis[300009];
ll mx = -1, nw, cnt[300009][30];

void dfs1(ll u)

{
    if(vis[u] == 1) {
        printf("-1\n");
        exit(0);
    }
    
    if(vis[u] == 2)
    	return;

    vis[u] = 1;
    for(ll i = 0; i < graph[u].size(); i++) {
        ll nd = graph[u][i];
        dfs1(nd);
    }
    vis[u] = 2;
}

void dfs(ll u)

{
    //memcpy(counter, cnt, sizeof(cnt));

	if(vis[u])
		return;
       cnt[u][ val[u] ]++;

    vis[u] = 1;
    for(ll i = 0; i < graph[u].size(); i++) {
        ll nd = graph[u][i];
        //cout << counter[ val[nd] ] << endl;
        dfs(nd);
        
        for(ll j = 0; j < 26; j++) 
        	cnt[u][j] = max(cnt[u][j], cnt[nd][j] + (ll)(j == val[u]));
        
    }
}

int main()

{
    ll n, e;
    cin >> n >> e;
    scanf("%s", str);
    ll len = strlen(str);
    for(ll i = 0; i < len; i++) {
        val[i + 1] = (str[i] - 'a');
    }

    for(ll i = 1; i <= e; i++) {
        ll u, v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
    }

    for(ll i = 1; i <= n; i++) {
        if(vis[i] == 0) {
            nw = 1;
            dfs1(i);
            if(nw != -1)
                start.push_back(i);
        }
    }

    memset(vis, 0, sizeof(vis));
    for(ll i = 0; i < start.size(); i++) {
        dfs(start[i]);
    }
    
   	for(ll i = 1; i <= n; i++)
   		for(ll j = 0; j < 26; j++)
   			mx = max(mx, cnt[i][j]);

    cout << mx << endl;

    return 0;
}