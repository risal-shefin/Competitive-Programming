#include <bits/stdc++.h>
using namespace std;
struct node {
    int x;
    int y;
} snow[109];
bool visit[109];
int n;
void dfs(int indx)
{
    if(visit[indx] == 1) return;
    visit[indx] = 1;
    for(int i = 0; i < n; i++) {
        if( (snow[i].x == snow[indx].x) || (snow[i].y == snow[indx].y) )
            dfs(i);
    }
}
int main()
{
    cin >> n;
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &snow[i].x, &snow[i].y);
    }
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(visit[i] == 1)
            continue;
        cnt++;
        dfs(i);
    }
    cnt--;
    cout << cnt << endl;
    return 0;
}
