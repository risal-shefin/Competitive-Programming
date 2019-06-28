#include <bits/stdc++.h>
using namespace std;
#define ll long long
char graph[2009][2009];
bool visit[2009][2009];
bool visit2[2009][2009];
int n, m, p;
ll ans = 0;
int main()
{
    cin >> n >> m >> p;
    for(int i = 0; i < n; i++) {
        scanf("%s", graph[i]);
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(graph[i][j] == '.') {
                int cnt = 0, k;
                if(visit[i][j] == 0) {
                    for(k = j; k < m; k++) {
                        if(graph[i][k] == '*')
                            break;
                        visit[i][k] = 1;
                        cnt++;
                        if(cnt == p) {
                            ans++;
                            cnt--;
                        }
                    }
                }
                if(visit2[i][j] == 0) {
                    cnt = 0;
                    for(k = i; k < n; k++) {
                        if(graph[k][j] == '*')
                            break;
                        visit2[k][j] = 1;
                        cnt++;
                        if(cnt == p) {
                            ans++;
                            cnt--;
                        }
                    }
                }
            }
        }
    }
    if(p == 1)
        ans = ans / 2;
    cout << ans << endl;
    return 0;
}
