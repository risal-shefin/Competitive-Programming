#include <bits/stdc++.h>
using namespace std;

struct node {
    int row, col;
    node(int r, int c) {
        row = r;
        col = c;
    }
};

bool visit[509][509];

int main()

{
    int n, m, k, srow = -1, scol = -1, cnt = 0;
    scanf("%d %d %d", &n, &m, &k);
    char ara[n + 5][m + 5];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            scanf(" %c", &ara[i][j]);

            if(ara[i][j] == '.') {
                cnt++;

                if(srow == -1) {
                    srow = i;
                    scol = j;
                }
            }

        }

    cnt = cnt - k;
    int cnt2 = 1;

    queue <node> q;
    q.push(node(srow, scol));
    visit[srow][scol] = 1;
    int rowset[] = {0, 0, -1, 1};
    int colset[] = {1, -1, 0, 0};

    while(!q.empty()) {
        node u = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int tmpr = u.row + rowset[i];
            int tmpcl = u.col + colset[i];

            if(tmpr >= 0 && tmpcl >= 0 && tmpr < n && tmpcl < m) {
                if(visit[tmpr][tmpcl] == 0 && ara[tmpr][tmpcl] == '.') {

                    visit[tmpr][tmpcl] = 1;
                    q.push( node(tmpr, tmpcl));
                    cnt2++;
                    if(cnt2 > cnt)
                        ara[tmpr][tmpcl] = 'X';
                }
            }

        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("%c", ara[i][j]);
        }

        printf("\n");
    }

    return 0;
}