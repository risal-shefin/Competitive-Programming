#include <bits/stdc++.h>
using namespace std;
#define sz 50005 * 33
int trie[sz][2], nodes = 1;
void add(int num)
{
    int cur = 0;
    for(int i = 30; i >= 0; i--) {
        int next = (num >> i) & 1;
        if(trie[cur][next] == -1) {
            trie[cur][next] = nodes;
            nodes++;
        }
        cur = trie[cur][next];
    }
}
int querymx(int num)
{
    int cur = 0, ans = 0;
    for(int i = 30; i >= 0; i--) {
        int next = ( (num >> i) & 1 ) ^ 1;
        if(trie[cur][next] != -1) {
            ans <<= 1;
            ans++;
            cur = trie[cur][next];
        }
        else {
            ans <<= 1;
            cur = trie[cur][next ^ 1];
        }
    }
    return ans;
}
int querymn(int num)
{
    int cur = 0, ans = 0;
    for(int i = 30; i >= 0; i--) {
        int next = (num >> i) & 1;
        if(trie[cur][next] != -1) {
            ans <<= 1;
            cur = trie[cur][next];
        }
        else {
            ans <<= 1;
            ans++;
            cur = trie[cur][next ^ 1];
        }
    }
      return ans;
}
int main()
{
    int t, caseno = 0;
    scanf("%d", &t);
    while(t--) {
        memset(trie, -1, sizeof(trie));
        nodes = 1;
        add(0);
        int n;
        scanf("%d", &n);
        int num = 0, ansmn = INT_MAX, ansmx = INT_MIN;
        for(int i = 1; i <= n; i++) {
            int in;
            scanf("%d", &in);
            num = num ^ in;
            ansmn = min(ansmn, querymn(num));
            ansmx = max(ansmx, querymx(num));
            add(num);
        }
          printf("Case %d: %d %d\n", ++caseno, ansmx, ansmn);
    }
      return 0;
}
