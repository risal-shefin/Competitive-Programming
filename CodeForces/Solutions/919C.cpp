#include <bits/stdc++.h>
using namespace std;

#define ll long long
char graph[2009][2009];
bool visit[2009][2009];
int rowset[] = {0, 1};
int colset[] = {1, 0};
int n, m, p;
ll ans = 0;


void dfs(int r, int c, int state, int cnt)

{
    if(r < 0 || c < 0 || r >= n || c >= m)
        return;
    if(graph[r][c] == '*')
        return;

    int tmpr = r + rowset[state];
    int tmpc = c + colset[state];

    cnt++;
    if(cnt == p) {
        ans++;
        return;
    }
    dfs(tmpr, tmpc, state, cnt);

    return;
}

int main()

{
    cin >> n >> m >> p;

    for(int i = 0; i < n; i++) {
        scanf("%s", graph[i]);
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {

            /*dfs(i, j, 0, 0);
            dfs(i, j, 1, 0);*/
            if(graph[i][j] == '.') {
                int cnt = 0, k;
                for(k = j; k < m; k++) {
                    if(graph[i][k] == '*')
                        break;
                    cnt++;
                    if(cnt == p) {
                        ans++;
                        break;
                    }
                }

                cnt = 0;
                for(k = i; k < n; k++) {
                    if(graph[k][j] == '*')
                        break;
                    cnt++;
                    if(cnt == p) {
                        ans++;
                        break;
                    }
                }

            }
        }
    }

    cout << ans << endl;
    return 0;
}