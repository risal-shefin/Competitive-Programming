#include <bits/stdc++.h>
using namespace std;
char mapset[4] = {'0', '1', '2', '3'};
char grid[60][60];
int n, m, startrow, startcol;
string s;
bool dfs(int row, int col, int indx, int len)
{
    if(row < 0 || col < 0 || row >= n || col >= m) return 0;
    if(grid[row][col] == '#') return 0;
    if(grid[row][col] == 'E') return 1;
    if(indx == len) return 0;
    if(s[indx] == mapset[0]) return dfs(row - 1, col, indx + 1, len);
    if(s[indx] == mapset[1]) return dfs(row, col - 1, indx + 1, len);
    if(s[indx] == mapset[2]) return dfs(row, col + 1, indx + 1, len);
    if(s[indx] == mapset[3]) return dfs(row + 1, col, indx + 1, len);
}
int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf(" %c", &grid[i][j]);
            if(grid[i][j] == 'S') {
                startrow = i;
                startcol = j;
            }
        }
    }
    cin >> s;
    int cnt = 0;
    do {
        if(dfs(startrow, startcol, 0, s.length() ))
            cnt++;
    } while(next_permutation(mapset, mapset + 4));
    printf("%d\n", cnt);
    return 0;
}
