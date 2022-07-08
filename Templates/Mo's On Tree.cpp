//find distinct "weights in nodes" of the path (from node u to node v)

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 40005;
const int MAXM = 100005;
const int LN = 19;

int N, M, K, cur, A[MAXN], LVL[MAXN], pa[LN][MAXN];
int BL[MAXN << 1], ID[MAXN << 1], FREQ[MAXN], ANS[MAXM];
int d[MAXN], in[MAXN], out[MAXN];
bool VIS[MAXN];
vector < int > graph[MAXN];

struct query
{
    int id, l, r, lc;
    bool operator < (const query& rhs)
    {
        if(BL[l] != BL[rhs.l])
            return BL[l] < BL[rhs.l];

        if(BL[l] & 1)
            return r < rhs.r;

        return r > rhs.r;
    }
} Q[MAXM];

// Set up Stuff
void dfs(int u, int par, int d)
{
    in[u] = ++cur, ID[cur] = u;
    pa[0][u] = par, LVL[u] = d;
    for (auto &v : graph[u])
    {
        if (v == par)
            continue;
        dfs(v, u, d+1);
    }
    out[u] = ++cur, ID[cur] = u;
}

// Function returns lca of u and v
int LCA(int u, int v)
{
    if(LVL[u] < LVL[v]) swap(u,v);
    int diff = LVL[u] - LVL[v];
    for(int i = 0; i < LN; i++) if( (diff>>i)&1 ) u = pa[i][u];
    if(u == v) return u;
    for(int i = LN-1; i >= 0; i--) {
        if(pa[i][u] != pa[i][v]) {
            u = pa[i][u];
            v = pa[i][v];
        }
    }
    return pa[0][u];
}

inline void check(int x, int& res)
{
    // If (x) occurs twice, then don't consider it's value
    if(VIS[x]) {
        if(--FREQ[A[x]] == 0)
            res--;
    }
    else if(!VIS[x]) {
        if(FREQ[A[x]]++ == 0)
            res++;
    }
    VIS[x] ^= 1;
}

void compute()
{

    // Perform standard Mo's Algorithm
    int curL = Q[0].l, curR = Q[0].l - 1, res = 0;

    for (int i = 0; i < M; i++)
    {

        while (curL < Q[i].l)
            check(ID[curL++], res);
        while (curL > Q[i].l)
            check(ID[--curL], res);
        while (curR < Q[i].r)
            check(ID[++curR], res);
        while (curR > Q[i].r)
            check(ID[curR--], res);

        int u = ID[curL], v = ID[curR];

        // Case 2
        if (Q[i].lc != u and Q[i].lc != v)
            check(Q[i].lc, res);

        ANS[Q[i].id] = res;

        if (Q[i].lc != u and Q[i].lc != v)
            check(Q[i].lc, res);
    }

    for (int i = 0; i < M; i++)
        printf("%d\n", ANS[i]);
}

void init(int N) {
    cur = 0;
    for (int i = 1; i <= N; i++) {
        graph[i].clear();
        VIS[i] = FREQ[i] = 0;
        for(int j=0; j<LN; j++) pa[j][i] = -1;
    }
}

int main()
{

    int u, v, x;

    scanf("%d %d", &N, &M);
    init(N);

    // Inputting Values
    for (int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
        d[i] = A[i];
    }

    // Compressing Coordinates
    sort(d + 1, d + N + 1);
    K = unique(d + 1, d + N + 1) - d - 1;
    for (int i = 1; i <= N; i++)
        A[i] = upper_bound(d + 1, d + K + 1, A[i]) - d;

    // Inputting Tree
    for (int i = 1; i < N; i++)
    {
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1, -1, 0);
    // Build Sparse Table
    for(int i=1; i<LN; i++)
        for(int j=1; j<=N; j++)
            if(pa[i-1][j] != -1)
                pa[i][j] = pa[i-1][pa[i-1][j]];

    int size = sqrt(cur);

    for (int i = 1; i <= cur; i++)
        BL[i] = (i - 1) / size + 1;

    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &u, &v);
        Q[i].lc = LCA(u, v);
        if (in[u] > in[v])
            swap(u, v);
        if (Q[i].lc == u)
            Q[i].l = in[u], Q[i].r = in[v];
        else
            Q[i].l = out[u], Q[i].r = in[v];
        Q[i].id = i;
    }

    sort(Q, Q + M);
    compute();
}
