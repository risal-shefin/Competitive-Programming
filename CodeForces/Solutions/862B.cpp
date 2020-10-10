#include <bits/stdc++.h>
using namespace std;

#define ll long long
int color[100009];
vector <int> graph[100009];
ll cnt[3];

int main()

{
    int n, u, v;
    cin >> n;
    for(int i = 1; i < n; i++) {
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    queue <int> q;
    q.push(u);

    while(!q.empty()) {
        int nd = q.front();
        q.pop();

        for(int i = 0; i < graph[nd].size(); i++){
            if(color[ graph[nd][i] ] == 0) {

                if(color[nd] == 2) {
                    color[ graph[nd][i] ] = 1;
                    q.push(graph[nd][i]);
                    cnt[1]++;
                }

                else {
                    color[ graph[nd][i] ] = 2;
                    q.push( graph[nd][i]);
                    cnt[2]++;
                }
            }
        }
    }

    printf("%I64d\n", cnt[1]*cnt[2] - (n - 1));

    return 0;
}