#include <bits/stdc++.h>
using namespace std;

struct node {
    int col;
    int row;
    int dist;

    node(int c, int r, int d) {
        col = c;
        row = r;
        dist = d;
    }
};

int main()

{
    int n;
    scanf("%d", &n);
    char s1[3], s2[3];
    int rowset[] = {2, 2, -2, -2, 1, 1, -1, -1};
    int colset[] = {1, -1, 1, -1, 2, -2, 2, -2};
    while(n--) {
        scanf("%s %s", s1, s2);
        int row1 = s1[1] - '0', col1 = s1[0] - 'a' + 1;
        int row2 = s2[1] - '0', col2 = s2[0] - 'a' + 1;
        if(row1 == row2 && col1 == col2) {
            printf("0\n");
            continue;
        }

        bool visit[9][9] = {};
        queue <node> q;
        node temp(col1, row1, 0);
        q.push(temp);

        while(!q.empty()) {
            node u = q.front();
            q.pop();

            for(int i = 0; i < 8; i++) {
                int rowtemp = u.row + rowset[i];
                int coltemp = u.col + colset[i];

                if(rowtemp >= 1 && rowtemp <= 8) {
                    if(coltemp >= 1 && coltemp <= 8) {
                        if(visit[rowtemp][coltemp] == 0) {
                            if(rowtemp == row2 && coltemp == col2) {
                                printf("%d\n", u.dist + 1);
                                goto over;
                            }

                            else {
                                q.push(node(coltemp, rowtemp, u.dist + 1));
                            }
                        }
                    }
                }

            }

        }


        over:;

    }

    return 0;
}
