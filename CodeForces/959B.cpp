#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1e18
unordered_map <string, ll> mark;
string word[100009];
char in[30];
ll cost[100009], indx[100009];
int main()
{
    ll n, k, m;
    cin >> n >> k >> m;
    for(ll i = 1; i <= n; i++) {
        scanf(" %s", in);
        ll len = strlen(in);
        string s(in, in + len);
        word[i] = s;
    }
    for(ll i = 1; i <= n; i++)
        scanf("%lld", &cost[i]);
    for(ll i = 1; i <= k; i++) {
        ll num, tmp = inf;
        scanf("%lld", &num);
        for(ll j = 1; j <= num; j++) {
            scanf("%lld", &indx[j]);
            tmp = min(tmp, cost[ indx[j] ]);
        }
        for(ll j = 1; j <= num; j++) {
            mark[ word[ indx[j] ] ] = tmp;
        }
    }
    ll ans = 0;
    for(ll i = 1; i <= m; i++) {
        scanf(" %s", in);
        ll len = strlen(in);
        string s(in, in + len);
        ans += mark[s];
    }
    cout << ans << endl;
    return 0;
}
