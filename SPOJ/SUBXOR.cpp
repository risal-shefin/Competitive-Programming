#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll trie[2000099][2], nodes = 1, cnt[4000198];

void add(ll num)

{
    ll cur = 0;
    for(ll i = 20; i >= 0; i--) {
        ll nxt = (num >> i) & 1;
        if(trie[cur][nxt] == 0) {
            trie[cur][nxt] = nodes;
            nodes++;
        }
        cur = trie[cur][nxt];
        cnt[cur]++;
    }
}

ll query(ll num, ll k)

{
    ll cur = 0, ans = 0;
    for(ll i = 20; i >= 0; i--) {
        ll nxt = (num >> i) & 1;
        ll nxt2 = (k >> i) & 1;
        if(nxt2 == 1) {
            ans += cnt[ trie[cur][nxt] ];
            cur = trie[cur][nxt ^ 1];
        }
        else {
            cur = trie[cur][nxt];
        }

        if(cur == 0)
            break;
    }

    //ans += cnt[cur];
    return ans;
}

int main()

{
    ll t, k, n;
    scanf("%lld", &t);
    while(t--) {
        memset(trie, 0, sizeof(trie));
        memset(cnt, 0, sizeof(cnt));
        scanf("%lld %lld", &n, &k);
        ll cur = 0, ans = 0;
        add(0);
        for(ll i = 1; i <= n; i++) {
            ll in;
            scanf("%lld", &in);
            cur ^= in;
            ans += query(cur, k);
            add(cur);
        }

        printf("%lld\n", ans);
    }

    return 0;
