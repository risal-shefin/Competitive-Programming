#include <bits/stdc++.h>
using namespace std;

int trie[32000000][2], nodes = 2;
long long cnt[32000000];

void add(int num)

{
    int cur = 1;
    for(int i = 30; i >= 0; i--) {
        int next = (num >> i) & 1;
        if(trie[cur][next] == 0) {
            trie[cur][next] = nodes;
            nodes++;
        }
        cnt[cur]++;
        cur = trie[cur][next];
    }
    cnt[cur]++;
}

int query(int num, int k)

{
    int cur = 1, ans = 0;
    for(int i = 30; i >= 0; i--) {
        int next = (num >> i) & 1;
        int next2 = (k >> i) & 1;
        if(next2 == 0) {
            ans += cnt[ trie[cur][next ^ 1] ];
            cur = trie[cur][next];
        }
        else {
            cur = trie[cur][next ^ 1];
        }

        if(cur == 0)
            break;
    }

    ans += cnt[cur];
    return ans;
}

int main()

{
    memset(trie, 0, sizeof(trie));
    add(0);
    int n, k, cur = 0;
    scanf("%d %d", &n, &k);
    long long ans = 0;
    for(int i = 1; i <= n; i++) {
        int in;
        scanf("%d", &in);
        cur ^= in;
        ans += query(cur, k);
        add(cur);
    }

    printf("%lld\n", ans);

    return 0;
}