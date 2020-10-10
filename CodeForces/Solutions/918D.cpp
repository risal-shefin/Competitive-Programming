#include <bits/stdc++.h>
using namespace std;

vector <int> graph[109], cost[109];
int dp[109][109][30][2];

int solve(int i, int j, int cst, int round)

{
    int &ret = dp[i][j][cst][round];
    if(ret != -1)
        return ret;

    ret = 0;
    if(round == 0) {
        for(int k = 0; k < graph[i].size(); k++) {
            if(cost[i][k] >= cst) {
                if(!solve(graph[i][k], j, cost[i][k], round^1) )
                    ret = 1;
            }
        }
    }
    else {
        for(int k = 0; k < graph[j].size(); k++) {
            if(cost[j][k] >= cst) {
                if(!solve(i, graph[j][k], cost[j][k], round^1) )
                    ret = 1;
            }
        }
    }

    return ret;
}

int main()

{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v;
        char ch;
        scanf("%d %d %c", &u, &v, &ch);
        graph[u].push_back(v);
        cost[u].push_back(ch - 'a');
    }

    memset(dp, -1, sizeof(dp));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if( solve(i, j, 0, 0) )
                printf("A");
            else
                printf("B");
        }
        printf("\n");
    }

    return 0;
}