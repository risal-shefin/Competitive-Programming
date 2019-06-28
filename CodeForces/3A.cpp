#include <bits/stdc++.h>
using namespace std;
struct node {
    int row;
    int col;
    int mr, mc;
    node(int r, int c, int m1, int m2) {
        row = r;
        col = c;
        mr = m1;
        mc = m2;
    }
};
struct nd {
    int row;
    int col;
    nd(int r, int c) {
        row = r;
        col = c;
    }
};
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int r1, c1, r2, c2;
    r1 = s1[1] - 48;
    c1 = s1[0] - 'a' + 1;
    r2 = s2[1] - 48;
    c2 = s2[0] - 'a' + 1;
    if(r1 == r2 && c1 == c2) {
        printf("0\n");
        return 0;
    }
    int rowset[8] = {0, 0, 1, 1, 1, -1, -1, -1};
    int colset[8] = {-1, 1, -1, 0, 1, -1, 0, 1};
    queue <nd> q;
    q.push(nd(r1, c1));
    vector <node> v;
    bool visit[10][10] = {};
    while(!q.empty()) {
        nd u = q.front();
        q.pop();
        for(int i = 0; i < 8; i++) {
            int tr = u.row + rowset[i];
            int tc = u.col + colset[i];
            if(tr > 0 && tr <= 8 && tc > 0 && tc <= 8 && visit[tr][tc] == 0) {
                visit[tr][tc] = 1;
                q.push(nd(tr, tc));
                v.push_back(node(tr, tc, u.row, u.col));
                if(tr == r2 && tc == c2) {
                    while(!q.empty()) {
                        q.pop();
                    }
                    //cout << tr << "  " << tc << endl;
                    goto over;
                }
            }
        }
    }
    over:
        {
            vector <nd> vct;
            int sz = v.size();
            vct.push_back(nd(r2, c2));
            for(int i = sz - 1; i >= 0; i--) {
                if(v[i].row == r2 && v[i].col == c2) {
                    vct.push_back(nd(v[i].mr, v[i].mc));
                    r2 = v[i].mr;
                    c2 = v[i].mc;
                }
            }
            v.clear();
            sz = vct.size();
            printf("%d\n", sz - 1);
            for(int i = sz - 1; i >= 0; i--) {
                if(vct[i].row > r1) {
                    if(vct[i].col > c1) {
                        printf("RU\n");
                    }
                    else if(vct[i].col == c1) {
                        printf("U\n");
                    }
                    else if(vct[i].col < c1) {
                        printf("LU\n");
                        //cout << vct[i].row << "  " << vct[i].col << endl;
                    }
                }
                if(vct[i].row < r1) {
                    if(vct[i].col > c1) {
                        printf("RD\n");
                    }
                    else if(vct[i].col == c1) {
                        printf("D\n");
                    }
                    else if(vct[i].col < c1) {
                        printf("LD\n");
                        //cout << vct[i].row << "  " << vct[i].col << endl;
                    }
                }
                if(vct[i].row == r1) {
                    if(vct[i].col > c1) {
                        printf("R\n");
                    }
                    else if(vct[i].col < c1) {
                        printf("L\n");
                    }
                }
                r1 = vct[i].row;
                c1 = vct[i].col;
            }
            vct.clear();
        }
    return 0;
}
