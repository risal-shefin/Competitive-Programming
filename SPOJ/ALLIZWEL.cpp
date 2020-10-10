#include <bits/stdc++.h>
using namespace std;

int r, c;
char graph[105][105];
string sample = "ALLIZZWELL";
bool checker = 0, visit[109][109];
char test[20];

void dfs(int row, int col, int indx)

{
    if(indx > 9) return;
    if(row < 0 || col < 0 || row >= r || col >= c) {
        return;
    }
    if(visit[row][col]) {
        //cout << 5 << endl;
        return;
    }

    test[indx] = graph[row][col];
    if(test[indx] != sample[indx]) {
        return;
    }

    visit[row][col] = 1;
    //cout << test[indx] << endl
    if(indx == 9 && test[9] == sample[9]) {
        checker = 1;
    }
    if(checker)
        return;

    dfs(row - 1, col - 1, indx + 1);  dfs(row - 1, col, indx + 1);  dfs(row - 1, col + 1, indx + 1);
    dfs(row, col -1, indx + 1);  dfs(row, col + 1, indx + 1);
    dfs(row + 1, col - 1, indx + 1);  dfs(row + 1, col, indx + 1);   dfs(row + 1, col + 1, indx + 1);
    visit[row][col] = 0;
}

int main()

{
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &r, &c);

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                scanf(" %c", &graph[i][j]);
            }
        }

        checker = 0;
        memset(visit, 0, sizeof(visit));

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(graph[i][j] == 'A') {
                    test[0] = graph[i][j];
                    dfs(i, j, 0);

                    for(int k = 0; k < r; k++) {
                        for(int l = 0; l < c; l++) {
                            visit[k][l] = 0;
                        }
                    }

                }
                if(checker)
                    break;
            }

            if(checker)
                break;
        }

        if(checker == 1) {
            printf("YES\n");
        }
        else
            printf("NO\n");

        /*if(t != 0)
            printf("\n");*/
    }

    return 0;
}
