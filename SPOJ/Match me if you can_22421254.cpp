#include <bits/stdc++.h>
using namespace std;
#define ll int
ll n, q;
char s[500009];
ll trie[5000009][30], cnt[5000009], id = 0;
void build()
 {
    ll cur = 0;
    for(ll i = 0; i < n; i++) {
        cur = 0;
        for(ll j = i; j < n; j++) {
             if(trie[cur][s[j] - 'a'] == -1)
                trie[cur][s[j] - 'a'] = ++id;
             cur = trie[ cur ][ s[j] - 'a'];
            cnt[ cur ]++;
        }
    }
}
void query()
 {
    ll cur = 0;
    ll ans, len;
    while(q--) {
        scanf("%s", s);
        cur = 0;
        bool flag = 1;
        for(ll i = 0; s[i] != '\0'; i++) {
            if(trie[ cur][ s[i] - 'a'] != -1)
                cur = trie[cur][ s[i] - 'a'];
            else {
                flag = 0;
                break;
            }
        }
         if(flag)
            printf("%d\n", cnt[ cur ]);
        else
            printf("0\n");
    }
}
int main()
 {
    memset(trie, -1, sizeof(trie));
    cin >> n >> q;
    scanf("%s", s);
    build();
    query();
     return 0;
