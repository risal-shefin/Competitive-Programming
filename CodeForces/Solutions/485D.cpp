#include <bits/stdc++.h>
using namespace std;

int ara[200009], mark[1000009];

int main()

{
    int m, n = 0;
    cin >> m;
    for(int i = 0; i < m; i++) {
        int in;
        scanf("%d", &in);
        if(!mark[in]) {
            ara[n++] = in;
            mark[in] = 1;
        }
    }

    int mx = 0, pos = 0;
    sort(ara, ara + n);
    for(int i = 0; i < n; i++) {
        pos = i;
        for(int j = ara[i] * 2; pos < n; j += ara[i]) {
            pos = lower_bound(ara + pos, ara + n, j) - ara;

            mx = max(mx, ara[pos - 1] % ara[i]);
        }
    }

    printf("%d\n", mx);

    return 0;
}