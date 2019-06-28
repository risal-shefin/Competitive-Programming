#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector <ll> prime;
bool isPrime(ll n)
{
    ll sqt = sqrt(n);
    for(ll i = 2; i <= sqt; i++)
        if(n % i == 0)
            return 0;
      return 1;
}
bool vis[1009];
struct node {
    ll num, lev;
    node(ll n, ll l) {
        num = n;
        lev = l;
    }
};
int main()
{
    for(ll i = 2; i <= 1000; i++)
        if(isPrime(i))
            prime.push_back(i);
      ll t, cs = 0;
    cin >> t;
    while(t--) {
        memset(vis, 0, sizeof(vis));
        ll s, tt, indx = 0;
        scanf("%lld %lld", &s, &tt);
          bool chk = 0;
        printf("Case %lld: ", ++cs);
        if(s > tt) {
            printf("-1\n");
            chk = 1;
        }
                queue <node> q;
        q.push( node(s, 0) );
        vis[s] = 1;
        while(!q.empty()) {
            node u = q.front();
            q.pop();
              if(u.num == tt) {
                printf("%lld\n", u.lev);
                chk = 1;
                break;
            }
              for(ll i = 0; i < prime.size(); i++) {
                  if(u.num % prime[i] != 0 || u.num == prime[i])
                    continue;
                  ll num = u.num + prime[i];
                  if(num > tt)
                    continue;
                if(vis[num])
                    continue;
                  vis[num] = 1;
                q.push( node(num, u.lev + 1) );
            }
        }
            if(!chk)
            printf("-1\n");
    }
      return 0;
}
