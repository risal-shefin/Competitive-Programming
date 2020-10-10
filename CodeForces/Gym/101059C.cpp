#include <bits/stdc++.h>
using namespace std;

struct gang {
    int vrtc;
    int level;
    gang(int v, int l) {
        vrtc = v;
        level = l;
    }
};

struct point {
    int vrtc;
    int gm;
    point(int v, int g) {
        vrtc = v;
        gm = g;
    }
};

bool visit[100009];
long long int payable[100009];
int mem[100009];

int main()

{
    int n, m, p, k;
    scanf("%d %d %d %d", &n, &m, &p, &k);
    vector <int> node[100009];
    int loc[p + 5];
    long long int pay[p + 5];

    for(int i = 0; i < p; i++) {
        scanf("%d", &loc[i]);
    }

    memset(payable, 0, sizeof(payable));
    memset(mem, 0, sizeof(mem));
    for(int i = 0; i < p; i++) {
        scanf("%I64d", &pay[i]);
        payable[ loc[i] ] = pay[i];
    }

    for(int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        node[u].push_back(v);
        node[v].push_back(u);
    }

    int start, stop;
    scanf("%d %d", &start, &stop);
    int gangflag = 0;

    for(int i = 0; i < p; i++) {
        int tmpstart = loc[i];

        queue <gang> q;
        q.push( gang(loc[i], 0) );
        memset(visit, 0, sizeof(visit));
        visit[ loc[i] ] = 1;
        mem[ loc[i] ] = mem[ loc[i] ] | (1 << i);
        while(!q.empty()) {
            gang nd = q.front();
            q.pop();
            int vert = nd.vrtc;

            for(int j = 0; j < node[vert].size(); j++) {
                if(visit[ node[vert][j] ] == 0 && nd.level < k) {
                    visit[ node[vert][j] ] = 1;

                    payable[ node[vert][j] ] += pay[i];
                    mem[ node[vert][j] ] |= (1 << i);
                    gangflag = gangflag | (1 << i);
                    q.push( gang(node[vert][j], nd.level + 1) );
                }
            }

        }

    }

    queue <point> q;
    queue <long long int> cost;
    q.push( point(start, gangflag ^ mem[start]) );
    cost.push( payable[start] );
    memset(visit, 0, sizeof(visit));
    visit[ start ] = 1;
    long long mn = LONG_MAX;

    if(start == stop) {
        printf("%I64d\n", payable[start] );
        return 0;
    }

    while(!q.empty()) {
        point uu = q.front();
        int nd = uu.vrtc;
        int gangm = uu.gm;
        long long int paid = cost.front();
        q.pop();
        cost.pop();

        for(int j = 0; j < node[nd].size(); j++) {
            if(visit[ node[nd][j] ] == 0) {
                visit[ node[nd][j] ] = 1;
                int tmp = gangm;

                long long int pd = paid;
                for(int k = 0; k < 10; k++) {

                    if(mem[ node[nd][j] ] & (1 << k) ) {
                        if(gangm & (1 << k)) {
                            pd += pay[k];
                            tmp = tmp ^ (1 << k);
                        }
                    }

                }

                if(node[nd][j] == stop) {
                    mn = min(mn, pd);
                    continue;
                }

                cost.push(pd);
                q.push( point(node[nd][j], tmp) );
                //cout << "  " << tmp << "   " << node[nd][j] <<  endl;
                //payable[ node[nd][j] ] = 0;
            }
        }
    }

    printf("%I64d\n", mn);

    return 0;
}