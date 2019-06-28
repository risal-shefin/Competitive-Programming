#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
    ll nxt[5];
    ll cnt;
} ara[1000009];
string s;
ll last, cur, val, mx, ans;
void newnode(ll cur)
{
    for(ll i = 0; i < 5; i++)
        ara[cur].nxt[i] = -1;
    ara[cur].cnt = 1;
}
void insrt()
{
    cur = 0;
    for(ll i = 0; i < s.length(); i++) {
        if(s[i] == 'A')
            val = 1;
        else if(s[i] == 'C')
            val = 2;
        else if(s[i] == 'G')
            val = 3;
        else
            val = 4;
          if(ara[cur].nxt[val] == -1) {
            ara[cur].nxt[val] = last;
            cur = ara[cur].nxt[val];
            newnode(last++);
        }
        else {
            cur = ara[cur].nxt[val];
            ara[cur].cnt++;
            mx = (i + 1) * ara[cur].cnt;
            ans = max(ans, mx);
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    ll t, caseno = 0;
    cin >> t;
    while(t--) {
        last = 1, ans = 0;
        newnode(0);
        ll n;
        cin >> n;
        for(ll i = 0; i < n; i++) {
            cin >> s;
            insrt();
            ans = max(ans, (ll)s.length());
        }
          printf("Case %lld: %lld\n", ++caseno, ans);
    }
      return 0;
}
